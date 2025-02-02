#include "ScreenToolsController.h"
#include "QGCApplication.h"
#include <QtGui/QFontDatabase>
#include <QtGui/QFontMetrics>
#include <QtGui/QInputDevice>

// #include "SettingsManager.h"

// #if defined(Q_OS_IOS)
// #include <sys/utsname.h>
// #endif

ScreenToolsController::ScreenToolsController()
{

}

bool
ScreenToolsController::hasTouch() const
{
    for (const auto& inputDevice: QInputDevice::devices()) {
        if (inputDevice->type() == QInputDevice::DeviceType::TouchScreen) {
            return true;
        }
    }
    return false;
}

QString
ScreenToolsController::iOSDevice() const
{
#if defined(Q_OS_IOS)
    struct utsname systemInfo;
    uname(&systemInfo);
    return QString(systemInfo.machine);
#else
    return QString();
#endif
}

QString
ScreenToolsController::fixedFontFamily() const
{
    return QFontDatabase::systemFont(QFontDatabase::FixedFont).family();
}

QString
ScreenToolsController::normalFontFamily() const
{
    //-- See App.SettinsGroup.json for index
    // int langID = qgcApp()->toolbox()->settingsManager()->appSettings()->qLocaleLanguage()->rawValue().toInt();
    // if(langID == QLocale::Korean) {
    //     return QString("NanumGothic");
    // } else {
        return QString("Open Sans");
    // }
}

double ScreenToolsController::defaultFontDescent(int pointSize) const
{
    return QFontMetrics(QFont(normalFontFamily(), pointSize)).descent();
}

#ifndef __mobile__
bool ScreenToolsController::fakeMobile() const { return qgcApp()->fakeMobile(); }
#endif
