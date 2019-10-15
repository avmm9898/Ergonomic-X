/****************************************************************************
** Meta object code from reading C++ file 'ThreeDWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ThreeDWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreeDWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreeDWindow_t {
    QByteArrayData data[17];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreeDWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreeDWindow_t qt_meta_stringdata_ThreeDWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ThreeDWindow"
QT_MOC_LITERAL(1, 13, 12), // "updateWindow"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "rotateBy"
QT_MOC_LITERAL(4, 36, 6), // "xAngle"
QT_MOC_LITERAL(5, 43, 6), // "yAngle"
QT_MOC_LITERAL(6, 50, 6), // "zAngle"
QT_MOC_LITERAL(7, 57, 15), // "mousePressEvent"
QT_MOC_LITERAL(8, 73, 12), // "QMouseEvent*"
QT_MOC_LITERAL(9, 86, 5), // "event"
QT_MOC_LITERAL(10, 92, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(11, 107, 10), // "wheelEvent"
QT_MOC_LITERAL(12, 118, 12), // "QWheelEvent*"
QT_MOC_LITERAL(13, 131, 14), // "updateRMbyQuat"
QT_MOC_LITERAL(14, 146, 11), // "LpmsDevice*"
QT_MOC_LITERAL(15, 158, 6), // "m_lpms"
QT_MOC_LITERAL(16, 165, 21) // "model_view_correction"

    },
    "ThreeDWindow\0updateWindow\0\0rotateBy\0"
    "xAngle\0yAngle\0zAngle\0mousePressEvent\0"
    "QMouseEvent*\0event\0mouseMoveEvent\0"
    "wheelEvent\0QWheelEvent*\0updateRMbyQuat\0"
    "LpmsDevice*\0m_lpms\0model_view_correction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreeDWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    3,   50,    2, 0x0a /* Public */,
       7,    1,   57,    2, 0x0a /* Public */,
      10,    1,   60,    2, 0x0a /* Public */,
      11,    1,   63,    2, 0x0a /* Public */,
      13,    1,   66,    2, 0x0a /* Public */,
      16,    1,   69,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 12,    9,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void ThreeDWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ThreeDWindow *_t = static_cast<ThreeDWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateWindow(); break;
        case 1: _t->rotateBy((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 2: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 4: _t->wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 5: _t->updateRMbyQuat((*reinterpret_cast< LpmsDevice*(*)>(_a[1]))); break;
        case 6: _t->model_view_correction((*reinterpret_cast< LpmsDevice*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject ThreeDWindow::staticMetaObject = {
    { &QOpenGLWidget::staticMetaObject, qt_meta_stringdata_ThreeDWindow.data,
      qt_meta_data_ThreeDWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ThreeDWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThreeDWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThreeDWindow.stringdata0))
        return static_cast<void*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int ThreeDWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
