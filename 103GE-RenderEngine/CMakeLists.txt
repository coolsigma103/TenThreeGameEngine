file(GLOB_RECURSE RE_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(render STATIC ${RE_SOURCES})
target_include_directories(render PRIVATE ${INC})   
target_link_libraries(render glad)
set(RE_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/src")