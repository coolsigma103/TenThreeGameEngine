cmake_minimum_required(VERSION 3.16)

project(TenThreeGameEngine VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_subdirectory(external)

file(GLOB_RECURSE TEN_THREE_SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${TEN_THREE_SOURCES})

target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad stb_impl glm argparse jsoncpp_lib)
target_include_directories(${PROJECT_NAME} PRIVATE src external)
