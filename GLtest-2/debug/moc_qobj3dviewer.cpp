/****************************************************************************
** Meta object code from reading C++ file 'qobj3dviewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qobj3dviewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qobj3dviewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QObj3dViewer_t {
    QByteArrayData data[22];
    char stringdata0[163];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QObj3dViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QObj3dViewer_t qt_meta_stringdata_QObj3dViewer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "QObj3dViewer"
QT_MOC_LITERAL(1, 13, 11), // "setRotation"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "angle"
QT_MOC_LITERAL(4, 32, 1), // "x"
QT_MOC_LITERAL(5, 34, 1), // "y"
QT_MOC_LITERAL(6, 36, 1), // "z"
QT_MOC_LITERAL(7, 38, 14), // "setTranslation"
QT_MOC_LITERAL(8, 53, 8), // "setScale"
QT_MOC_LITERAL(9, 62, 1), // "s"
QT_MOC_LITERAL(10, 64, 14), // "setPerspective"
QT_MOC_LITERAL(11, 79, 13), // "verticalAngle"
QT_MOC_LITERAL(12, 93, 9), // "nearPlane"
QT_MOC_LITERAL(13, 103, 8), // "farPlane"
QT_MOC_LITERAL(14, 112, 9), // "setLookAt"
QT_MOC_LITERAL(15, 122, 3), // "eye"
QT_MOC_LITERAL(16, 126, 6), // "center"
QT_MOC_LITERAL(17, 133, 2), // "up"
QT_MOC_LITERAL(18, 136, 11), // "setLighting"
QT_MOC_LITERAL(19, 148, 8), // "lightPos"
QT_MOC_LITERAL(20, 157, 2), // "kd"
QT_MOC_LITERAL(21, 160, 2) // "ld"

    },
    "QObj3dViewer\0setRotation\0\0angle\0x\0y\0"
    "z\0setTranslation\0setScale\0s\0setPerspective\0"
    "verticalAngle\0nearPlane\0farPlane\0"
    "setLookAt\0eye\0center\0up\0setLighting\0"
    "lightPos\0kd\0ld"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QObj3dViewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   44,    2, 0x0a /* Public */,
       7,    3,   53,    2, 0x0a /* Public */,
       8,    1,   60,    2, 0x0a /* Public */,
      10,    3,   63,    2, 0x0a /* Public */,
      14,    3,   70,    2, 0x0a /* Public */,
      18,    3,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,    4,    5,    6,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void, QMetaType::Float, QMetaType::Float, QMetaType::Float,   11,   12,   13,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D, QMetaType::QVector3D,   15,   16,   17,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D, QMetaType::QVector3D,   19,   20,   21,

       0        // eod
};

void QObj3dViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QObj3dViewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setRotation((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 1: _t->setTranslation((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 2: _t->setScale((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->setPerspective((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 4: _t->setLookAt((*reinterpret_cast< const QVector3D(*)>(_a[1])),(*reinterpret_cast< const QVector3D(*)>(_a[2])),(*reinterpret_cast< const QVector3D(*)>(_a[3]))); break;
        case 5: _t->setLighting((*reinterpret_cast< const QVector3D(*)>(_a[1])),(*reinterpret_cast< const QVector3D(*)>(_a[2])),(*reinterpret_cast< const QVector3D(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QObj3dViewer::staticMetaObject = { {
    &QOpenGLWidget::staticMetaObject,
    qt_meta_stringdata_QObj3dViewer.data,
    qt_meta_data_QObj3dViewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QObj3dViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QObj3dViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QObj3dViewer.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions"))
        return static_cast< QOpenGLFunctions*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int QObj3dViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
