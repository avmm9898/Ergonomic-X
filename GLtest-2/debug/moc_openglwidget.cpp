/****************************************************************************
** Meta object code from reading C++ file 'openglwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../openglwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'openglwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_openglwidget_t {
    QByteArrayData data[11];
    char stringdata0[81];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_openglwidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_openglwidget_t qt_meta_stringdata_openglwidget = {
    {
QT_MOC_LITERAL(0, 0, 12), // "openglwidget"
QT_MOC_LITERAL(1, 13, 11), // "qColorToRGB"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 1), // "C"
QT_MOC_LITERAL(4, 28, 6), // "float&"
QT_MOC_LITERAL(5, 35, 1), // "r"
QT_MOC_LITERAL(6, 37, 1), // "g"
QT_MOC_LITERAL(7, 39, 1), // "b"
QT_MOC_LITERAL(8, 41, 17), // "quat_to_rotmatrix"
QT_MOC_LITERAL(9, 59, 12), // "drawGridCube"
QT_MOC_LITERAL(10, 72, 8) // "drawAxes"

    },
    "openglwidget\0qColorToRGB\0\0C\0float&\0r\0"
    "g\0b\0quat_to_rotmatrix\0drawGridCube\0"
    "drawAxes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_openglwidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x08 /* Private */,
       8,    1,   43,    2, 0x08 /* Private */,
       9,    0,   46,    2, 0x08 /* Private */,
      10,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QColor, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4,    3,    5,    6,    7,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void openglwidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<openglwidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->qColorToRGB((*reinterpret_cast< const QColor(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 1: _t->quat_to_rotmatrix((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->drawGridCube(); break;
        case 3: _t->drawAxes(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject openglwidget::staticMetaObject = { {
    &QOpenGLWidget::staticMetaObject,
    qt_meta_stringdata_openglwidget.data,
    qt_meta_data_openglwidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *openglwidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *openglwidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_openglwidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int openglwidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
