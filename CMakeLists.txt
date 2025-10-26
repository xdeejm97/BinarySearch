cmake_minimum_required(VERSION 3.11.0)
project(stack VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare( 
   googletest
   GIT_REPOSITORY      https://github.com/google/googletest.git
   GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

set(BINARY_SEARCH_LIB_SOURCES BinarySearchLib/BinarySearch.h BinarySearchLib/BinarySearch.cpp)
set(BINARY_SEARCH_APP_SOURCES BinarySearchApp/BinarySearchApp.cpp BinarySearchApp/benchmark.h )
set(BINARY_SEARCH_TESTS_SOURCES BinarySearchUnitTest/BinarySearchUnitTest.cpp BinarySearchUnitTest/TrivialSearchUnitTest.cpp)

enable_testing()
add_executable(BinarySearchApp ${BINARY_SEARCH_APP_SOURCES} ${BINARY_SEARCH_LIB_SOURCES} )
add_executable(BinarySearchTests ${BINARY_SEARCH_TESTS_SOURCES} ${BINARY_SEARCH_LIB_SOURCES})
target_link_libraries(BinarySearchTests GTest::gtest_main)

include(CTest)
include(GoogleTest)
gtest_discover_tests(BinarySearchTests)