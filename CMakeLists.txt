cmake_minimum_required(VERSION 3.19)
project(PlanetPlayer)

set(CMAKE_CXX_STANDARD 14)

set(PLANET_INCLUDES ./ include src)

add_subdirectory(3rdparty/test1)
list(APPEND PLANET_INCLUDES 3rdparty/test1/src)

add_subdirectory(3rdparty/test2)
list(APPEND PLANET_INCLUDES 3rdparty/test2/src)

file(GLOB_RECURSE PLANET_FILES
        src/*.*)

add_library(PlanetPlayer STATIC ${PLANET_FILES})
target_include_directories(PlanetPlayer PUBLIC ${PLANET_INCLUDES})
target_link_libraries(PlanetPlayer TEST1 TEST2)

##########################################################

add_subdirectory(./3rdparty/googletest)

file(GLOB_RECURSE PLANET_TEST_FILES
        test/src/*.*
        test/src/utils/*.*)

set(PLANET_TEST_INCLUDES 3rdparty/googletest/googletest 3rdparty/googletest/googletest/include
        3rdparty/googletest/googlemock/include)

list(APPEND PLANET_TEST_INCLUDES ${PLANET_INCLUDES})

add_executable(PlanetUnitTest ${PLANET_TEST_FILES})
target_include_directories(PlanetUnitTest PUBLIC ${PLANET_TEST_INCLUDES})
target_link_libraries(PlanetUnitTest PlanetPlayer gtest)
set_target_properties(PlanetUnitTest PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -fno-access-control")

