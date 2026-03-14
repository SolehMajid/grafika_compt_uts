# ====================================================
#  Project: GLUTApp UTS
#  Author : Yohanes Oktanio
#  NIM    : 24-095
#  Website: yohanes.oktanio.dev
# ====================================================
#  Deskripsi:
#  CMake configuration file for building an
#  OpenGL + GLUT based graphics project (multiple targets).
#  Message : Mesakno Developere Mas/Mbak. Jajal Tukokno Maem
# ====================================================

cmake_minimum_required(VERSION 3.10)

project(GLUTApp VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_executable(main
    main.cpp
    src/maze.cpp
)

target_include_directories(main PRIVATE src)

target_link_libraries(main PRIVATE
    OpenGL::GL
    OpenGL::GLU
    GLUT::GLUT
)

install(TARGETS main DESTINATION bin)

set(CPACK_PACKAGE_NAME "maze")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_GENERATOR "DEB;RPM")
set(CPACK_PACKAGE_CONTACT "yohanes@oktanio.dev")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Yohanes Oktanio")
set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "OpenGL Maze Game - UTS")
set(CPACK_DEBIAN_PACKAGE_DEPENDS
    "freeglut3, libglu1-mesa, libgl1"
)

include(CPack)