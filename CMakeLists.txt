cmake_minimum_required(VERSION 3.22)

project(
    WaterMolecularSimulation
    VERSION 0.1
    LANGUAGES CXX CUDA
)

file(GLOB SOURCES_CPU "./src/cpu/*.cpp")

add_executable(CPU_MAIN ${SOURCES_CPU})