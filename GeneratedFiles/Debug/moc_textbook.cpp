/****************************************************************************
** Meta object code from reading C++ file 'textbook.h'
**
** Created: Sat Feb 20 08:34:43 2016
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../textbook.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TextBook[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      24,    9,    9,    9, 0x08,
      39,    9,    9,    9, 0x08,
      54,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TextBook[] = {
    "TextBook\0\0slotNewFile()\0slotSaveFile()\0"
    "slotOpenFile()\0slotSaveAsFilee()\0"
};

const QMetaObject TextBook::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_TextBook,
      qt_meta_data_TextBook, 0 }
};

const QMetaObject *TextBook::metaObject() const
{
    return &staticMetaObject;
}

void *TextBook::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TextBook))
        return static_cast<void*>(const_cast< TextBook*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int TextBook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: slotNewFile(); break;
        case 1: slotSaveFile(); break;
        case 2: slotOpenFile(); break;
        case 3: slotSaveAsFilee(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
