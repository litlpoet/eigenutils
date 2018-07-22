# Top level CMakeLists
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(eigenutils VERSION 0.0.1 LANGUAGES CXX)

## 'Release' as default build type
if(NOT CMAKE_CONFIGURATION_TYPES AND NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to 'Release' as none was specified")
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
  set_property (CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "Build type: " ${CMAKE_BUILD_TYPE})

# global setting
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# enable testing this project
enable_testing()

# add subdirectories
add_subdirectory(src)
add_subdirectory(test)
