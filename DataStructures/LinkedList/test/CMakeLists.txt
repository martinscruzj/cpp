cmake_minimum_required(VERSION 3.14)

set(TEST_PROJECT_NAME LinkedListTests)
set(RUNNABLE_TESTS linkedlisttests)
set(LIBRARY_TESTS_SOURCE
   linkedlisttests.cpp)

project(${TEST_PROJECT_NAME})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL http://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${RUNNABLE_TESTS}
   ${LIBRARY_TESTS_SOURCE})
target_link_libraries(${RUNNABLE_TESTS}
   gtest_main
   ${LIBRARY_NAME})

include(GoogleTest)
gtest_discover_tests(${RUNNABLE_TESTS})
