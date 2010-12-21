/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Dec 16 14:59:21 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      20,   12,   11,   11, 0x08,
      32,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      45,   11,   11,   11, 0x08,
      52,   11,   11,   11, 0x08,
      61,   11,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
      92,   11,   11,   11, 0x08,
     100,   11,   11,   11, 0x08,
     107,   11,   11,   11, 0x08,
     115,   11,   11,   11, 0x08,
     121,   11,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     141,   11,   11,   11, 0x08,
     150,   11,   11,   11, 0x08,
     160,   11,   11,   11, 0x08,
     167,   11,   11,   11, 0x08,
     174,   11,   11,   11, 0x08,
     181,   11,   11,   11, 0x08,
     187,   11,   11,   11, 0x08,
     196,   11,   11,   11, 0x08,
     204,   11,   11,   11, 0x08,
     217,  211,   11,   11, 0x08,
     238,   11,   11,   11, 0x08,
     258,  247,   11,   11, 0x08,
     292,  282,   11,   11, 0x08,
     327,  315,   11,   11, 0x08,
     359,  349,   11,   11, 0x08,
     382,   11,   11,   11, 0x08,
     393,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0newSize\0resize(int)\0add()\0"
    "bend()\0move()\0rotate()\0viewRotate()\0"
    "connectit()\0top()\0front()\0left()\0"
    "right()\0v45()\0v135()\0spin()\0pan()\0"
    "zoomIn()\0zoomOut()\0open()\0save()\0"
    "exit()\0del()\0modify()\0color()\0axis()\0"
    "index\0componentChosen(int)\0timeup()\0"
    "actionName\0actionSelected(QString)\0"
    "frameName\0frameSelected(QString)\0"
    "delaySecond\0delaySelected(double)\0"
    "curveName\0curveSelected(QString)\0"
    "addFrame()\0addAction()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: resize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: add(); break;
        case 2: bend(); break;
        case 3: move(); break;
        case 4: rotate(); break;
        case 5: viewRotate(); break;
        case 6: connectit(); break;
        case 7: top(); break;
        case 8: front(); break;
        case 9: left(); break;
        case 10: right(); break;
        case 11: v45(); break;
        case 12: v135(); break;
        case 13: spin(); break;
        case 14: pan(); break;
        case 15: zoomIn(); break;
        case 16: zoomOut(); break;
        case 17: open(); break;
        case 18: save(); break;
        case 19: exit(); break;
        case 20: del(); break;
        case 21: modify(); break;
        case 22: color(); break;
        case 23: axis(); break;
        case 24: componentChosen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: timeup(); break;
        case 26: actionSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 27: frameSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 28: delaySelected((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: curveSelected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 30: addFrame(); break;
        case 31: addAction(); break;
        default: ;
        }
        _id -= 32;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
