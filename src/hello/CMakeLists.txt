project(hello)

add_executable(hello main.cpp)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(hello fmt::fmt-header-only)
INCLUDE_DIRECTORIES("C:\\SDKs\\coost\\include")
find_library("C:\\SDKs\\coost\\Debug" co)
target_link_libraries(hello "C:\\SDKs\\coost\\Debug\\co.lib")

set_property(TARGET hello PROPERTY CXX_STANDARD 20)
