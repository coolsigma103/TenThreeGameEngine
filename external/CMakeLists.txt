find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(jsoncpp REQUIRED)

add_subdirectory(glad)
add_subdirectory(stb_impl)
add_subdirectory(glm)
add_subdirectory(argparse)

add_library(imgui
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_demo.cpp
    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui PUBLIC
    imgui
    imgui/backends
)

target_link_libraries(imgui PRIVATE glfw OpenGL::GL glad)

set(TEN_THREE_EXTERNAL_LIB_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/glad/include
    ${CMAKE_CURRENT_SOURCE_DIR}/glm
    ${CMAKE_CURRENT_SOURCE_DIR}/stb_impl
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends
    PARENT_SCOPE
)
