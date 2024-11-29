project(foo_test)

include(googletest)

enable_testing()

file(GLOB_RECURSE TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/*_test.cpp)

foreach(SRC ${TEST_SRC})

    get_filename_component(TEST_NAME ${SRC} NAME_WE)

    add_executable(${TEST_NAME} ${SRC})

    target_link_libraries(${TEST_NAME}
        PRIVATE foo GTest::gtest_main)

    gtest_discover_tests(${TEST_NAME})

    add_custom_command(TARGET ${TEST_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:${TEST_NAME}> $<TARGET_FILE_DIR:${TEST_NAME}>
    )

endforeach()
