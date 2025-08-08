cmake_minimum_required(VERSION 4.0)
#set standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set some path
set(INC "${CMAKE_CURRENT_SOURCE_DIR}/include") #add a lib and include in the repo root
set(LIB "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(EobCS "${CMAKE_CURRENT_SOURCE_DIR}/EobCS/EobCS.hpp")
 
project(103GE)

#add subdir
add_subdirectory("${CMAKE_SOURCE_DIR}/103GE-RenderEngine")
add_subdirectory("${CMAKE_SOURCE_DIR}/103GE")
add_subdirectory("${CMAKE_SOURCE_DIR}/imgui") #remember to add the dear-imgui source and glfw/opengl3 backend to /imgui folder("docking" branch)

#add glfw3 library
find_package(glfw3 REQUIRED)

#add glad libray
add_library(glad "${LIB}/glad.c")
target_include_directories(glad PRIVATE ${INC})

#add JNI library(for scripting)
find_package(Java REQUIRED)
find_package(JNI REQUIRED)

#executable
add_executable(${PROJECT_NAME}
        ${CORE_SOURCES}
        ${EobCS}
        main.cpp
)

#add include path
target_include_directories(${PROJECT_NAME} PUBLIC 
        ${CMAKE_SOURCE_DIR} 
        ${INC} 
        ${RE_INC} 
        ${CORE_INC}
        ${JNI_INCLUDE_DIRS}
        ${IMGUI_INC}
)

#add libraries
target_link_libraries(${PROJECT_NAME} 
        glad 
        glfw3 
        render
        imgui
        ${JNI_LIBRARIES}
)