/****************************************************************************
** Meta object code from reading C++ file 'hmagazzino.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hmagazzino.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hmagazzino.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HMagazzino_t {
    QByteArrayData data[16];
    char stringdata[274];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HMagazzino_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HMagazzino_t qt_meta_stringdata_HMagazzino = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 21),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 23),
QT_MOC_LITERAL(4, 58, 8),
QT_MOC_LITERAL(5, 67, 19),
QT_MOC_LITERAL(6, 87, 23),
QT_MOC_LITERAL(7, 111, 23),
QT_MOC_LITERAL(8, 135, 7),
QT_MOC_LITERAL(9, 143, 23),
QT_MOC_LITERAL(10, 167, 19),
QT_MOC_LITERAL(11, 187, 17),
QT_MOC_LITERAL(12, 205, 12),
QT_MOC_LITERAL(13, 218, 23),
QT_MOC_LITERAL(14, 242, 7),
QT_MOC_LITERAL(15, 250, 23)
    },
    "HMagazzino\0on_pushButton_clicked\0\0"
    "on_pushButton_2_clicked\0cercaLot\0"
    "on_btsearch_clicked\0on_pushButton_4_clicked\0"
    "on_pushButton_3_clicked\0refresh\0"
    "on_pushButton_5_clicked\0onConnectionNameSet\0"
    "on_rbprod_clicked\0updateFilter\0"
    "on_pushButton_6_toggled\0checked\0"
    "on_pushButton_6_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HMagazzino[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    0,   82,    2, 0x08 /* Private */,
       6,    0,   83,    2, 0x08 /* Private */,
       7,    0,   84,    2, 0x08 /* Private */,
       8,    0,   85,    2, 0x08 /* Private */,
       9,    0,   86,    2, 0x08 /* Private */,
      10,    0,   87,    2, 0x08 /* Private */,
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    1,   90,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void,

       0        // eod
};

void HMagazzino::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HMagazzino *_t = static_cast<HMagazzino *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: _t->on_pushButton_2_clicked(); break;
        case 2: _t->cercaLot(); break;
        case 3: _t->on_btsearch_clicked(); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->on_pushButton_3_clicked(); break;
        case 6: _t->refresh(); break;
        case 7: _t->on_pushButton_5_clicked(); break;
        case 8: _t->onConnectionNameSet(); break;
        case 9: _t->on_rbprod_clicked(); break;
        case 10: _t->updateFilter(); break;
        case 11: _t->on_pushButton_6_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_pushButton_6_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject HMagazzino::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HMagazzino.data,
      qt_meta_data_HMagazzino,  qt_static_metacall, 0, 0}
};


const QMetaObject *HMagazzino::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HMagazzino::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HMagazzino.stringdata))
        return static_cast<void*>(const_cast< HMagazzino*>(this));
    return QWidget::qt_metacast(_clname);
}

int HMagazzino::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
