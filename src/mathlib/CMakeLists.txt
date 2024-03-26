cmake_minimum_required(VERSION 3.5)

file(GLOB MATHLIB_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file(GLOB MATHLIB_TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp" "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.h")

add_library(MathLib ${MATHLIB_SOURCES})
target_include_directories(MathLib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(
    MathLib_test
    ${MATHLIB_TEST_SOURCES}
)
target_link_libraries(
    MathLib_test
    GTest::gtest_main
    MathLib
)

gtest_discover_tests(MathLib_test)
