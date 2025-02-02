/****************************************************************************
** Meta object code from reading C++ file 'LinkManager.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/Comms/LinkManager.h"
#include "QmlObjectListModel.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LinkManager.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSLinkManagerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSLinkManagerENDCLASS = QtMocHelpers::stringData(
    "LinkManager",
    "mavlinkSupportForwardingEnabledChanged",
    "",
    "commPortStringsChanged",
    "commPortsChanged",
    "_linkDisconnected",
    "createConfiguration",
    "LinkConfiguration*",
    "type",
    "name",
    "startConfigurationEditing",
    "config",
    "cancelConfigurationEditing",
    "endConfigurationEditing",
    "editedConfig",
    "endCreateConfiguration",
    "removeConfiguration",
    "createConnectedLink",
    "const LinkConfiguration*",
    "createMavlinkForwardingSupportLink",
    "shutdown",
    "startLogReplay",
    "LogReplayLink*",
    "logFile",
    "linkConfigurations",
    "QmlObjectListModel*",
    "linkTypeStrings",
    "mavlinkSupportForwardingEnabled",
    "serialBaudRates",
    "serialPortStrings",
    "serialPorts"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSLinkManagerENDCLASS_t {
    uint offsetsAndSizes[62];
    char stringdata0[12];
    char stringdata1[39];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[17];
    char stringdata5[18];
    char stringdata6[20];
    char stringdata7[19];
    char stringdata8[5];
    char stringdata9[5];
    char stringdata10[26];
    char stringdata11[7];
    char stringdata12[27];
    char stringdata13[24];
    char stringdata14[13];
    char stringdata15[23];
    char stringdata16[20];
    char stringdata17[20];
    char stringdata18[25];
    char stringdata19[35];
    char stringdata20[9];
    char stringdata21[15];
    char stringdata22[15];
    char stringdata23[8];
    char stringdata24[19];
    char stringdata25[20];
    char stringdata26[16];
    char stringdata27[32];
    char stringdata28[16];
    char stringdata29[18];
    char stringdata30[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSLinkManagerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSLinkManagerENDCLASS_t qt_meta_stringdata_CLASSLinkManagerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "LinkManager"
        QT_MOC_LITERAL(12, 38),  // "mavlinkSupportForwardingEnabl..."
        QT_MOC_LITERAL(51, 0),  // ""
        QT_MOC_LITERAL(52, 22),  // "commPortStringsChanged"
        QT_MOC_LITERAL(75, 16),  // "commPortsChanged"
        QT_MOC_LITERAL(92, 17),  // "_linkDisconnected"
        QT_MOC_LITERAL(110, 19),  // "createConfiguration"
        QT_MOC_LITERAL(130, 18),  // "LinkConfiguration*"
        QT_MOC_LITERAL(149, 4),  // "type"
        QT_MOC_LITERAL(154, 4),  // "name"
        QT_MOC_LITERAL(159, 25),  // "startConfigurationEditing"
        QT_MOC_LITERAL(185, 6),  // "config"
        QT_MOC_LITERAL(192, 26),  // "cancelConfigurationEditing"
        QT_MOC_LITERAL(219, 23),  // "endConfigurationEditing"
        QT_MOC_LITERAL(243, 12),  // "editedConfig"
        QT_MOC_LITERAL(256, 22),  // "endCreateConfiguration"
        QT_MOC_LITERAL(279, 19),  // "removeConfiguration"
        QT_MOC_LITERAL(299, 19),  // "createConnectedLink"
        QT_MOC_LITERAL(319, 24),  // "const LinkConfiguration*"
        QT_MOC_LITERAL(344, 34),  // "createMavlinkForwardingSuppor..."
        QT_MOC_LITERAL(379, 8),  // "shutdown"
        QT_MOC_LITERAL(388, 14),  // "startLogReplay"
        QT_MOC_LITERAL(403, 14),  // "LogReplayLink*"
        QT_MOC_LITERAL(418, 7),  // "logFile"
        QT_MOC_LITERAL(426, 18),  // "linkConfigurations"
        QT_MOC_LITERAL(445, 19),  // "QmlObjectListModel*"
        QT_MOC_LITERAL(465, 15),  // "linkTypeStrings"
        QT_MOC_LITERAL(481, 31),  // "mavlinkSupportForwardingEnabled"
        QT_MOC_LITERAL(513, 15),  // "serialBaudRates"
        QT_MOC_LITERAL(529, 17),  // "serialPortStrings"
        QT_MOC_LITERAL(547, 11)   // "serialPorts"
    },
    "LinkManager",
    "mavlinkSupportForwardingEnabledChanged",
    "",
    "commPortStringsChanged",
    "commPortsChanged",
    "_linkDisconnected",
    "createConfiguration",
    "LinkConfiguration*",
    "type",
    "name",
    "startConfigurationEditing",
    "config",
    "cancelConfigurationEditing",
    "endConfigurationEditing",
    "editedConfig",
    "endCreateConfiguration",
    "removeConfiguration",
    "createConnectedLink",
    "const LinkConfiguration*",
    "createMavlinkForwardingSupportLink",
    "shutdown",
    "startLogReplay",
    "LogReplayLink*",
    "logFile",
    "linkConfigurations",
    "QmlObjectListModel*",
    "linkTypeStrings",
    "mavlinkSupportForwardingEnabled",
    "serialBaudRates",
    "serialPortStrings",
    "serialPorts"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSLinkManagerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       6,  132, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    7 /* Public */,
       3,    0,   99,    2, 0x06,    8 /* Public */,
       4,    0,  100,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,  101,    2, 0x08,   10 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       6,    2,  102,    2, 0x02,   11 /* Public */,
      10,    1,  107,    2, 0x02,   14 /* Public */,
      12,    1,  110,    2, 0x102,   16 /* Public | MethodIsConst  */,
      13,    2,  113,    2, 0x02,   18 /* Public */,
      15,    1,  118,    2, 0x02,   21 /* Public */,
      16,    1,  121,    2, 0x02,   23 /* Public */,
      17,    1,  124,    2, 0x02,   25 /* Public */,
      19,    0,  127,    2, 0x02,   27 /* Public */,
      20,    0,  128,    2, 0x02,   28 /* Public */,
      21,    1,  129,    2, 0x02,   29 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    0x80000000 | 7, QMetaType::Int, QMetaType::QString,    8,    9,
    0x80000000 | 7, 0x80000000 | 7,   11,
    QMetaType::Void, 0x80000000 | 7,   11,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 7,   11,   14,
    QMetaType::Void, 0x80000000 | 7,   11,
    QMetaType::Void, 0x80000000 | 7,   11,
    QMetaType::Void, 0x80000000 | 18,   11,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 22, QMetaType::QString,   23,

 // properties: name, type, flags
      24, 0x80000000 | 25, 0x00015409, uint(-1), 0,
      26, QMetaType::QStringList, 0x00015401, uint(-1), 0,
      27, QMetaType::Bool, 0x00015001, uint(0), 0,
      28, QMetaType::QStringList, 0x00015401, uint(-1), 0,
      29, QMetaType::QStringList, 0x00015001, uint(1), 0,
      30, QMetaType::QStringList, 0x00015001, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject LinkManager::staticMetaObject = { {
    QMetaObject::SuperData::link<QGCTool::staticMetaObject>(),
    qt_meta_stringdata_CLASSLinkManagerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSLinkManagerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSLinkManagerENDCLASS_t,
        // property 'linkConfigurations'
        QtPrivate::TypeAndForceComplete<QmlObjectListModel*, std::true_type>,
        // property 'linkTypeStrings'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // property 'mavlinkSupportForwardingEnabled'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'serialBaudRates'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // property 'serialPortStrings'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // property 'serialPorts'
        QtPrivate::TypeAndForceComplete<QStringList, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<LinkManager, std::true_type>,
        // method 'mavlinkSupportForwardingEnabledChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'commPortStringsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'commPortsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method '_linkDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createConfiguration'
        QtPrivate::TypeAndForceComplete<LinkConfiguration *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'startConfigurationEditing'
        QtPrivate::TypeAndForceComplete<LinkConfiguration *, std::false_type>,
        QtPrivate::TypeAndForceComplete<LinkConfiguration *, std::false_type>,
        // method 'cancelConfigurationEditing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<LinkConfiguration *, std::false_type>,
        // method 'endConfigurationEditing'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<LinkConfiguration *, std::false_type>,
        QtPrivate::TypeAndForceComplete<LinkConfiguration *, std::false_type>,
        // method 'endCreateConfiguration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<LinkConfiguration *, std::false_type>,
        // method 'removeConfiguration'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<LinkConfiguration *, std::false_type>,
        // method 'createConnectedLink'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const LinkConfiguration *, std::false_type>,
        // method 'createMavlinkForwardingSupportLink'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'shutdown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startLogReplay'
        QtPrivate::TypeAndForceComplete<LogReplayLink *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void LinkManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LinkManager *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mavlinkSupportForwardingEnabledChanged(); break;
        case 1: _t->commPortStringsChanged(); break;
        case 2: _t->commPortsChanged(); break;
        case 3: _t->_linkDisconnected(); break;
        case 4: { LinkConfiguration* _r = _t->createConfiguration((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< LinkConfiguration**>(_a[0]) = std::move(_r); }  break;
        case 5: { LinkConfiguration* _r = _t->startConfigurationEditing((*reinterpret_cast< std::add_pointer_t<LinkConfiguration*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< LinkConfiguration**>(_a[0]) = std::move(_r); }  break;
        case 6: _t->cancelConfigurationEditing((*reinterpret_cast< std::add_pointer_t<LinkConfiguration*>>(_a[1]))); break;
        case 7: _t->endConfigurationEditing((*reinterpret_cast< std::add_pointer_t<LinkConfiguration*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<LinkConfiguration*>>(_a[2]))); break;
        case 8: _t->endCreateConfiguration((*reinterpret_cast< std::add_pointer_t<LinkConfiguration*>>(_a[1]))); break;
        case 9: _t->removeConfiguration((*reinterpret_cast< std::add_pointer_t<LinkConfiguration*>>(_a[1]))); break;
        case 10: _t->createConnectedLink((*reinterpret_cast< std::add_pointer_t<const LinkConfiguration*>>(_a[1]))); break;
        case 11: _t->createMavlinkForwardingSupportLink(); break;
        case 12: _t->shutdown(); break;
        case 13: { LogReplayLink* _r = _t->startLogReplay((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< LogReplayLink**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< LinkConfiguration* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< LinkConfiguration* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< LinkConfiguration* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< LinkConfiguration* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< LinkConfiguration* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LinkManager::*)();
            if (_t _q_method = &LinkManager::mavlinkSupportForwardingEnabledChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LinkManager::*)();
            if (_t _q_method = &LinkManager::commPortStringsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LinkManager::*)();
            if (_t _q_method = &LinkManager::commPortsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<LinkManager *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QmlObjectListModel**>(_v) = _t->_qmlLinkConfigurations(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = _t->linkTypeStrings(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->mavlinkSupportForwardingEnabled(); break;
        case 3: *reinterpret_cast< QStringList*>(_v) = _t->serialBaudRates(); break;
        case 4: *reinterpret_cast< QStringList*>(_v) = _t->serialPortStrings(); break;
        case 5: *reinterpret_cast< QStringList*>(_v) = _t->serialPorts(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *LinkManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LinkManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSLinkManagerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGCTool::qt_metacast(_clname);
}

int LinkManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGCTool::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void LinkManager::mavlinkSupportForwardingEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LinkManager::commPortStringsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LinkManager::commPortsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
