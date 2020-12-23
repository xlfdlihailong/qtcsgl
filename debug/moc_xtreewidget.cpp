/****************************************************************************
** Meta object code from reading C++ file 'xtreewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../xtreewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xtreewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_xTreeWidget_t {
    QByteArrayData data[20];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_xTreeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_xTreeWidget_t qt_meta_stringdata_xTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 11), // "xTreeWidget"
QT_MOC_LITERAL(1, 12, 15), // "sigShowMaxIndex"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "url"
QT_MOC_LITERAL(4, 33, 8), // "sigClick"
QT_MOC_LITERAL(5, 42, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(6, 59, 4), // "item"
QT_MOC_LITERAL(7, 64, 6), // "column"
QT_MOC_LITERAL(8, 71, 14), // "sigDoubleClick"
QT_MOC_LITERAL(9, 86, 32), // "sigTransSystemNameAndStationName"
QT_MOC_LITERAL(10, 119, 7), // "pstring"
QT_MOC_LITERAL(11, 127, 3), // "sys"
QT_MOC_LITERAL(12, 131, 7), // "station"
QT_MOC_LITERAL(13, 139, 7), // "popMenu"
QT_MOC_LITERAL(14, 147, 9), // "itemClick"
QT_MOC_LITERAL(15, 157, 15), // "itemDoubleClick"
QT_MOC_LITERAL(16, 173, 14), // "slotDeleteItem"
QT_MOC_LITERAL(17, 188, 11), // "slotAddItem"
QT_MOC_LITERAL(18, 200, 16), // "slotAddItemAfter"
QT_MOC_LITERAL(19, 217, 14) // "slotItemUpdate"

    },
    "xTreeWidget\0sigShowMaxIndex\0\0url\0"
    "sigClick\0QTreeWidgetItem*\0item\0column\0"
    "sigDoubleClick\0sigTransSystemNameAndStationName\0"
    "pstring\0sys\0station\0popMenu\0itemClick\0"
    "itemDoubleClick\0slotDeleteItem\0"
    "slotAddItem\0slotAddItemAfter\0"
    "slotItemUpdate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_xTreeWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    2,   72,    2, 0x06 /* Public */,
       8,    2,   77,    2, 0x06 /* Public */,
       9,    2,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,   87,    2, 0x08 /* Private */,
      14,    2,   90,    2, 0x08 /* Private */,
      15,    2,   95,    2, 0x08 /* Private */,
      16,    0,  100,    2, 0x08 /* Private */,
      17,    0,  101,    2, 0x08 /* Private */,
      18,    0,  102,    2, 0x08 /* Private */,
      19,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 10,   11,   12,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void xTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<xTreeWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigShowMaxIndex((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sigClick((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sigDoubleClick((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->sigTransSystemNameAndStationName((*reinterpret_cast< pstring(*)>(_a[1])),(*reinterpret_cast< pstring(*)>(_a[2]))); break;
        case 4: _t->popMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 5: _t->itemClick((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->itemDoubleClick((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->slotDeleteItem(); break;
        case 8: _t->slotAddItem(); break;
        case 9: _t->slotAddItemAfter(); break;
        case 10: _t->slotItemUpdate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (xTreeWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&xTreeWidget::sigShowMaxIndex)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (xTreeWidget::*)(QTreeWidgetItem * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&xTreeWidget::sigClick)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (xTreeWidget::*)(QTreeWidgetItem * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&xTreeWidget::sigDoubleClick)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (xTreeWidget::*)(pstring , pstring );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&xTreeWidget::sigTransSystemNameAndStationName)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject xTreeWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_xTreeWidget.data,
    qt_meta_data_xTreeWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *xTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *xTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_xTreeWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int xTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void xTreeWidget::sigShowMaxIndex(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void xTreeWidget::sigClick(QTreeWidgetItem * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void xTreeWidget::sigDoubleClick(QTreeWidgetItem * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void xTreeWidget::sigTransSystemNameAndStationName(pstring _t1, pstring _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
