# personal_fuzztest
a repo contains several tests using google/fuzztest

# Prerequisites

To use FuzzTest, you'll need:

- A Linux-based operating system.
- [Clang](https://clang.llvm.org/). GCC is not yet supported. Unittest mode mode should work but it's not yet tested.
- [CMake](https://https//cmake.org/).

check https://github.com/google/fuzztest/blob/main/doc/quickstart-cmake.md for original reference.
# How to use

```shell
git clone https://github.com/yMsquare/personal_fuzztest.git
cd my_fuzz

# create dir build
mkdir build && cd build

# generating CMakeLists
CC=clang CXX=clang++ cmake -DCMAKE_BUILD_TYPE=RelWithDebug -DFUZZTEST_FUZZING_MODE=on ..

# compile
# this may take a long period of time
cmake --build .

# run the tests
# run all unit tests
./my_fuzz

# run fuzz test
#./my_fuzz --fuzz=<TestSuiteName>.<TestName>
./my_fuzz --fuzz=StringTest.TestCatString
```

# Errors

```shell	
[ 96%] Linking CXX executable antlr4_tests
CMake Error at /usr/share/cmake-3.22/Modules/GoogleTestAddTests.cmake:83 (message):
  Error running test executable.

    Path: '.../fuzz/personal_fuzztest/build/_deps/antlr_cpp-build/runtime/antlr4_tests'
    Result: Process terminated due to timeout
    Output:
Call Stack (most recent call first):
  /usr/share/cmake-3.22/Modules/GoogleTestAddTests.cmake:179 (gtest_discover_tests_impl)

```

solution: try `cmake --build .`again until it is successfully compiled.
