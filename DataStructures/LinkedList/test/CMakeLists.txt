cmake_minimum_required(version 3.5)

set(TEST_PROJECT_NAME LinkedListTests)
set(LIBRARY_TESTS_SOURCE linkedlisttests.cpp)

project(${TEST_PROJECT_NAME})

find_package(PkgConfig)
pkg_check_modules(GTEST "gtest" REQUIRED)
message(STATUS "gtest found: " ${GTEST_FOUND})

enable_testing()

add_executable(${TEST_PROJECT_NAME} ${LIBRARY_TESTS_SOURCE})

target_link_libraries(${TEST_PROJECT_NAME} ${GTEST_LIBRARIES} ${LIBRARY_NAME})

include(GoogleTest)
gtest_discover_tests(${TEST_PROJECT_NAME})
add_test(${TEST_PROJECT_NAME} ${TEST_PROJECT_NAME})
