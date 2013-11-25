/****************************************************************************
** Meta object code from reading C++ file 'tile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "tile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Tile_t {
    QByteArrayData data[10];
    char stringdata[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Tile_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Tile_t qt_meta_stringdata_Tile = {
    {
QT_MOC_LITERAL(0, 0, 4),
QT_MOC_LITERAL(1, 5, 17),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 17),
QT_MOC_LITERAL(4, 42, 18),
QT_MOC_LITERAL(5, 61, 11),
QT_MOC_LITERAL(6, 73, 10),
QT_MOC_LITERAL(7, 84, 10),
QT_MOC_LITERAL(8, 95, 11),
QT_MOC_LITERAL(9, 107, 7)
    },
    "Tile\0hasButton1Changed\0\0hasButton2Changed\0"
    "highlightedChanged\0flipChanged\0"
    "hasButton1\0hasButton2\0highlighted\0"
    "canFlip\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tile[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       4,   38, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x05,
       3,    0,   35,    2, 0x05,
       4,    0,   36,    2, 0x05,
       5,    0,   37,    2, 0x05,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       6, QMetaType::Bool, 0x00495103,
       7, QMetaType::Bool, 0x00495103,
       8, QMetaType::Bool, 0x00495103,
       9, QMetaType::Bool, 0x00495003,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void Tile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tile *_t = static_cast<Tile *>(_o);
        switch (_id) {
        case 0: _t->hasButton1Changed(); break;
        case 1: _t->hasButton2Changed(); break;
        case 2: _t->highlightedChanged(); break;
        case 3: _t->flipChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Tile::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tile::hasButton1Changed)) {
                *result = 0;
            }
        }
        {
            typedef void (Tile::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tile::hasButton2Changed)) {
                *result = 1;
            }
        }
        {
            typedef void (Tile::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tile::highlightedChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (Tile::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tile::flipChanged)) {
                *result = 3;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Tile::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Tile.data,
      qt_meta_data_Tile,  qt_static_metacall, 0, 0}
};


const QMetaObject *Tile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Tile.stringdata))
        return static_cast<void*>(const_cast< Tile*>(this));
    return QObject::qt_metacast(_clname);
}

int Tile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = hasButton1(); break;
        case 1: *reinterpret_cast< bool*>(_v) = hasButton2(); break;
        case 2: *reinterpret_cast< bool*>(_v) = highlighted(); break;
        case 3: *reinterpret_cast< bool*>(_v) = canFlip(); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setHasButton1(*reinterpret_cast< bool*>(_v)); break;
        case 1: setHasButton2(*reinterpret_cast< bool*>(_v)); break;
        case 2: setHighlighted(*reinterpret_cast< bool*>(_v)); break;
        case 3: setFlip(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 4;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Tile::hasButton1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Tile::hasButton2Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Tile::highlightedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Tile::flipChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
