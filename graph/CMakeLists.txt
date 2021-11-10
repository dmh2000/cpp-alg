cmake_minimum_required(VERSION 3.10)

# set project name
project(graph VERSION 1.0)

# version number
configure_file(graph-version.h.in graph-version.h)

# specify standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# target_compile_options()
if (MSVC) 
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else ()
    # gcc
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# add source subdirectory
# add_subdirectory(src)
# add_subdirectory(test)

# get source source files
file(GLOB MAIN graph.cpp)
file(GLOB SRC_FILES src/*.cpp)
file(GLOB TEST_FILES test/*.cpp)

# add an executable
add_executable(graph ${MAIN} ${SRC_FILES} ${TEST_FILES})

# target_compile_definitions()
# target_include_directories()
# target_link_libraries()
target_link_libraries (graph LINK_PUBLIC 
    /home/dmh2000/projects/cpp-alg/googletest/build/lib/libgtest.a
    pthread
)


target_include_directories(
    graph PUBLIC 
    include
    ${CMAKE_CURRENT_SOURCE_DIR}/../googletest/googletest/include
    "${PROJECT_BINARY_DIR}"
)
