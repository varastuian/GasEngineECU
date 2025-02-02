/****************************************************************************
** Meta object code from reading C++ file 'QGCCorePlugin.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/API/QGCCorePlugin.h"
#include "QmlObjectListModel.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QGCCorePlugin.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQGCCorePluginENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSQGCCorePluginENDCLASS = QtMocHelpers::stringData(
    "QGCCorePlugin",
    "analyzePagesChanged",
    "",
    "showTouchAreasChanged",
    "showTouchAreas",
    "showAdvancedUIChanged",
    "showAdvancedUI",
    "toolBarIndicatorsChanged"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQGCCorePluginENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[14];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[15];
    char stringdata5[22];
    char stringdata6[15];
    char stringdata7[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQGCCorePluginENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQGCCorePluginENDCLASS_t qt_meta_stringdata_CLASSQGCCorePluginENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "QGCCorePlugin"
        QT_MOC_LITERAL(14, 19),  // "analyzePagesChanged"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 21),  // "showTouchAreasChanged"
        QT_MOC_LITERAL(57, 14),  // "showTouchAreas"
        QT_MOC_LITERAL(72, 21),  // "showAdvancedUIChanged"
        QT_MOC_LITERAL(94, 14),  // "showAdvancedUI"
        QT_MOC_LITERAL(109, 24)   // "toolBarIndicatorsChanged"
    },
    "QGCCorePlugin",
    "analyzePagesChanged",
    "",
    "showTouchAreasChanged",
    "showTouchAreas",
    "showAdvancedUIChanged",
    "showAdvancedUI",
    "toolBarIndicatorsChanged"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQGCCorePluginENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       2,   46, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    3 /* Public */,
       3,    1,   39,    2, 0x06,    4 /* Public */,
       5,    1,   42,    2, 0x06,    6 /* Public */,
       7,    0,   45,    2, 0x06,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,

 // properties: name, type, flags
       4, QMetaType::Bool, 0x00015103, uint(1), 0,
       6, QMetaType::Bool, 0x00015103, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject QGCCorePlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<QGCTool::staticMetaObject>(),
    qt_meta_stringdata_CLASSQGCCorePluginENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQGCCorePluginENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQGCCorePluginENDCLASS_t,
        // property 'showTouchAreas'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'showAdvancedUI'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QGCCorePlugin, std::true_type>,
        // method 'analyzePagesChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showTouchAreasChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'showAdvancedUIChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'toolBarIndicatorsChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void QGCCorePlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QGCCorePlugin *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->analyzePagesChanged(); break;
        case 1: _t->showTouchAreasChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 2: _t->showAdvancedUIChanged((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->toolBarIndicatorsChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QGCCorePlugin::*)();
            if (_t _q_method = &QGCCorePlugin::analyzePagesChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QGCCorePlugin::*)(bool );
            if (_t _q_method = &QGCCorePlugin::showTouchAreasChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QGCCorePlugin::*)(bool );
            if (_t _q_method = &QGCCorePlugin::showAdvancedUIChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QGCCorePlugin::*)();
            if (_t _q_method = &QGCCorePlugin::toolBarIndicatorsChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QGCCorePlugin *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->showTouchAreas(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->showAdvancedUI(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QGCCorePlugin *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setShowTouchAreas(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setShowAdvancedUI(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *QGCCorePlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGCCorePlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQGCCorePluginENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGCTool::qt_metacast(_clname);
}

int QGCCorePlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGCTool::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QGCCorePlugin::analyzePagesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QGCCorePlugin::showTouchAreasChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QGCCorePlugin::showAdvancedUIChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QGCCorePlugin::toolBarIndicatorsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
