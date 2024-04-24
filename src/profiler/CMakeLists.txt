
file(GLOB STDDEV_SOURCES "./*.cpp" "./*.h")
add_executable(stddev ${STDDEV_SOURCES})
target_include_directories(stddev PRIVATE .)
target_link_libraries(stddev PRIVATE MathLib)

include(GNUInstallDirs)
install(TARGETS stddev
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    COMPONENT Profiler
)