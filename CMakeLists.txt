cmake_minimum_required(VERSION 3.22)
project(
    WaterMolecularSimulation
    VERSION 0.1
    LANGUAGES CXX C CUDA
)
include(ExternalProject)

file(GLOB_RECURSE SOURCES_CPU 
        "./src/cpu/**/*.cpp"
        "./src/cpu/*.cpp"
)

file(GLOB_RECURSE SOURCES_RENDER 
        "./src/render/*.c"
        "./src/render/*.cpp"
)
        

set(THIRD_PARTY ${CMAKE_BINARY_DIR}/third-party)

# external project GLFW
ExternalProject_Add(glfw_lib
    GIT_REPOSITORY "https://github.com/glfw/glfw"
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${THIRD_PARTY}
)

# dependencies and includes
find_package(OpenGL REQUIRED)
include_directories(${THIRD_PARTY}/include)
include_directories(include)
link_directories(${THIRD_PARTY}/lib)

# builds
add_executable(CPU_WaterSim ${SOURCES_CPU})
add_library(RENDER_LIB ${SOURCES_RENDER})

target_include_directories(CPU_WaterSim PUBLIC "./src/render")

# build dependencies
add_dependencies(CPU_WaterSim glfw_lib RENDER_LIB)

# linking
set(GRAPHIC_LIBS ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})
target_link_libraries(RENDER_LIB glfw3 ${GRAPHIC_LIBS})
target_link_libraries(CPU_WaterSim RENDER_LIB)