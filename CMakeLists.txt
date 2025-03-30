cmake_minimum_required(VERSION 3.16)
project(NeuralVisualizer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ZBuild REQUIRED)

# Source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# Add executable
add_executable(NeuralVisualizer ${SOURCES})

target_include_directories(NeuralVisualizer PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/architecture
    ${PROJECT_SOURCE_DIR}/include/gui
    ${PROJECT_SOURCE_DIR}/include/utils
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/architecture
    ${PROJECT_SOURCE_DIR}/src/gui
    ${PROJECT_SOURCE_DIR}/src/utils
)

# Link libraries
target_link_libraries(NeuralVisualizer PRIVATE ZBuild::ZBuild)
