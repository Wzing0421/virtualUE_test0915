#-------------------------------------------------
#
# Project created by QtCreator 2019-07-16T16:49:08
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = virtualUE
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    audioplaythread.cpp \
    audiosendthread.cpp \
    codec.cpp

HEADERS  += mainwindow.h \
    audioplaythread.h \
    audiosendthread.h \
    config.h \
    codec.h \
    codec2.h

FORMS    += mainwindow.ui

unix:!macx: LIBS += -L$$PWD/./ -lcodec2

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

unix:!macx: PRE_TARGETDEPS += $$PWD/./libcodec2.a

unix:!macx: LIBS += -L$$PWD/./ -lcodec2

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
