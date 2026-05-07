cmake_minimum_required(VERSION 3.20)

project(Macro)

add_executable(Macro main.cc)

# Set the default mode as Debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
# Define DEBUG macro for Debug builds
target_compile_definitions(Macro PRIVATE $<$<CONFIG:Debug>:PR_DEBUG>)