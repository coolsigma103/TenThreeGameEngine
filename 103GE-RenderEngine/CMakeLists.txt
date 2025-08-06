cmake_minimum_required(VERSION 3.10)
project(103GE-GameEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

file(GLOB_RECURSE SRC_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.c"
)

add_library(render STATIC ${SRC_FILES})
target_include_directories(render PRIVATE "${CMAKE_SOURCE_DIR}/include")
target_link_directories(render PRIVATE "${CMAKE_SOURCE_DIR}/lib")
#import glfw
find_package(glfw3 REQUIRED)
#import glad
add_library(glad "${CMAKE_SOURCE_DIR}/lib/glad.c")
target_include_directories(glad PRIVATE "${CMAKE_SOURCE_DIR}/include")
#import stb
add_library(stb "${CMAKE_SOURCE_DIR}/lib/stb.c")
target_include_directories(stb PRIVATE "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(render glad glfw3 stb)