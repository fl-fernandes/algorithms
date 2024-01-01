cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  circular_linked_list_test
  data-structures/circular_linked_list_test.h
  data-structures/circular_linked_list_test.cpp
)
target_link_libraries(
  circular_linked_list_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(circular_linked_list_test)