#include "audiosendthread.h"

/*
 * audiosendthread 可以把获取到的960字节(3 * 20ms共3帧合在一起)压缩为18字节，并加上12字节sc2的头，共30字节数据发送至媒体网关
 */

audiosendthread::audiosendthread(QObject *parent)
    : QThread(parent)
{
    //首先用Socket2_4将128k语音包送到媒体网关的一个端口进行压缩，Socket2_4只负责发送，udpSocket负责接收并发送
    udpSocket = new QUdpSocket(this);
    destaddr.setAddress(mediaGW_addr2);
    //destport = 20000;

    //用于2.4k压缩的目的地址和端口
    Socket2_4 = new QUdpSocket(this);
    tmpaddr.setAddress(mediaGW_addr1);
    //tmpport = 30000;

    SN = 0;//序列号初始化成0

    /*初始化sc2_2接口的头*/
    init_sc2_2();

    /*
     * 初始化编码器
    */
    codec2EnCoder = new Codec2EnCoder();
    codec2EnCoder->Init();
}
audiosendthread::~audiosendthread(){
    delete udpSocket;
    delete Socket2_4;
    delete input;
    delete inputDevice;
    delete codec2EnCoder;
}

void audiosendthread::setaudioformat(int samplerate, int channelcount, int samplesize){
    format.setSampleRate(samplerate);
    format.setChannelCount(channelcount);
    format.setSampleSize(samplesize);
    format.setCodec("audio/pcm");
    format.setSampleType(QAudioFormat::SignedInt);
    format.setByteOrder(QAudioFormat::LittleEndian);

    input = new QAudioInput(format, this);

}

void audiosendthread::mystart(){
    if(!udpSocket -> bind(QHostAddress::Any, 10005)){
        qDebug()<<"socket bind error";
    }
    //connect(udpSocket,SIGNAL(readyRead()),this,SLOT(readyReadSlot()));

    SN = 0;
    m_CurrentPlayIndex = 0;
    m_PCMDataBuffer.clear();

    qDebug()<<"audio sender starts!";
    inputDevice = input->start();
    connect(inputDevice,SIGNAL(readyRead()),this,SLOT(onReadyRead()));


}

void audiosendthread::mystop(){
    qDebug()<<"audio sender stops!";

    QMutexLocker locker(&m_Mutex);
    SN = 0;
    m_CurrentPlayIndex = 0;
    m_PCMDataBuffer.clear();

    input->stop();
    udpSocket->close();

}

/**
 * @brief audiosendthread::onReadyRead
 * 利用codec2编码并发送
 * 每次读入的消息并不一定是960长度，所以需要增加一个缓冲区，每次收集到960了再发送
 */
void audiosendthread::onReadyRead(){
    int len = inputDevice -> read(au_data,FRAME_LEN_60ms);

    m_CurrentPlayIndex += len;
    m_PCMDataBuffer.append(au_data, len);

    if( m_CurrentPlayIndex >= FRAME_LEN_60ms){
        char *writeData = new char[FRAME_LEN_60ms];
        char *outputData = new char[FRANE_COMPRESS_60ms];
        memcpy(writeData,&m_PCMDataBuffer.data()[0], FRAME_LEN_60ms);
        /*
         *现在不直接发送了，而是直接编码
         */
        //Socket2_4 -> writeDatagram(writeData, FRAME_LEN_60ms, tmpaddr, mediaGW_port1);

        //1. 编码
        codec2EnCoder->Codec((uint8_t*)writeData, FRAME_LEN_60ms,(uint8_t*)outputData , FRANE_COMPRESS_60ms);

        //2. 发送
        this->sendAudio(outputData);
        //3. 整理缓冲区
        m_PCMDataBuffer = m_PCMDataBuffer.right(m_PCMDataBuffer.size()-FRAME_LEN_60ms);
        m_CurrentPlayIndex -= FRAME_LEN_60ms;
        delete []writeData;
        delete []outputData;
    }

}

/* 已经废弃
void audiosendthread::readyReadSlot(){//收到压缩的2.4k的语音包
    while(udpSocket->hasPendingDatagrams()){
            QHostAddress senderip;
            quint16 senderport;

            char recvbuf[FRANE_COMPRESS_60ms];//2.4k语音包的长度是18字节
            udpSocket->readDatagram(recvbuf,sizeof(recvbuf),&senderip,&senderport);
            //加上头再发送出去
            char* sendbuf = new char[FRANE_COMPRESS_60ms + sizeof(sc2_2)];//12字节的头，18字节的裸2.4k语音共30字节
            memcpy(sendbuf,sc2_2,sizeof(sc2_2));

            unsigned int SN_net = htonl(SN);
            memcpy(sendbuf + 5,((unsigned char*)&SN_net)+1,3);

            memcpy(sendbuf + sizeof(sc2_2), recvbuf, FRANE_COMPRESS_60ms);
            udpSocket->writeDatagram(sendbuf,FRANE_COMPRESS_60ms +sizeof(sc2_2), destaddr,mediaGW_port2);

            QMutexLocker locker(&m_Mutex);
            SN++;

            delete []sendbuf;
    }
}
*/
void audiosendthread::init_sc2_2(){//初始化sc2_2的头
    /*初始化UEID,我只是不想让UEUD变得全是0*/
    sc2_2[0] = 0x00;
    sc2_2[1] = 0x00;
    sc2_2[2] = 0x00;
    sc2_2[3] = 0x01;
    //媒体方向
    sc2_2[4] = 0x00;//上行

    /*SN序号*/
    sc2_2[5] = 0x00;
    sc2_2[6] = 0x00;
    sc2_2[7] = 0x00;

    //length
    short len24k = 18;
    short len24k_net = htons(len24k);
    memcpy(sc2_2+8,&len24k_net,2);

    //Rev
    sc2_2[10] = 0x00;
    sc2_2[11] = 0x00;
}

/**
   send 18bytes compressed codec2 audio data to media gateway
 * @brief audiosendthread::sendAudio
 * @param outputData 18Bytes compressed codec2 audio data
 */
void audiosendthread::sendAudio(char *outputData){

    //先加上sc2头然后发送出去
    char* sendbuf = new char[FRANE_COMPRESS_60ms + sizeof(sc2_2)];//12字节的头，18字节的裸2.4k语音共30字节
    memcpy(sendbuf,sc2_2,sizeof(sc2_2));
    /*处理三个字节长度的SN*/

    unsigned int SN_net = htonl(SN);
    memcpy(sendbuf + 5,((unsigned char*)&SN_net)+1,3);

    memcpy(sendbuf + sizeof(sc2_2), outputData, FRANE_COMPRESS_60ms);
    udpSocket->writeDatagram(sendbuf, FRANE_COMPRESS_60ms +sizeof(sc2_2), destaddr, mediaGW_port2);

    //sn号增加1,注意加锁
    QMutexLocker locker(&m_Mutex);
    SN++;

    delete []sendbuf;

}
