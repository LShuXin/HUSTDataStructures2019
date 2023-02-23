cmake_minimum_required(VERSION 3.17)

set(CMAKE_C_STANDARD 99)

set(project_name HUSTDataStructures2019) ## rename your project here

project(${project_name} C)

include_directories(src)

add_library(${project_name}-lib
            src/a_test.h
            src/a_test.c
            src/headers.h
            src/define.h
            src/sort/sort.h
            src/sort/sort.c
            )


add_executable(${project_name}-exe main.c)
target_link_libraries(${project_name}-exe ${project_name}-lib)