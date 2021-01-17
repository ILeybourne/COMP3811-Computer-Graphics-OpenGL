/****************************************************************************
** Meta object code from reading C++ file 'SceneWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SceneWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SceneWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SceneWidget_t {
    QByteArrayData data[9];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SceneWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SceneWidget_t qt_meta_stringdata_SceneWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SceneWidget"
QT_MOC_LITERAL(1, 12, 12), // "getFrameRate"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 19), // "changeScreenTexture"
QT_MOC_LITERAL(4, 46, 1), // "i"
QT_MOC_LITERAL(5, 48, 17), // "changeGyroTexture"
QT_MOC_LITERAL(6, 66, 11), // "resetCamera"
QT_MOC_LITERAL(7, 78, 17), // "changeTerrainSeed"
QT_MOC_LITERAL(8, 96, 4) // "seed"

    },
    "SceneWidget\0getFrameRate\0\0changeScreenTexture\0"
    "i\0changeGyroTexture\0resetCamera\0"
    "changeTerrainSeed\0seed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SceneWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    1,   40,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,
       6,    0,   46,    2, 0x0a /* Public */,
       7,    1,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::ULongLong,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void SceneWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SceneWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { unsigned long long _r = _t->getFrameRate();
            if (_a[0]) *reinterpret_cast< unsigned long long*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->changeScreenTexture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->changeGyroTexture((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->resetCamera(); break;
        case 4: _t->changeTerrainSeed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SceneWidget::staticMetaObject = { {
    &QGLWidget::staticMetaObject,
    qt_meta_stringdata_SceneWidget.data,
    qt_meta_data_SceneWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SceneWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SceneWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SceneWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGLFunctions"))
        return static_cast< QGLFunctions*>(this);
    return QGLWidget::qt_metacast(_clname);
}

int SceneWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
