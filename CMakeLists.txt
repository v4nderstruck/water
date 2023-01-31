cmake_minimum_required(VERSION 3.22)

project(
    WaterMolecularSimulation
    VERSION 0.1
    LANGUAGES CXX CUDA
)

file(GLOB SOURCES "./src/*cpp")

add_executable(Main ${SOURCES})