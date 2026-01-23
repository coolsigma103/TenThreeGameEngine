cmake_minimum_required(VERSION 3.23)

project(TenThreeGameEngine VERSION 0.0.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenGL REQUIRED)
find_package(Vulkan REQUIRED)

add_subdirectory(thirdparty/FreeType)
add_subdirectory(thirdparty/glad)
add_subdirectory(thirdparty/glfw)
add_subdirectory(thirdparty/glm)
add_subdirectory(thirdparty/libsndfile)
add_subdirectory(thirdparty/nlohmann-json)
add_subdirectory(thirdparty/openal-soft)
add_subdirectory(thirdparty/stb_impl)

file(GLOB_RECURSE 103_ENGINE_SOURCES CONFIGURE_DEPENDS *.cpp  *.c)

add_executable(TenThreeGameEngine ${103_ENGINE_SOURCES})
target_include_directories(TenThreeGameEngine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(TenThreeGameEngine PRIVATE freetype 
                                                 glad 
                                                 glfw 
                                                 glm 
                                                 sndfile 
                                                 nlohmann_json::nlohmann_json 
                                                 openal
                                                 stb_impl
)



