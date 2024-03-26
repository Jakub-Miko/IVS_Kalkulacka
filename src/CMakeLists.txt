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

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

file(GLOB SOURCES *.cpp *.h *.ui)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Ivs_Calculator
        MANUAL_FINALIZATION
        ${SOURCES}
    )
else()
    add_executable(Ivs_Calculator
        ${SOURCES}
    )
endif()

target_link_libraries(Ivs_Calculator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Ivs_Calculator PROPERTIES
    ${BUNDLE_ID_OPTION}
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Ivs_Calculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Ivs_Calculator)
endif()

add_subdirectory(mathlib)
