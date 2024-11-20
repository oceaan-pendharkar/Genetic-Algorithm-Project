cmake_minimum_required(VERSION 3.20)
project(lab1template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(assignment2template main.cpp city.hpp tour.hpp
        city.cpp
        tour.cpp
        SingletonFacade.hpp
        SingletonFacade.cpp
        TourPopulationFactory.hpp
        TourPopulationFactory.cpp
        TourPopulationManipulator.hpp)
