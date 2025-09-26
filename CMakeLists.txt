cmake_minimum_required(VERSION 3.10)

project(djangocpp
    VERSION 1.0
    DESCRIPTION "A Django-inspired C++ web framework"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Compiler flags
option(ENABLE_LTO "Enable Link Time Optimization" ON)

if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3" CACHE STRING "Debug flags" FORCE)
elseif(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -flto -s" CACHE STRING "Release flags" FORCE)
endif()

set(SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/main.cc
    ${PROJECT_SOURCE_DIR}/src/app.cc
    ${PROJECT_SOURCE_DIR}/src/http.cc
    ${PROJECT_SOURCE_DIR}/src/router.cc
)

add_executable(djangocpp ${SRC_FILES})

# Enable LTO if requested
if(ENABLE_LTO)
    message(STATUS "LTO enabled")
    set_property(TARGET djangocpp PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
endif()

