add_library(core
    daemon.c
    fast_log.c
    fast_log_types.c
    glitch_log.c
    log_config.c
    pid_file.c
    signal.c
)
target_link_libraries(core jorm util pthread)

add_executable(fast_log_unit fast_log_unit.c)
target_link_libraries(fast_log_unit core utest)
add_test(fast_log_unit ${CMAKE_CURRENT_BINARY_DIR}/fast_log_unit fast_log_unit)

add_executable(glitch_log_unit glitch_log_unit.c)
target_link_libraries(glitch_log_unit core utest)
add_test(glitch_log_unit ${CMAKE_CURRENT_BINARY_DIR}/glitch_log_unit glitch_log_unit)

add_executable(signal_unit signal_unit.c)
target_link_libraries(signal_unit core utest)
add_test(signal_unit ${CMAKE_CURRENT_BINARY_DIR}/signal_unit signal_unit)
