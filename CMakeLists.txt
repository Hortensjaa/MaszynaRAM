cmake_minimum_required(VERSION 3.24)
project(MaszynaRAM C)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set(CMAKE_C_STANDARD 11)

add_executable(MaszynaRAM main.c)
