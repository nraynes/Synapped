cmake_minimum_required(VERSION 3.10)
project(NeuralVisualizer)

set(CMAKE_CXX_STANDARD 17)

# Find gtkmm
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)

link_directories(${GTKMM_LIBRARY_DIRS})

# Source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# Add executable
add_executable(neural_visualizer ${SOURCES})

target_include_directories(neural_visualizer PRIVATE
    ${GTKMM_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/architecture
    ${PROJECT_SOURCE_DIR}/include/enums
    ${PROJECT_SOURCE_DIR}/include/gui
    ${PROJECT_SOURCE_DIR}/include/utils
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/src/architecture
    ${PROJECT_SOURCE_DIR}/src/gui
    ${PROJECT_SOURCE_DIR}/src/utils
)

# Link libraries
target_link_libraries(neural_visualizer ${GTKMM_LIBRARIES})

# Optional: remove annoying warnings from pkg-config
add_definitions(${GTKMM_CFLAGS_OTHER})