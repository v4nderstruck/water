cmake_minimum_required(VERSION 3.22)

project(
    WaterMolecularSimulation
    VERSION 0.1
    LANGUAGES CXX CUDA
)

file(GLOB_RECURSE SOURCES_CPU 
        "./src/cpu/**/*.cpp"
        "./src/cpu/*.cpp")


add_executable(CPU_WaterSim ${SOURCES_CPU})