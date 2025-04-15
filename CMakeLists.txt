cmake_minimum_required(VERSION 3.16)
project(Synapped)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(ZBuild REQUIRED)

# Source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
)

# Add executable
add_executable(Synapped ${SOURCES})

file(GLOB_RECURSE ALL_INCLUDE_DIRS
    RELATIVE "${PROJECT_SOURCE_DIR}/include"
    "${PROJECT_SOURCE_DIR}/include/*"
)

set(INCLUDE_DIRS "")
foreach(path IN LISTS ALL_INCLUDE_DIRS)
    get_filename_component(dir "${PROJECT_SOURCE_DIR}/include/${path}" DIRECTORY)
    list(APPEND INCLUDE_DIRS "${dir}")
endforeach()

file(GLOB_RECURSE ALL_SRC_INCLUDE_DIRS
    RELATIVE "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/src/*"
)

foreach(path IN LISTS ALL_SRC_INCLUDE_DIRS)
    get_filename_component(dir "${PROJECT_SOURCE_DIR}/src/${path}" DIRECTORY)
    list(APPEND INCLUDE_DIRS "${dir}")
endforeach()

list(REMOVE_DUPLICATES INCLUDE_DIRS)

target_include_directories(Synapped PRIVATE
    ${INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(Synapped PRIVATE ZBuild::ZBuild)
