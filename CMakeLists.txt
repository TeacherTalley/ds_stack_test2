cmake_minimum_required(VERSION 3.14)
project(ds_stack_test)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#link_directories("/usr/local/lib")

#find_package(GTest REQUIRED)
#message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_executable(
  main
  main.cpp 
)

add_executable(
  tests
  tests.cpp 
)

target_link_libraries(
  tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
