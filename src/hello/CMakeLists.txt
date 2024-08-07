project(hello)

add_executable(hello main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(hello PRIVATE fmt::fmt-header-only)

set_property(TARGET hello PROPERTY CXX_STANDARD 20)
