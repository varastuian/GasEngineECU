/****************************************************************************
** Meta object code from reading C++ file 'QGCLoggingCategory.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../src/Utilities/QGCLoggingCategory.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QGCLoggingCategory.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSQGCLoggingCategoryRegisterENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSQGCLoggingCategoryRegisterENDCLASS = QtMocHelpers::stringData(
    "QGCLoggingCategoryRegister",
    "registeredCategories",
    "",
    "setCategoryLoggingOn",
    "category",
    "enable",
    "categoryLoggingOn"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSQGCLoggingCategoryRegisterENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[27];
    char stringdata1[21];
    char stringdata2[1];
    char stringdata3[21];
    char stringdata4[9];
    char stringdata5[7];
    char stringdata6[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSQGCLoggingCategoryRegisterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSQGCLoggingCategoryRegisterENDCLASS_t qt_meta_stringdata_CLASSQGCLoggingCategoryRegisterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 26),  // "QGCLoggingCategoryRegister"
        QT_MOC_LITERAL(27, 20),  // "registeredCategories"
        QT_MOC_LITERAL(48, 0),  // ""
        QT_MOC_LITERAL(49, 20),  // "setCategoryLoggingOn"
        QT_MOC_LITERAL(70, 8),  // "category"
        QT_MOC_LITERAL(79, 6),  // "enable"
        QT_MOC_LITERAL(86, 17)   // "categoryLoggingOn"
    },
    "QGCLoggingCategoryRegister",
    "registeredCategories",
    "",
    "setCategoryLoggingOn",
    "category",
    "enable",
    "categoryLoggingOn"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSQGCLoggingCategoryRegisterENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x02,    1 /* Public */,
       3,    2,   33,    2, 0x02,    2 /* Public */,
       6,    1,   38,    2, 0x02,    5 /* Public */,

 // methods: parameters
    QMetaType::QStringList,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    4,    5,
    QMetaType::Bool, QMetaType::QString,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject QGCLoggingCategoryRegister::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSQGCLoggingCategoryRegisterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSQGCLoggingCategoryRegisterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSQGCLoggingCategoryRegisterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<QGCLoggingCategoryRegister, std::true_type>,
        // method 'registeredCategories'
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'setCategoryLoggingOn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'categoryLoggingOn'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void QGCLoggingCategoryRegister::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QGCLoggingCategoryRegister *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QStringList _r = _t->registeredCategories();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->setCategoryLoggingOn((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 2: { bool _r = _t->categoryLoggingOn((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *QGCLoggingCategoryRegister::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGCLoggingCategoryRegister::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSQGCLoggingCategoryRegisterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGCLoggingCategoryRegister::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
