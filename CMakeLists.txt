cmake_minimum_required(VERSION 3.17)
project(Asn2)

set(CMAKE_CXX_STANDARD 14)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -pedantic -std=c++14")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(Asn2 main.cpp city.cpp city.hpp tour.cpp tour.hpp population.cpp population.hpp simulation.cpp simulation.hpp)