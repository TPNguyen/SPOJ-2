set(
    ToRun
# Here set program file you want work on:
    test.cpp
#
#   input
    )
project(SPOJ)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
# add_executable(${PROJECT_NAME} ${SRC_LIST})
add_executable(${PROJECT_NAME} ${ToRun})
configure_file(input input COPYONLY)
# add_library(list_all_files ${SRC_LIST})
# SET_TARGET_PROPERTIES(list_all_files PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD_DEBUG True)
# list(APPEND CMAKE_CXX_FLAGS "-std=c++14")
add_definitions(-std=c++1y)
