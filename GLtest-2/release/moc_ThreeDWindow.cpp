/****************************************************************************
** Meta object code from reading C++ file 'ThreeDWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ThreeDWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ThreeDWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThreeDWindow_t {
    QByteArrayData data[25];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThreeDWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThreeDWindow_t qt_meta_stringdata_ThreeDWindow = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ThreeDWindow"
QT_MOC_LITERAL(1, 13, 14), // "updateFieldMap"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "float[3][6][6][3]"
QT_MOC_LITERAL(4, 47, 8), // "magField"
QT_MOC_LITERAL(5, 56, 8), // "float[3]"
QT_MOC_LITERAL(6, 65, 14), // "hardIronOffset"
QT_MOC_LITERAL(7, 80, 11), // "float[3][3]"
QT_MOC_LITERAL(8, 92, 14), // "softIronMatrix"
QT_MOC_LITERAL(9, 107, 12), // "updateWindow"
QT_MOC_LITERAL(10, 120, 8), // "rotateBy"
QT_MOC_LITERAL(11, 129, 6), // "xAngle"
QT_MOC_LITERAL(12, 136, 6), // "yAngle"
QT_MOC_LITERAL(13, 143, 6), // "zAngle"
QT_MOC_LITERAL(14, 150, 13), // "rotateSceneBy"
QT_MOC_LITERAL(15, 164, 15), // "mousePressEvent"
QT_MOC_LITERAL(16, 180, 12), // "QMouseEvent*"
QT_MOC_LITERAL(17, 193, 5), // "event"
QT_MOC_LITERAL(18, 199, 14), // "mouseMoveEvent"
QT_MOC_LITERAL(19, 214, 10), // "wheelEvent"
QT_MOC_LITERAL(20, 225, 12), // "QWheelEvent*"
QT_MOC_LITERAL(21, 238, 14), // "updateRMbyQuat"
QT_MOC_LITERAL(22, 253, 11), // "LpmsDevice*"
QT_MOC_LITERAL(23, 265, 6), // "m_lpms"
QT_MOC_LITERAL(24, 272, 21) // "model_view_correction"

    },
    "ThreeDWindow\0updateFieldMap\0\0"
    "float[3][6][6][3]\0magField\0float[3]\0"
    "hardIronOffset\0float[3][3]\0softIronMatrix\0"
    "updateWindow\0rotateBy\0xAngle\0yAngle\0"
    "zAngle\0rotateSceneBy\0mousePressEvent\0"
    "QMouseEvent*\0event\0mouseMoveEvent\0"
    "wheelEvent\0QWheelEvent*\0updateRMbyQuat\0"
    "LpmsDevice*\0m_lpms\0model_view_correction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThreeDWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    3,   67,    2, 0x0a /* Public */,
      14,    3,   74,    2, 0x0a /* Public */,
      15,    1,   81,    2, 0x0a /* Public */,
      18,    1,   84,    2, 0x0a /* Public */,
      19,    1,   87,    2, 0x0a /* Public */,
      21,    1,   90,    2, 0x0a /* Public */,
      24,    1,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5, 0x80000000 | 7,    4,    6,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   12,   13,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   11,   12,   13,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, 0x80000000 | 20,   17,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, 0x80000000 | 22,   23,

       0        // eod
};

void ThreeDWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ThreeDWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateFieldMap((*reinterpret_cast< float(*)[3][6][6][3]>(_a[1])),(*reinterpret_cast< float(*)[3]>(_a[2])),(*reinterpret_cast< float(*)[3][3]>(_a[3]))); break;
        case 1: _t->updateWindow(); break;
        case 2: _t->rotateBy((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->rotateSceneBy((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: _t->wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 7: _t->updateRMbyQuat((*reinterpret_cast< LpmsDevice*(*)>(_a[1]))); break;
        case 8: _t->model_view_correction((*reinterpret_cast< LpmsDevice*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ThreeDWindow::staticMetaObject = { {
    &QOpenGLWidget::staticMetaObject,
    qt_meta_stringdata_ThreeDWindow.data,
    qt_meta_data_ThreeDWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
