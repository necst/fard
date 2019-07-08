cmake_minimum_required(VERSION 3.12)
project(image_filtering_debugging_C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(image_filtering_debugging_C
        edgeDetector.c
        edgeDetector.h
        filters.c
        filters.h
        main.c)

target_link_libraries( image_filtering_debugging_C pthread )