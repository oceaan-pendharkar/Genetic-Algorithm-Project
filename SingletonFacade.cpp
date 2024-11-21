#include <iostream>

#include "SingletonFacade.hpp"
#include "GeneticSystem.hpp"
#include "TourPopulationFactory.hpp"

constexpr int SingletonFacade::FIRST = 0;
constexpr int SingletonFacade::ITERATIONS = 1000;
constexpr double SingletonFacade::IMPROVEMENT_FACTOR = 0.05;

void SingletonFacade::run() {
    //initialize population
    const auto * factory = new TourPopulationFactory{};
    const std::vector<Tour*> tours = factory->createPopulation();

    Tour * elite = tours[FIRST];
    double const base_distance = elite->get_tour_distance();
    double best_distance = base_distance;

    for(const auto & tour : tours) {
        std::cout << "fitness: " << tour->get_tour_distance() << " | distance: " << tour->get_tour_fitness() << std::endl;
    }

    // Print the original Elite data
    std::cout << "Original Elite Distance: " << elite << std::endl;
    //TODO: print statement for original elite city sequence
    std::cout << "--- STARTING ALGORITHM ---" << std::endl;

    // Sets up the variables for the Genetic Algorithm
    GeneticSystem genetic_system;
    std::vector<Tour*> new_tours = tours;
    int iterations = 0;
    bool new_elite_found;
    double improvement_factor;

     // while termination criteria not reached.
     while(base_distance/best_distance > IMPROVEMENT_FACTOR && iterations++ < ITERATIONS) {

         // Run the latest set of tours through the Genetic System
         genetic_system.iterate_next(new_tours);

         // If new Elite is found, set the new values
         if (tours[FIRST]->get_tour_distance() < best_distance) {
             new_elite_found = true;
             best_distance = tours[FIRST]->get_tour_distance();
             improvement_factor = base_distance / best_distance;
         } else {
             new_elite_found = false;
         }

         // Print the new values
         print_iteration(new_tours, iterations, new_elite_found, improvement_factor);
     }

    //delete all the cities: only needs to be done on one tour because all the tours point to the same set of cities
    for (const auto & city : tours[FIRST]->get_cities()) {
        delete city;
    }
    //delete all the pointers to tours
    for (const auto & tour : tours) {
        delete tour;
    }

    delete factory;
}

void SingletonFacade::print_iteration(std::vector<Tour*> & population, const int & iterations,
    const bool & new_elite_found, const double & improvement_factor) {
    std::cout << "Iteration: " << iterations << std::endl;

    if (new_elite_found) {
        std::cout << "NEW ELITE FOUND:" << std::endl;
    }

    std::cout << "Distance: " << population[FIRST]->get_tour_distance() << std::endl;

    if (!new_elite_found) {
        std::cout << "Best non-elite distance: " << population[FIRST]->get_tour_distance() << std::endl;
    }
    std::cout << "Improvement over base: " << improvement_factor << std::endl;
}
