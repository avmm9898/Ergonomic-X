/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[308];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 17), // "send_thread_start"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "send_thread_exit"
QT_MOC_LITERAL(4, 47, 24), // "on_actionclose_triggered"
QT_MOC_LITERAL(5, 72, 27), // "on_BTN_StartAllLpms_clicked"
QT_MOC_LITERAL(6, 100, 12), // "data_display"
QT_MOC_LITERAL(7, 113, 11), // "LpmsDevice*"
QT_MOC_LITERAL(8, 125, 12), // "data_receive"
QT_MOC_LITERAL(9, 138, 12), // "lpms_connect"
QT_MOC_LITERAL(10, 151, 9), // "rula_calc"
QT_MOC_LITERAL(11, 161, 10), // "timer_loop"
QT_MOC_LITERAL(12, 172, 25), // "on_BTN_set_origin_clicked"
QT_MOC_LITERAL(13, 198, 21), // "on_btn_x_plus_clicked"
QT_MOC_LITERAL(14, 220, 21), // "on_btn_y_plus_clicked"
QT_MOC_LITERAL(15, 242, 21), // "on_btn_z_plus_clicked"
QT_MOC_LITERAL(16, 264, 21), // "on_OpenHead_triggered"
QT_MOC_LITERAL(17, 286, 21) // "on_OpenBody_triggered"

    },
    "MainWindow\0send_thread_start\0\0"
    "send_thread_exit\0on_actionclose_triggered\0"
    "on_BTN_StartAllLpms_clicked\0data_display\0"
    "LpmsDevice*\0data_receive\0lpms_connect\0"
    "rula_calc\0timer_loop\0on_BTN_set_origin_clicked\0"
    "on_btn_x_plus_clicked\0on_btn_y_plus_clicked\0"
    "on_btn_z_plus_clicked\0on_OpenHead_triggered\0"
    "on_OpenBody_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    1,   93,    2, 0x08 /* Private */,
       8,    1,   96,    2, 0x08 /* Private */,
       9,    1,   99,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Int,
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
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_thread_start(); break;
        case 1: _t->send_thread_exit(); break;
        case 2: _t->on_actionclose_triggered(); break;
        case 3: _t->on_BTN_StartAllLpms_clicked(); break;
        case 4: _t->data_display((*reinterpret_cast< LpmsDevice*(*)>(_a[1]))); break;
        case 5: _t->data_receive((*reinterpret_cast< LpmsDevice*(*)>(_a[1]))); break;
        case 6: _t->lpms_connect((*reinterpret_cast< LpmsDevice*(*)>(_a[1]))); break;
        case 7: { int _r = _t->rula_calc();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->timer_loop(); break;
        case 9: _t->on_BTN_set_origin_clicked(); break;
        case 10: _t->on_btn_x_plus_clicked(); break;
        case 11: _t->on_btn_y_plus_clicked(); break;
        case 12: _t->on_btn_z_plus_clicked(); break;
        case 13: _t->on_OpenHead_triggered(); break;
        case 14: _t->on_OpenBody_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_thread_start)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::send_thread_exit)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::send_thread_start()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MainWindow::send_thread_exit()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
