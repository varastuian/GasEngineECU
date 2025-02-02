/****************************************************************************
** Meta object code from reading C++ file 'QGroundControlQmlGlobal.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/QmlControls/QGroundControlQmlGlobal.h"
#include "LinkManager.h"
#include "QGCCorePlugin.h"
#include "QGCPalette.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QGroundControlQmlGlobal.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQGroundControlQmlGlobalENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSQGroundControlQmlGlobalENDCLASS = QtMocHelpers::stringData(
    "QGroundControlQmlGlobal",
    "appName",
    "linkManager",
    "LinkManager*",
    "corePlugin",
    "QGCCorePlugin*",
    "globalPalette",
    "QGCPalette*",
    "qgcVersion",
    "zOrderTopMost",
    "zOrderWidgets",
    "zOrderMapItems",
    "zOrderVehicles",
    "zOrderWaypointIndicators",
    "zOrderTrajectoryLines",
    "zOrderWaypointLines"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQGroundControlQmlGlobalENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[24];
    char stringdata1[8];
    char stringdata2[12];
    char stringdata3[13];
    char stringdata4[11];
    char stringdata5[15];
    char stringdata6[14];
    char stringdata7[12];
    char stringdata8[11];
    char stringdata9[14];
    char stringdata10[14];
    char stringdata11[15];
    char stringdata12[15];
    char stringdata13[25];
    char stringdata14[22];
    char stringdata15[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQGroundControlQmlGlobalENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQGroundControlQmlGlobalENDCLASS_t qt_meta_stringdata_CLASSQGroundControlQmlGlobalENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23),  // "QGroundControlQmlGlobal"
        QT_MOC_LITERAL(24, 7),  // "appName"
        QT_MOC_LITERAL(32, 11),  // "linkManager"
        QT_MOC_LITERAL(44, 12),  // "LinkManager*"
        QT_MOC_LITERAL(57, 10),  // "corePlugin"
        QT_MOC_LITERAL(68, 14),  // "QGCCorePlugin*"
        QT_MOC_LITERAL(83, 13),  // "globalPalette"
        QT_MOC_LITERAL(97, 11),  // "QGCPalette*"
        QT_MOC_LITERAL(109, 10),  // "qgcVersion"
        QT_MOC_LITERAL(120, 13),  // "zOrderTopMost"
        QT_MOC_LITERAL(134, 13),  // "zOrderWidgets"
        QT_MOC_LITERAL(148, 14),  // "zOrderMapItems"
        QT_MOC_LITERAL(163, 14),  // "zOrderVehicles"
        QT_MOC_LITERAL(178, 24),  // "zOrderWaypointIndicators"
        QT_MOC_LITERAL(203, 21),  // "zOrderTrajectoryLines"
        QT_MOC_LITERAL(225, 19)   // "zOrderWaypointLines"
    },
    "QGroundControlQmlGlobal",
    "appName",
    "linkManager",
    "LinkManager*",
    "corePlugin",
    "QGCCorePlugin*",
    "globalPalette",
    "QGCPalette*",
    "qgcVersion",
    "zOrderTopMost",
    "zOrderWidgets",
    "zOrderMapItems",
    "zOrderVehicles",
    "zOrderWaypointIndicators",
    "zOrderTrajectoryLines",
    "zOrderWaypointLines"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQGroundControlQmlGlobalENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      12,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00015401, uint(-1), 0,
       2, 0x80000000 | 3, 0x00015409, uint(-1), 0,
       4, 0x80000000 | 5, 0x00015409, uint(-1), 0,
       6, 0x80000000 | 7, 0x00015409, uint(-1), 0,
       8, QMetaType::QString, 0x00015401, uint(-1), 0,
       9, QMetaType::QReal, 0x00015401, uint(-1), 0,
      10, QMetaType::QReal, 0x00015401, uint(-1), 0,
      11, QMetaType::QReal, 0x00015401, uint(-1), 0,
      12, QMetaType::QReal, 0x00015401, uint(-1), 0,
      13, QMetaType::QReal, 0x00015401, uint(-1), 0,
      14, QMetaType::QReal, 0x00015401, uint(-1), 0,
      15, QMetaType::QReal, 0x00015401, uint(-1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QGroundControlQmlGlobal::staticMetaObject = { {
    QMetaObject::SuperData::link<QGCTool::staticMetaObject>(),
    qt_meta_stringdata_CLASSQGroundControlQmlGlobalENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQGroundControlQmlGlobalENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQGroundControlQmlGlobalENDCLASS_t,
        // property 'appName'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'linkManager'
        QtPrivate::TypeAndForceComplete<LinkManager*, std::true_type>,
        // property 'corePlugin'
        QtPrivate::TypeAndForceComplete<QGCCorePlugin*, std::true_type>,
        // property 'globalPalette'
        QtPrivate::TypeAndForceComplete<QGCPalette*, std::true_type>,
        // property 'qgcVersion'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'zOrderTopMost'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'zOrderWidgets'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'zOrderMapItems'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'zOrderVehicles'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'zOrderWaypointIndicators'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'zOrderTrajectoryLines'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // property 'zOrderWaypointLines'
        QtPrivate::TypeAndForceComplete<qreal, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QGroundControlQmlGlobal, std::true_type>
    >,
    nullptr
} };

void QGroundControlQmlGlobal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QGroundControlQmlGlobal *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->appName(); break;
        case 1: *reinterpret_cast< LinkManager**>(_v) = _t->linkManager(); break;
        case 2: *reinterpret_cast< QGCCorePlugin**>(_v) = _t->corePlugin(); break;
        case 3: *reinterpret_cast< QGCPalette**>(_v) = _t->_globalPalette; break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->qgcVersion(); break;
        case 5: *reinterpret_cast< qreal*>(_v) = _t->zOrderTopMost(); break;
        case 6: *reinterpret_cast< qreal*>(_v) = _t->zOrderWidgets(); break;
        case 7: *reinterpret_cast< qreal*>(_v) = _t->zOrderMapItems(); break;
        case 8: *reinterpret_cast< qreal*>(_v) = _t->zOrderVehicles(); break;
        case 9: *reinterpret_cast< qreal*>(_v) = _t->zOrderWaypointIndicators(); break;
        case 10: *reinterpret_cast< qreal*>(_v) = _t->zOrderTrajectoryLines(); break;
        case 11: *reinterpret_cast< qreal*>(_v) = _t->zOrderWaypointLines(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *QGroundControlQmlGlobal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGroundControlQmlGlobal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQGroundControlQmlGlobalENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGCTool::qt_metacast(_clname);
}

int QGroundControlQmlGlobal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGCTool::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
