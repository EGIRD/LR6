cmake_minimum_required(VERSION 3.27)
project(tests)

set(CMAKE_CXX_STANDARD 20)

include(CTest)
add_subdirectory(gtest)
if(BUILD_TESTING)
    add_executable(main test.cpp)
    target_link_libraries(main PRIVATE GTest::gtest_main)
    include(GoogleTest)
    gtest_discover_tests(main)
endif()
