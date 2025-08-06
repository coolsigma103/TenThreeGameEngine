cmake_minimum_required(VERSION 4.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(INC "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(LIB "${CMAKE_CURRENT_SOURCE_DIR}/lib")
 
project(MyProject)

add_library(glad "${LIB}/glad.c")
target_include_directories(glad PRIVATE ${INC})

add_subdirectory("${CMAKE_SOURCE_DIR}/103GE-RenderEngine")
add_subdirectory("${CMAKE_SOURCE_DIR}/103GE")

add_executable(${PROJECT_NAME}
        ${CORE_SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE ${INC} ${RE_INCLUDE})
target_link_libraries(${PROJECT_NAME} glad render)