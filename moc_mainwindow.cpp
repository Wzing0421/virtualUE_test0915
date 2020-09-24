/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[352];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 16), // "on_start_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "recvRegInfo"
QT_MOC_LITERAL(4, 41, 12), // "proc_timeout"
QT_MOC_LITERAL(5, 54, 17), // "proc_auth_timeout"
QT_MOC_LITERAL(6, 72, 18), // "proc_dereg_timeout"
QT_MOC_LITERAL(7, 91, 18), // "proc_periodtimeout"
QT_MOC_LITERAL(8, 110, 17), // "call_timeoutT9005"
QT_MOC_LITERAL(9, 128, 17), // "call_timeoutT9006"
QT_MOC_LITERAL(10, 146, 17), // "call_timeoutT9007"
QT_MOC_LITERAL(11, 164, 17), // "call_timeoutT9009"
QT_MOC_LITERAL(12, 182, 17), // "call_timeoutT9014"
QT_MOC_LITERAL(13, 200, 21), // "on_DeReigster_clicked"
QT_MOC_LITERAL(14, 222, 15), // "on_call_clicked"
QT_MOC_LITERAL(15, 238, 21), // "on_disconnect_clicked"
QT_MOC_LITERAL(16, 260, 18), // "on_connect_clicked"
QT_MOC_LITERAL(17, 279, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(18, 301, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(19, 325, 13), // "sendSipInvite"
QT_MOC_LITERAL(20, 339, 12) // "sendRegister"

    },
    "MainWindow\0on_start_clicked\0\0recvRegInfo\0"
    "proc_timeout\0proc_auth_timeout\0"
    "proc_dereg_timeout\0proc_periodtimeout\0"
    "call_timeoutT9005\0call_timeoutT9006\0"
    "call_timeoutT9007\0call_timeoutT9009\0"
    "call_timeoutT9014\0on_DeReigster_clicked\0"
    "on_call_clicked\0on_disconnect_clicked\0"
    "on_connect_clicked\0on_pushButton_clicked\0"
    "on_pushButton_2_clicked\0sendSipInvite\0"
    "sendRegister"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x08 /* Private */,
       3,    0,  110,    2, 0x08 /* Private */,
       4,    0,  111,    2, 0x08 /* Private */,
       5,    0,  112,    2, 0x08 /* Private */,
       6,    0,  113,    2, 0x08 /* Private */,
       7,    0,  114,    2, 0x08 /* Private */,
       8,    0,  115,    2, 0x08 /* Private */,
       9,    0,  116,    2, 0x08 /* Private */,
      10,    0,  117,    2, 0x08 /* Private */,
      11,    0,  118,    2, 0x08 /* Private */,
      12,    0,  119,    2, 0x08 /* Private */,
      13,    0,  120,    2, 0x08 /* Private */,
      14,    0,  121,    2, 0x08 /* Private */,
      15,    0,  122,    2, 0x08 /* Private */,
      16,    0,  123,    2, 0x08 /* Private */,
      17,    0,  124,    2, 0x08 /* Private */,
      18,    0,  125,    2, 0x08 /* Private */,
      19,    0,  126,    2, 0x08 /* Private */,
      20,    0,  127,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_start_clicked(); break;
        case 1: _t->recvRegInfo(); break;
        case 2: _t->proc_timeout(); break;
        case 3: _t->proc_auth_timeout(); break;
        case 4: _t->proc_dereg_timeout(); break;
        case 5: _t->proc_periodtimeout(); break;
        case 6: _t->call_timeoutT9005(); break;
        case 7: _t->call_timeoutT9006(); break;
        case 8: _t->call_timeoutT9007(); break;
        case 9: _t->call_timeoutT9009(); break;
        case 10: _t->call_timeoutT9014(); break;
        case 11: _t->on_DeReigster_clicked(); break;
        case 12: _t->on_call_clicked(); break;
        case 13: _t->on_disconnect_clicked(); break;
        case 14: _t->on_connect_clicked(); break;
        case 15: _t->on_pushButton_clicked(); break;
        case 16: _t->on_pushButton_2_clicked(); break;
        case 17: _t->sendSipInvite(); break;
        case 18: _t->sendRegister(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
