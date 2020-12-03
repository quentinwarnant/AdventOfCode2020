cmake_minimum_required(VERSION 3.0.0)
project(AdventOfCode VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

#add_executable(AdventOfCode main.cpp)

file(GLOB SOURCES
    Days/*.hpp
    Days/*.cpp
    main.cpp
)

add_executable(AdventOfCode ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
