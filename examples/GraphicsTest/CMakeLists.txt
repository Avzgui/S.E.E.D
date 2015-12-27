cmake_minimum_required(VERSION 2.6)

get_filename_component(ProjectId ${CMAKE_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId})

#setters
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

set(SEED_INCLUDE "../../seed-framework/include/")
set(LIBS "${CMAKE_SOURCE_DIR}/../../seed-framework/lib-required")
set(FRAMEWORK "${CMAKE_SOURCE_DIR}/../../seed-framework")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# OpenGL and GLUT package
find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message("ERROR: OpenGL not found")
endif(NOT OPENGL_FOUND)
set(GL_LIBRARY GL GLU X11)

#INCLUDES
include_directories(${OPENGL_INCLUDE_DIRS})
#include directories Seed-Graphics
include_directories(${SEED_INCLUDE})
# include Materials
include_directories(${FRAMEWORK}/ressources/Materials)
# GLM include directory
include_directories(${LIBS}/glm)
# AntTweakBar include directories
include_directories(${LIBS}/antTweakBar/include)
# Boost include directories
include_directories(${LIBS}/boost_win32)
# Assimp include directories for windows
include_directories(${LIBS}/assimp_win32/include)
# Glew include directories for windows
include_directories(${LIBS}/glew_win32/include)
# GLFW include directories for windows
include_directories(${LIBS}/glfw_win32/include)

#libs WINDOWS
if(WIN32)
	set(GLFW_LIB "${LIBS}/glfw_win32/lib-vc2013/glfw3.lib")
	set(GLEW_LIB "${LIBS}/glew_win32/lib/Release/Win32/glew32.lib")
	set(ANT_TWEAK_BAR_LIB "${LIBS}/antTweakBar/lib/Release/Win32/glew32.lib")
	set(ASSIMP_LIB "${LIB}/assimp_win32/lib/assimp_release-dll_win32/assimp.lib")
	set(BOOST_FILESYSTEM_LIB "${LIB}/boost_win32/lib/libboost_filesystem-vc120-mt-1_59.lib")
	set(SEED_GRAPHICS_LIB "${FRAMEWORK}/build/lib/Seed-Graphics.lib")
else(WIN32)
endif(WIN32)

file(GLOB_RECURSE SRC src/*.?pp)

add_executable(${ProjectId} ${SRC})

target_link_libraries(${ProjectId} ${OPENGL_INCLUDE_DIRS})
target_link_libraries(${ProjectId} ${ASSIMP_LIB})
target_link_libraries(${ProjectId} ${GLEW_LIB})
target_link_libraries(${ProjectId} ${GLFW_LIB} ${GL_LIBRARY} m)
target_link_libraries(${ProjectId} ${SEED_GRAPHICS_LIB})
target_link_libraries(${ProjectId} ${ANT_TWEAK_BAR_LIB})
target_link_libraries(${ProjectId} ${BOOST_FILESYSTEM_LIB})
