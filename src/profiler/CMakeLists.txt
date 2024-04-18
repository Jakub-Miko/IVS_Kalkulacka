
file(GLOB STDDEV_SOURCES "./*.cpp" "./*.h")
add_executable(stddev ${STDDEV_SOURCES})
target_include_directories(stddev PRIVATE .)
target_link_libraries(stddev PRIVATE MathLib)