cmake_minimum_required(VERSION 3.24)
project(MaszynaRAM C)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set(CMAKE_C_STANDARD 11)

add_executable(MaszynaRAM main.c main_service.c input_output_tapes.c commands_queue.c accumulator_service.c memory_service.c prompts_and_exceptions.c stream_control.c support_functions.c)
#add_executable(MaszynaRAM main.c)
