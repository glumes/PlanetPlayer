cmake_minimum_required(VERSION 3.19)
project(Test2)

file(GLOB_RECURSE TEST_FILE
        src/*.*)

add_library(TEST2 STATIC ${TEST_FILE})
