/****************************************************************************
** Meta object code from reading C++ file 'huser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../huser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'huser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HUser_t {
    QByteArrayData data[20];
    char stringdata[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HUser_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HUser_t qt_meta_stringdata_HUser = {
    {
QT_MOC_LITERAL(0, 0, 5),
QT_MOC_LITERAL(1, 6, 11),
QT_MOC_LITERAL(2, 18, 0),
QT_MOC_LITERAL(3, 19, 5),
QT_MOC_LITERAL(4, 25, 7),
QT_MOC_LITERAL(5, 33, 4),
QT_MOC_LITERAL(6, 38, 7),
QT_MOC_LITERAL(7, 46, 9),
QT_MOC_LITERAL(8, 56, 8),
QT_MOC_LITERAL(9, 65, 5),
QT_MOC_LITERAL(10, 71, 2),
QT_MOC_LITERAL(11, 74, 5),
QT_MOC_LITERAL(12, 80, 12),
QT_MOC_LITERAL(13, 93, 12),
QT_MOC_LITERAL(14, 106, 3),
QT_MOC_LITERAL(15, 110, 4),
QT_MOC_LITERAL(16, 115, 4),
QT_MOC_LITERAL(17, 120, 16),
QT_MOC_LITERAL(18, 137, 16),
QT_MOC_LITERAL(19, 154, 11)
    },
    "HUser\0setUserName\0\0uname\0setRole\0role\0"
    "getRole\0setActive\0isActive\0setID\0ID\0"
    "getID\0getCanUpdate\0setCanUpdate\0upd\0"
    "init\0conn\0setCanUpdateAnag\0getCanUpdateAnag\0"
    "getUsername"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HUser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x0a /* Public */,
       4,    1,   77,    2, 0x0a /* Public */,
       6,    0,   80,    2, 0x0a /* Public */,
       7,    1,   81,    2, 0x0a /* Public */,
       9,    1,   84,    2, 0x0a /* Public */,
      11,    0,   87,    2, 0x0a /* Public */,
      12,    0,   88,    2, 0x0a /* Public */,
      13,    1,   89,    2, 0x0a /* Public */,
      15,    1,   92,    2, 0x0a /* Public */,
      17,    1,   95,    2, 0x0a /* Public */,
      18,    0,   98,    2, 0x0a /* Public */,
      19,    0,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Bool,
    QMetaType::QString,

       0        // eod
};

void HUser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HUser *_t = static_cast<HUser *>(_o);
        switch (_id) {
        case 0: _t->setUserName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->setRole((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: { int _r = _t->getRole();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 3: _t->setActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setID((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: { int _r = _t->getID();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: { bool _r = _t->getCanUpdate();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: _t->setCanUpdate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->init((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setCanUpdateAnag((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: { bool _r = _t->getCanUpdateAnag();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { QString _r = _t->getUsername();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject HUser::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HUser.data,
      qt_meta_data_HUser,  qt_static_metacall, 0, 0}
};


const QMetaObject *HUser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HUser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HUser.stringdata))
        return static_cast<void*>(const_cast< HUser*>(this));
    return QObject::qt_metacast(_clname);
}

int HUser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
