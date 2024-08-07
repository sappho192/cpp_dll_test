project(hello_library)

add_library(hello_library SHARED main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(hello_library PRIVATE fmt::fmt-header-only)

set_property(TARGET hello_library PROPERTY CXX_STANDARD 20)
