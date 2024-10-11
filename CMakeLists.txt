cmake_minimum_required(VERSION 3.19)
project(my_fuzz)

# Option to add coverage instrumentation
#option(COVERAGE_INSTRUMENTATION "Add coverage instrumentation to generate coverage reports." OFF)
#set(COVERAGE_FLAGS -fprofile-instr-generate -fcoverage-mapping)

#enable testing
enable_testing()

#FuzzTest requires C++ 17
set(CXX_STANDARD 17)

add_subdirectory(third/fuzztest)
#make sure that fuzztest can compile correctly
fuzztest_setup_fuzzing_flags()

#include rapidjson
#include_directories(ENV{HOME}/rapidjson/include)
add_executable(
        my_test
        my_test.cpp
        lib/stringCat.h
        lib/stringCat.h
        # include/rapidjson/writer.h
        # include/rapidjson/stringbuffer.h
        # include/rapidjson/document.h
)


#link fuzztest to the executable
link_fuzztest(my_test)

#make sure gtest knows where to find ?
gtest_discover_tests(my_test)

# 添加rapidjson库. add rapidjson library
#target_include_directories(my_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/rapidjson)