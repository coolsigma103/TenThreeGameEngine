file(GLOB_RECURSE SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

find_package(glfw3 REQUIRED)

add_library(render STATIC ${SOURCES})
target_include_directories(render PRIVATE ${INC})   
target_link_libraries(render glad glfw)
set(RE_INC "${CMAKE_CURRENT_SOURCE_DIR}/src" PARENT_SCOPE)