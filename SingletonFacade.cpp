#include "SingletonFacade.hpp"

#include <iostream>

#include "TourPopulationFactory.hpp"

constexpr int FIRST = 0;
constexpr int ITERATIONS = 1000;
constexpr double IMPROVEMENT_FACTOR = 0.05;

void SingletonFacade::run() {
    //initialize population
    const auto * factory = new TourPopulationFactory{};
    const std::vector<tour*> tours = factory->createPopulation();

    tour * elite = tours[FIRST];
    double base_distance = elite->get_tour_distance();
    double best_distance = base_distance;

    for(const auto & tour : tours) {
        std::cout << "fitness: " << tour->get_tour_distance() << " | distance: " << tour->get_tour_fitness() << std::endl;
    }

     // while termination criteria not reached.
     int iterations = 0;
     while(base_distance/best_distance > IMPROVEMENT_FACTOR && iterations++ < ITERATIONS) {
         //TODO: select solutions for next population
         //TODO: perform crossover and mutation
         //TODO: evaluate population

         //placeholder code to make loop work:
         best_distance = base_distance / IMPROVEMENT_FACTOR;
     }

    // We only need to delete one tour because all the tours contain pointers to the same city. We can discuss.
    delete tours[FIRST];
}