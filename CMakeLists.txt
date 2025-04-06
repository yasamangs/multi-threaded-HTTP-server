cmake_minimum_required(VERSION 3.10)

project(HTTPServer)

set(CMAKE_CXX_STANDARD 17)

# Find Boost
find_package(Boost 1.70 REQUIRED COMPONENTS system thread)

# Specify where the Boost headers are located
include_directories(${Boost_INCLUDE_DIRS})

# Add the source files
add_executable(server src/server.cpp)

# Link Boost libraries correctly
target_link_libraries(server ${Boost_LIBRARIES} pthread)