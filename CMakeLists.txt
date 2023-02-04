cmake_minimum_required(VERSION 3.22)
project(
    WaterMolecularSimulation
    VERSION 0.1
    LANGUAGES CXX CUDA
)
include(ExternalProject)

file(GLOB_RECURSE SOURCES_CPU 
        "./src/cpu/**/*.cpp"
        "./src/cpu/*.cpp")

set(THIRD_PARTY ${CMAKE_BINARY_DIR}/third-party)

# external project GLFW
ExternalProject_Add(glfw_lib
    GIT_REPOSITORY "https://github.com/glfw/glfw"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${THIRD_PARTY}
)

find_package(OpenGL REQUIRED)
set(LIBS ${OPENGL_LIBRARIES})

include_directories(${THIRD_PARTY}/include)
link_directories(${THIRD_PARTY}/lib)
add_executable(CPU_WaterSim ${SOURCES_CPU})
add_dependencies(CPU_WaterSim glfw_lib)

target_link_libraries(CPU_WaterSim ${LIBS} ${GLFW_LIBRARIES})