cmake_minimum_required(VERSION 3.19)
project(Test1)

file(GLOB_RECURSE TEST_FILE
        src/*.*)

add_library(TEST1 STATIC ${TEST_FILE})

