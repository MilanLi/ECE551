/****************************************************************************
** Meta object code from reading C++ file 'gamedata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gamedata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamedata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GameData_t {
    QByteArrayData data[28];
    char stringdata[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GameData_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GameData_t qt_meta_stringdata_GameData = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 12),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 15),
QT_MOC_LITERAL(4, 39, 18),
QT_MOC_LITERAL(5, 58, 13),
QT_MOC_LITERAL(6, 72, 12),
QT_MOC_LITERAL(7, 85, 12),
QT_MOC_LITERAL(8, 98, 11),
QT_MOC_LITERAL(9, 110, 9),
QT_MOC_LITERAL(10, 120, 9),
QT_MOC_LITERAL(11, 130, 5),
QT_MOC_LITERAL(12, 136, 10),
QT_MOC_LITERAL(13, 147, 10),
QT_MOC_LITERAL(14, 158, 6),
QT_MOC_LITERAL(15, 165, 5),
QT_MOC_LITERAL(16, 171, 6),
QT_MOC_LITERAL(17, 178, 12),
QT_MOC_LITERAL(18, 191, 10),
QT_MOC_LITERAL(19, 202, 10),
QT_MOC_LITERAL(20, 213, 10),
QT_MOC_LITERAL(21, 224, 4),
QT_MOC_LITERAL(22, 229, 5),
QT_MOC_LITERAL(23, 235, 8),
QT_MOC_LITERAL(24, 244, 11),
QT_MOC_LITERAL(25, 256, 6),
QT_MOC_LITERAL(26, 263, 5),
QT_MOC_LITERAL(27, 269, 30)
    },
    "GameData\0movesChanged\0\0gameTimeChanged\0"
    "player1TurnChanged\0gameOnChanged\0"
    "BlackChanged\0WhiteChanged\0UndoChanged\0"
    "resetGame\0pauseGame\0state\0countBlack\0"
    "countWhite\0flipHH\0index\0flipHC\0"
    "flipcomputer\0undoTileHH\0undoTileHC\0"
    "updateTime\0undo\0moves\0gameTime\0"
    "player1Turn\0gameOn\0tiles\0"
    "QDeclarativeListProperty<Tile>\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       8,  128, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x05,
       3,    0,  105,    2, 0x05,
       4,    0,  106,    2, 0x05,
       5,    0,  107,    2, 0x05,
       6,    0,  108,    2, 0x05,
       7,    0,  109,    2, 0x05,
       8,    0,  110,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       9,    0,  111,    2, 0x0a,
      10,    1,  112,    2, 0x0a,
      12,    0,  115,    2, 0x0a,
      13,    0,  116,    2, 0x0a,
      14,    1,  117,    2, 0x0a,
      16,    1,  120,    2, 0x0a,
      17,    0,  123,    2, 0x0a,
      18,    0,  124,    2, 0x0a,
      19,    0,  125,    2, 0x0a,
      20,    0,  126,    2, 0x0a,
      21,    0,  127,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,

 // properties: name, type, flags
      22, QMetaType::Int, 0x00495103,
      23, QMetaType::QString, 0x00495103,
      13, QMetaType::Int, 0x00495003,
      12, QMetaType::Int, 0x00495003,
      21, QMetaType::Bool, 0x00495103,
      24, QMetaType::Bool, 0x00495103,
      25, QMetaType::Bool, 0x00495103,
      26, 0x80000000 | 27, 0x00095409,

 // properties: notify_signal_id
       0,
       1,
       5,
       4,
       6,
       2,
       3,
       0,

       0        // eod
};

void GameData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GameData *_t = static_cast<GameData *>(_o);
        switch (_id) {
        case 0: _t->movesChanged(); break;
        case 1: _t->gameTimeChanged(); break;
        case 2: _t->player1TurnChanged(); break;
        case 3: _t->gameOnChanged(); break;
        case 4: _t->BlackChanged(); break;
        case 5: _t->WhiteChanged(); break;
        case 6: _t->UndoChanged(); break;
        case 7: _t->resetGame(); break;
        case 8: _t->pauseGame((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: { int _r = _t->countBlack();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: { int _r = _t->countWhite();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 11: _t->flipHH((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->flipHC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->flipcomputer(); break;
        case 14: _t->undoTileHH(); break;
        case 15: _t->undoTileHC(); break;
        case 16: _t->updateTime(); break;
        case 17: { bool _r = _t->undo();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GameData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameData::movesChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (GameData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameData::gameTimeChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (GameData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameData::player1TurnChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (GameData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameData::gameOnChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (GameData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameData::BlackChanged)) {
                *result = 4;
            }
        }
        {
            typedef void (GameData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameData::WhiteChanged)) {
                *result = 5;
            }
        }
        {
            typedef void (GameData::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GameData::UndoChanged)) {
                *result = 6;
            }
        }
    }
}

const QMetaObject GameData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GameData.data,
      qt_meta_data_GameData,  qt_static_metacall, 0, 0}
};


const QMetaObject *GameData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameData::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GameData.stringdata))
        return static_cast<void*>(const_cast< GameData*>(this));
    return QObject::qt_metacast(_clname);
}

int GameData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = moves(); break;
        case 1: *reinterpret_cast< QString*>(_v) = gameTime(); break;
        case 2: *reinterpret_cast< int*>(_v) = countWhite(); break;
        case 3: *reinterpret_cast< int*>(_v) = countBlack(); break;
        case 4: *reinterpret_cast< bool*>(_v) = undo(); break;
        case 5: *reinterpret_cast< bool*>(_v) = player1Turn(); break;
        case 6: *reinterpret_cast< bool*>(_v) = gameOn(); break;
        case 7: *reinterpret_cast< QDeclarativeListProperty<Tile>*>(_v) = tiles(); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setMoves(*reinterpret_cast< int*>(_v)); break;
        case 1: setGameTime(*reinterpret_cast< QString*>(_v)); break;
        case 2: setWhite(*reinterpret_cast< int*>(_v)); break;
        case 3: setBlack(*reinterpret_cast< int*>(_v)); break;
        case 4: setUndo(*reinterpret_cast< bool*>(_v)); break;
        case 5: setPlayer1Turn(*reinterpret_cast< bool*>(_v)); break;
        case 6: setGameOn(*reinterpret_cast< bool*>(_v)); break;
        }
        _id -= 8;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void GameData::movesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void GameData::gameTimeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void GameData::player1TurnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void GameData::gameOnChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void GameData::BlackChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void GameData::WhiteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void GameData::UndoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}
QT_END_MOC_NAMESPACE
