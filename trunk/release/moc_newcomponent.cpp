/****************************************************************************
** Meta object code from reading C++ file 'newcomponent.h'
**
** Created: Tue Nov 24 16:12:51 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../newcomponent.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newcomponent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewComponent[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x08,
      44,   13,   39,   13, 0x08,
      60,   14,   13,   13, 0x08,
      79,   73,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewComponent[] = {
    "NewComponent\0\0index\0parentChanged(int)\0"
    "bool\0validateInput()\0pointTo(int)\0"
    "x,y,z\0setDir(float,float,float)\0"
};

const QMetaObject NewComponent::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewComponent,
      qt_meta_data_NewComponent, 0 }
};

const QMetaObject *NewComponent::metaObject() const
{
    return &staticMetaObject;
}

void *NewComponent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewComponent))
        return static_cast<void*>(const_cast< NewComponent*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewComponent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: parentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: { bool _r = validateInput();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: pointTo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: setDir((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
