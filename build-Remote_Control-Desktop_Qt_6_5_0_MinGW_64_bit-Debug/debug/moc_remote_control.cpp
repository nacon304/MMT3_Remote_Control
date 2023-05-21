/****************************************************************************
** Meta object code from reading C++ file 'remote_control.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Remote_Control/remote_control.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'remote_control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSRemote_ControlENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSRemote_ControlENDCLASS = QtMocHelpers::stringData(
    "Remote_Control",
    "on_btn_login_connect_clicked",
    "",
    "on_btn_home_screen_clicked",
    "on_btn_home_key_clicked",
    "on_btn_home_folder_clicked",
    "on_btn_home_app_clicked",
    "on_btn_home_process_clicked",
    "on_btn_home_screen_link_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRemote_ControlENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[15];
    char stringdata1[29];
    char stringdata2[1];
    char stringdata3[27];
    char stringdata4[24];
    char stringdata5[27];
    char stringdata6[24];
    char stringdata7[28];
    char stringdata8[32];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRemote_ControlENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRemote_ControlENDCLASS_t qt_meta_stringdata_CLASSRemote_ControlENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "Remote_Control"
        QT_MOC_LITERAL(15, 28),  // "on_btn_login_connect_clicked"
        QT_MOC_LITERAL(44, 0),  // ""
        QT_MOC_LITERAL(45, 26),  // "on_btn_home_screen_clicked"
        QT_MOC_LITERAL(72, 23),  // "on_btn_home_key_clicked"
        QT_MOC_LITERAL(96, 26),  // "on_btn_home_folder_clicked"
        QT_MOC_LITERAL(123, 23),  // "on_btn_home_app_clicked"
        QT_MOC_LITERAL(147, 27),  // "on_btn_home_process_clicked"
        QT_MOC_LITERAL(175, 31)   // "on_btn_home_screen_link_clicked"
    },
    "Remote_Control",
    "on_btn_login_connect_clicked",
    "",
    "on_btn_home_screen_clicked",
    "on_btn_home_key_clicked",
    "on_btn_home_folder_clicked",
    "on_btn_home_app_clicked",
    "on_btn_home_process_clicked",
    "on_btn_home_screen_link_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRemote_ControlENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Remote_Control::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSRemote_ControlENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRemote_ControlENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRemote_ControlENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Remote_Control, std::true_type>,
        // method 'on_btn_login_connect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_home_screen_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_home_key_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_home_folder_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_home_app_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_home_process_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_home_screen_link_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Remote_Control::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Remote_Control *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_login_connect_clicked(); break;
        case 1: _t->on_btn_home_screen_clicked(); break;
        case 2: _t->on_btn_home_key_clicked(); break;
        case 3: _t->on_btn_home_folder_clicked(); break;
        case 4: _t->on_btn_home_app_clicked(); break;
        case 5: _t->on_btn_home_process_clicked(); break;
        case 6: _t->on_btn_home_screen_link_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Remote_Control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Remote_Control::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRemote_ControlENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Remote_Control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
