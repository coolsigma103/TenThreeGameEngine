# Findglfw3.cmake - Locate GLFW3 library
# This module defines:
#   glfw3_FOUND
#   glfw3_INCLUDE_DIRS
#   glfw3_LIBRARIES

find_path(GLFW3_INCLUDE_DIR
    NAMES GLFW/glfw3.h
    PATHS
        /usr/include
        /usr/local/include
        ${CMAKE_SOURCE_DIR}/external/glfw/include
)

find_library(GLFW3_LIBRARY
    NAMES glfw glfw3
    PATHS
        /usr/lib
        /usr/local/lib
        ${CMAKE_SOURCE_DIR}/external/glfw/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(glfw3
    REQUIRED_VARS glfw3_LIBRARY GLFW3_INCLUDE_DIR
    VERSION_VAR glfw3_VERSION
)

if(glfw3_FOUND)
    set(glfw3_LIBRARIES ${GLFW3_LIBRARY})
    set(glfw3_INCLUDE_DIRS ${GLFW3_INCLUDE_DIR})
endif()
