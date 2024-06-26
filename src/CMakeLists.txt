cmake_minimum_required(VERSION 3.5)

project(Ivs_Calculator VERSION 0.1 LANGUAGES CXX)



include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)


add_subdirectory(mathlib)
add_subdirectory(profiler)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Svg SvgWidgets Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Svg SvgWidgets Multimedia)

file(GLOB SOURCES *.cpp *.h *.ui)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(E-Calculator
        MANUAL_FINALIZATION
        ${SOURCES}

        about.h about.cpp about.ui
        svgbutton.h svgbutton.cpp
        Resources.qrc
    )
else()
    add_executable(E-Calculator
        ${SOURCES}
    )
endif()

target_link_libraries(E-Calculator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt6::Svg Qt6::SvgWidgets Qt6::Multimedia)
target_include_directories(E-Calculator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(E-Calculator PROPERTIES
    ${BUNDLE_ID_OPTION}
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS E-Calculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT E-Calculator
)
install(DIRECTORY "../doc/" DESTINATION ${CMAKE_INSTALL_DATADIR}/E-Calculator/ COMPONENT E-Calculator)
install(FILES "../LICENSE" DESTINATION ${CMAKE_INSTALL_DATADIR}/E-Calculator/ COMPONENT E-Calculator)
install(FILES "../user_guide/user_guide.pdf" DESTINATION ${CMAKE_INSTALL_DATADIR}/E-Calculator/ COMPONENT E-Calculator)
if(UNIX AND NOT APPLE)
    install(FILES "./E-Calculator.desktop" DESTINATION "share/applications" COMPONENT E-Calculator)
    install(FILES "./svgs/EEEE_logo.svg" DESTINATION "share/icons/hicolor/scalable/apps" COMPONENT E-Calculator)
endif()

message(${CMAKE_INSTALL_DATADIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(E-Calculator)
endif()

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Team EEEEE")
set(CPACK_PACKAGE_NAME "Ivs-Calculator")
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MAJOR 1)
set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_COMPONENTS_ALL E-Calculator Profiler)
set(CPACK_PACKAGE_DESCRIPTION "IVSCalculator from Team EEEEE")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt6core6, libqt6gui6, libqt6core5compat6, libqt6widgets6, qt6-qpa-plugins, libqt6multimedia6, libqt6svg6, libqt6svgwidgets6")

file(GLOB MATHENGINE_TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/math_engine.cpp" 
"${CMAKE_CURRENT_SOURCE_DIR}/math_engine.h"
"${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp"
 "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.h")
add_executable(
    MathEngine_test
    ${MATHENGINE_TEST_SOURCES}
)
target_include_directories(MathEngine_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(
    MathEngine_test
    GTest::gtest_main
    MathLib
)

gtest_discover_tests(MathEngine_test)


target_link_libraries(E-Calculator PRIVATE MathLib)
include(CPack)

cpack_add_component(E-Calculator DISPLAY_NAME "E-Calculator")
