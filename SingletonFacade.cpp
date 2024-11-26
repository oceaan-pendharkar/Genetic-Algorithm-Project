#include <iostream>
#include <iomanip>
#include "SingletonFacade.hpp"
#include "GeneticSystem.hpp"
#include "TourPopulationFactory.hpp"

constexpr int FIRST = 0;
constexpr int ONE = 1;
constexpr int TWO = 2;
constexpr int SIX = 6;
constexpr int ITERATIONS = 1000;
constexpr double IMPROVEMENT_FACTOR = 1.5;
void clean_up(const std::vector<City*>& cities, const TourPopulationFactory *factory);
void print_original_elite_data(const Tour& base_elite);
void reprint_original_elite(const Tour& base_elite, double base_distance);
void print_best_elite(const Tour& final_elite);
void print_final_report(const GeneticInfo & data, const Tour & final_elite);

void SingletonFacade::run() {
    auto data = GeneticInfo{};

    //initialize population
    const auto * factory = new TourPopulationFactory{};
    data.tours = factory->createPopulation();
    data.base_elite = data.tours[FIRST];
    data.base_distance = data.base_elite.get_tour_distance();
    data.best_distance = data.base_distance;

    // Print the original Elite data
    print_original_elite_data(data.base_elite);

    // Sets up the variables for the Genetic Algorithm
    std::cout << "Enter your mutation rate (A2 suggests 15)" << std::endl;
    std::cin >> data.mutation_rate;
    const GeneticSystem genetic_system(&data);
    // std::vector<Tour> data.tours = data.tours;

     // while termination criteria not reached.
     while(data.base_distance/data.best_distance < IMPROVEMENT_FACTOR && data.iterations < ITERATIONS) {
         // Run the latest set of data.tours through the Genetic System
         genetic_system.iterate_next(data.tours);
     }

    const Tour final_elite = data.tours[FIRST];
    print_final_report(data, final_elite);
    clean_up(data.tours[0].get_cities(), factory);
}

void print_final_report(const GeneticInfo & data, const Tour & final_elite) {
    std::cout << "--- FINISHED ALGORITHM ---" << std::endl;
    std::cout << "Total iterations: " << data.iterations << std::endl;
    std::cout << std::endl;
    reprint_original_elite(data.base_elite, data.base_distance);
    print_best_elite(final_elite);

    if (data.base_distance/data.best_distance >= IMPROVEMENT_FACTOR) {
        std::cout << std::endl;
        std::cout << "Improvement factor reached!" << std::endl;
        std::cout << "Improvement factor: " << std::fixed << std::setprecision(SIX) <<
            data.improvement_factor << std::endl;
    }
}

void print_original_elite_data(const Tour& base_elite) {
    std::cout << std::endl;
    std::cout << "Original Elite Distance: " << base_elite.get_tour_distance() << std::endl;
    std::cout << "(";
    for (int i = 0; i < base_elite.get_number_of_cities() - ONE; i++) {
        std::cout << base_elite.get_city_name(i) << "->";
    }
    std::cout << base_elite.get_city_name(base_elite.get_number_of_cities() - ONE) << ")" << std::endl;
    std::cout << "--- STARTING ALGORITHM ---" << std::endl;
}

void reprint_original_elite(const Tour& base_elite, double base_distance) {
    std::cout << "Original Elite:" << std::endl;
    std::cout << "Distance: " << std::fixed << std::setprecision(TWO) << base_distance << std::endl;
    std::cout << "(";
    for (int i = 0; i < base_elite.get_number_of_cities() - ONE; i++) {
        std::cout << base_elite.get_city_name(i) << "->";
    }
    std::cout << base_elite.get_city_name(base_elite.get_number_of_cities() - ONE) << ")" << std::endl;
    std::cout << std::endl;
}

void print_best_elite(const Tour& final_elite) {
    std::cout << "Best Elite:" << std::endl;
    std::cout << "Distance: " << std::fixed << std::setprecision(TWO) << final_elite.get_tour_distance() << std::endl;
    std::cout << "(";
    for (int i = 0; i < final_elite.get_number_of_cities() - ONE; i++) {
        std::cout << final_elite.get_city_name(i) << "->";
    }
    std::cout << final_elite.get_city_name(final_elite.get_number_of_cities() - ONE) << ")" << std::endl;
}

void clean_up(const std::vector<City*>& cities, const TourPopulationFactory *factory) {
    for(auto & city : cities) {
        delete city;
    }
    delete factory;
}
