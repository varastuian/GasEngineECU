/****************************************************************************
** Meta object code from reading C++ file 'ecucontroller.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/Vahid/ecucontroller.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ecucontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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
struct qt_meta_stringdata_CLASSECUControllerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSECUControllerENDCLASS = QtMocHelpers::stringData(
    "ECUController",
    "messageReceived",
    "",
    "LinkInterface*",
    "link",
    "__message",
    "message",
    "dataChanged",
    "receiveBytes",
    "b",
    "onTimeout",
    "init",
    "startEngine",
    "stopEngine",
    "flameout",
    "vehicleComponents",
    "vehicleCkeck"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSECUControllerENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[14];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[5];
    char stringdata5[10];
    char stringdata6[8];
    char stringdata7[12];
    char stringdata8[13];
    char stringdata9[2];
    char stringdata10[10];
    char stringdata11[5];
    char stringdata12[12];
    char stringdata13[11];
    char stringdata14[9];
    char stringdata15[18];
    char stringdata16[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSECUControllerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSECUControllerENDCLASS_t qt_meta_stringdata_CLASSECUControllerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "ECUController"
        QT_MOC_LITERAL(14, 15),  // "messageReceived"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 14),  // "LinkInterface*"
        QT_MOC_LITERAL(46, 4),  // "link"
        QT_MOC_LITERAL(51, 9),  // "__message"
        QT_MOC_LITERAL(61, 7),  // "message"
        QT_MOC_LITERAL(69, 11),  // "dataChanged"
        QT_MOC_LITERAL(81, 12),  // "receiveBytes"
        QT_MOC_LITERAL(94, 1),  // "b"
        QT_MOC_LITERAL(96, 9),  // "onTimeout"
        QT_MOC_LITERAL(106, 4),  // "init"
        QT_MOC_LITERAL(111, 11),  // "startEngine"
        QT_MOC_LITERAL(123, 10),  // "stopEngine"
        QT_MOC_LITERAL(134, 8),  // "flameout"
        QT_MOC_LITERAL(143, 17),  // "vehicleComponents"
        QT_MOC_LITERAL(161, 12)   // "vehicleCkeck"
    },
    "ECUController",
    "messageReceived",
    "",
    "LinkInterface*",
    "link",
    "__message",
    "message",
    "dataChanged",
    "receiveBytes",
    "b",
    "onTimeout",
    "init",
    "startEngine",
    "stopEngine",
    "flameout",
    "vehicleComponents",
    "vehicleCkeck"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSECUControllerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       2,   78, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   62,    2, 0x06,    3 /* Public */,
       7,    0,   67,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    2,   68,    2, 0x0a,    7 /* Public */,
      10,    0,   73,    2, 0x0a,   10 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,   74,    2, 0x02,   11 /* Public */,
      12,    0,   75,    2, 0x02,   12 /* Public */,
      13,    0,   76,    2, 0x02,   13 /* Public */,
      14,    0,   77,    2, 0x02,   14 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QByteArray,    4,    9,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      15, QMetaType::QVariantList, 0x00015001, uint(1), 0,
      16, QMetaType::QVariantList, 0x00015001, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject ECUController::staticMetaObject = { {
    QMetaObject::SuperData::link<QGCTool::staticMetaObject>(),
    qt_meta_stringdata_CLASSECUControllerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSECUControllerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSECUControllerENDCLASS_t,
        // property 'vehicleComponents'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // property 'vehicleCkeck'
        QtPrivate::TypeAndForceComplete<QVariantList, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ECUController, std::true_type>,
        // method 'messageReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<LinkInterface *, std::false_type>,
        QtPrivate::TypeAndForceComplete<__message, std::false_type>,
        // method 'dataChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'receiveBytes'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<LinkInterface *, std::false_type>,
        QtPrivate::TypeAndForceComplete<QByteArray, std::false_type>,
        // method 'onTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'init'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startEngine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopEngine'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'flameout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ECUController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ECUController *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->messageReceived((*reinterpret_cast< std::add_pointer_t<LinkInterface*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<__message>>(_a[2]))); break;
        case 1: _t->dataChanged(); break;
        case 2: _t->receiveBytes((*reinterpret_cast< std::add_pointer_t<LinkInterface*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[2]))); break;
        case 3: _t->onTimeout(); break;
        case 4: _t->init(); break;
        case 5: _t->startEngine(); break;
        case 6: _t->stopEngine(); break;
        case 7: _t->flameout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< LinkInterface* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< LinkInterface* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ECUController::*)(LinkInterface * , __message );
            if (_t _q_method = &ECUController::messageReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ECUController::*)();
            if (_t _q_method = &ECUController::dataChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ECUController *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QVariantList*>(_v) = _t->vehicleComponents(); break;
        case 1: *reinterpret_cast< QVariantList*>(_v) = _t->vehicleCkeck(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *ECUController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ECUController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSECUControllerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGCTool::qt_metacast(_clname);
}

int ECUController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGCTool::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void ECUController::messageReceived(LinkInterface * _t1, __message _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ECUController::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
