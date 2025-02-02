include(C:/Users/varas/OneDrive/Documents/Codes/ECU/second/ParadECU/build/Desktop_Qt_6_6_3_MSVC2019_64bit-Debug/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/ParadECU-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_ALL_MODULES_FOUND_VIA_FIND_PACKAGE "ZlibPrivate;EntryPointPrivate;Core;Network;Bluetooth;Gui;Widgets;OpenGL;OpenGLWidgets;Charts;Concurrent;Core5Compat;Positioning;QmlIntegration;Qml;QmlModels;Quick;PositioningQuick;QuickShapesPrivate;Location;Multimedia;QuickTemplates2;QuickControls2;QuickWidgets;Sensors;Sql;Svg;Test;TextToSpeech;Xml;MultimediaQuickPrivate;Quick3DUtils;ShaderTools;Quick3DRuntimeRender;Quick3D;SerialPort")

qt_deploy_qml_imports(TARGET ParadECU PLUGINS_FOUND plugins_found)
qt_deploy_runtime_dependencies(
    EXECUTABLE C:/Users/varas/OneDrive/Documents/Codes/ECU/second/ParadECU/build/Desktop_Qt_6_6_3_MSVC2019_64bit-Debug/ParadECU.exe
    ADDITIONAL_MODULES ${plugins_found}
    GENERATE_QT_CONF
)