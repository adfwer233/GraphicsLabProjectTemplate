# CMakeLists.txt in UserProject
cmake_minimum_required(VERSION 3.28)
project(UserProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GRAPHICS_LAB_INSTALL_PATH "" CACHE STRING "install path of graphics lab")

list(APPEND CMAKE_PREFIX_PATH ${GRAPHICS_LAB_INSTALL_PATH})
INCLUDE_DIRECTORIES(${GRAPHICS_LAB_INSTALL_PATH}/include)

message(STATUS "Graphics Lab Install Path: ${GRAPHICS_LAB_INSTALL_PATH}")

# Path to the graphics engine's root directory
find_package(spdlog REQUIRED)
find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)
find_package(assimp REQUIRED)
find_package(spirv_cross_core REQUIRED)
find_package(spirv_cross_glsl REQUIRED)
find_package(spirv_cross_cpp REQUIRED)
find_package(autodiff REQUIRED)
find_package(eigen3 REQUIRED)
find_package(OpenMP REQUIRED)
find_package(GraphicsLab REQUIRED)
find_package(OpenCV)

# Create the user project executable
add_library(UserProject SHARED
    src/main.cpp
)

# Link the engine's libraries (replace YourEngineLib with actual library names)
target_link_libraries(UserProject
        GraphicsLab::LAB_vkl
)
