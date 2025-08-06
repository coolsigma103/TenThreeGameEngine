cmake_minimum_required(VERSION 3.10)
project(103GE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

file(GLOB_RECURSE SRC_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.c"
)


add_executable(${PROJECT_NAME} ${SRC_FILES})


target_include_directories(${PROJECT_NAME} PUBLIC
    "${CMAKE_SOURCE_DIR}/include"
)

link_directories(${CMAKE_SOURCE_DIR}/lib)

find_package(glfw3 3.4 REQUIRED)

add_library(glad STATIC "${CMAKE_SOURCE_DIR}/lib/glad.c")
add_library(stb STATIC "${CMAKE_SOURCE_DIR}/lib/stb.c")
target_include_directories(glad PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_include_directories(stb PUBLIC "${CMAKE_SOURCE_DIR}/include")
target_link_libraries(${PROJECT_NAME} glad stb glfw)