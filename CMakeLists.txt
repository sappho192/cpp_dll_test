# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(cpp_template)

# Find dependencies provided by vcpkg (via vcpkg.cmake)
find_package(fmt CONFIG REQUIRED)

# main target
add_subdirectory(src/coost coost)
add_subdirectory(src/hello hello)
add_subdirectory(src/hello_library hello_library)

enable_testing()
# tests target
add_executable(tests)
target_sources(tests PRIVATE src/test.cpp)
target_link_libraries(tests PRIVATE fmt::fmt-header-only)
set_property(TARGET tests PROPERTY CXX_STANDARD 20)
add_test(tests tests)
