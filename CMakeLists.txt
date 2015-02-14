set(
    ToRun
# Here set program file you want work on:
    MWPZ06H.cpp
#
#   input
    )
project(SPOJ)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
# add_executable(${PROJECT_NAME} ${SRC_LIST})
add_executable(${PROJECT_NAME} ${ToRun})
configure_file(input input COPYONLY)
add_library(list_all_files ${SRC_LIST})
