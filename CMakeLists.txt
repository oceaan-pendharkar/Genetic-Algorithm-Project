cmake_minimum_required(VERSION 3.20)
project(lab1template)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)

add_executable(assignment2template
        main.cpp
        City.hpp
        City.cpp
        Tour.hpp
        Tour.cpp
        SingletonFacade.hpp
        SingletonFacade.cpp
        TourPopulationFactory.hpp
        TourPopulationFactory.cpp
        BasePopulationHandler.cpp
        BasePopulationHandler.hpp
        CrossoverHandler.cpp
        CrossoverHandler.hpp
        MutationHandler.cpp
        MutationHandler.hpp
        EvaluationHandler.cpp
        EvaluationHandler.hpp
        GeneticSystem.cpp
        GeneticSystem.hpp)
