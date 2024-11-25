#include <iostream>
#include <iomanip>

#include "SingletonFacade.hpp"
#include "GeneticSystem.hpp"
#include "TourPopulationFactory.hpp"

constexpr int FIRST = 0;
constexpr int ONE = 1;
constexpr int TWO = 2;
constexpr int SIX = 6;
constexpr int SingletonFacade::ITERATIONS = 1000;
constexpr double SingletonFacade::IMPROVEMENT_FACTOR = 1.5;
void clean_up(const std::vector<City*>& cities, const TourPopulationFactory *factory);
static void print_iteration(const std::vector<Tour> & population, const int & iterations,
                            const bool & new_elite_found, const double & improvement_factor);
void print_original_elite_data(Tour base_elite);

void SingletonFacade::run() {
    //initialize population
    const auto * factory = new TourPopulationFactory{};
    const std::vector<Tour> tours = factory->createPopulation();

    Tour base_elite = tours[FIRST];
    double const base_distance = base_elite.get_tour_distance();
    double best_distance = base_distance;

    // Print the original Elite data
    print_original_elite_data(base_elite);

    // Sets up the variables for the Genetic Algorithm
    int mutation_rate;
    std::cout << "Enter your mutation rate (A2 suggests 15)" << std::endl;
    std::cin >> mutation_rate;
    const GeneticSystem genetic_system(mutation_rate);
    std::vector<Tour> new_tours = tours;
    int iterations = 0;
    bool new_elite_found;
    double improvement_factor;

     // while termination criteria not reached.
     while(base_distance/best_distance < IMPROVEMENT_FACTOR && iterations < ITERATIONS) {

         // Run the latest set of tours through the Genetic System
         genetic_system.iterate_next(new_tours);

         // If new Elite is found, set the new values
         if (new_tours[FIRST].get_tour_distance() < best_distance) {
             new_elite_found = true;
             best_distance = new_tours[FIRST].get_tour_distance();
             improvement_factor = base_distance / best_distance;
         } else {
             new_elite_found = false;
         }

         // Print the new values
         print_iteration(new_tours, iterations++, new_elite_found, improvement_factor);
     }

    Tour final_elite = new_tours[FIRST];

    std::cout << "--- FINISHED ALGORITHM ---" << std::endl;
    std::cout << "Total iterations: " << iterations << std::endl;
    std::cout << std::endl;
    std::cout << "Original Elite:" << std::endl;
    std::cout << "Distance: " << std::fixed << std::setprecision(TWO) << base_distance << std::endl;
    std::cout << "(";
    for (int i = 0; i < base_elite.get_number_of_cities() - ONE; i++) {
        std::cout << base_elite.get_city_name(i) << "->";
    }
    std::cout << base_elite.get_city_name(base_elite.get_number_of_cities() - ONE) << ")" << std::endl;
    std::cout << std::endl;
    std::cout << "Best Elite:" << std::endl;
    std::cout << "Distance: " << std::fixed << std::setprecision(TWO) << final_elite.get_tour_distance() << std::endl;
    std::cout << "(";
    for (int i = 0; i < final_elite.get_number_of_cities() - ONE; i++) {
        std::cout << final_elite.get_city_name(i) << "->";
    }
    std::cout << final_elite.get_city_name(final_elite.get_number_of_cities() - ONE) << ")" << std::endl;

    if (base_distance/best_distance >= IMPROVEMENT_FACTOR) {
        std::cout << std::endl;
        std::cout << "Improvement factor reached!" << std::endl;
        std::cout << "Improvement factor: " << std::fixed << std::setprecision(SIX) <<
            improvement_factor << std::endl;
    }
    clean_up(new_tours[0].get_cities(), factory);
}

void print_iteration(const std::vector<Tour> & population, const int & iterations,
                     const bool & new_elite_found, const double & improvement_factor) {
    std::cout << "Iteration: " << iterations << std::endl;

    if (new_elite_found) {
        std::cout << "NEW ELITE FOUND:" << std::endl;
    }

    std::cout << "Distance: " << std::fixed << std::setprecision(TWO)
        << population[FIRST].get_tour_distance() << std::endl;

    if (!new_elite_found) {
        std::cout << "Best non-elite distance: " << std::fixed << std::setprecision(TWO)
            << population[FIRST].get_tour_distance() << std::endl;
    }
    std::cout << "Improvement over base: " << std::fixed << std::setprecision(SIX)
        << improvement_factor << std::endl << std::endl;
}

void print_original_elite_data(Tour base_elite) {
    std::cout << std::endl;
    std::cout << "Original Elite Distance: " << base_elite.get_tour_distance() << std::endl;
    std::cout << "(";
    for (int i = 0; i < base_elite.get_number_of_cities() - ONE; i++) {
        std::cout << base_elite.get_city_name(i) << "->";
    }
    std::cout << base_elite.get_city_name(base_elite.get_number_of_cities() - ONE) << ")" << std::endl;
    std::cout << "--- STARTING ALGORITHM ---" << std::endl;
}

void clean_up(const std::vector<City*>& cities, const TourPopulationFactory *factory) {
    for(auto & city : cities) {
        delete city;
    }
    delete factory;
}
