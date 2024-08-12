project(hello)

add_executable(hello main.cpp)

message("CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")
message("CMAKE_HOME_DIRECTORY=${CMAKE_HOME_DIRECTORY}")
message("CMAKE_CONFIGURATION_TYPES=${CMAKE_CONFIGURATION_TYPES}")

find_package(fmt CONFIG REQUIRED)
target_link_libraries(hello fmt::fmt-header-only)
include_directories(${CMAKE_HOME_DIRECTORY}/src/coost/include)
target_link_libraries(hello co) # coost is co
# INCLUDE_DIRECTORIES("C:\\SDKs\\coost\\include")
# find_library("C:\\SDKs\\coost\\Debug" co)
# target_link_libraries(hello "C:\\SDKs\\coost\\Debug\\co.lib")

set_property(TARGET hello PROPERTY CXX_STANDARD 20)
