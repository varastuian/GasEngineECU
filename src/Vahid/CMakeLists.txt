find_package(Qt6 REQUIRED COMPONENTS Quick Core Gui Positioning)

qt_add_library(Vahid STATIC
    ImageFootprintCalculator.h ImageFootprintCalculator.cc
    gimbaltcp.h gimbaltcp.cpp
    ecucontroller.h ecucontroller.cpp
)

target_link_libraries(Vahid
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Quick
        Qt6::Positioning
    PUBLIC
        QGC
        Comms
)

target_include_directories(Vahid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
