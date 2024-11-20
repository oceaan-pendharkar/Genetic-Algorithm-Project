#include "SingletonFacade.hpp"
#include "TourPopulationFactory.hpp"

void run() {
    //initialize population
    const auto * factory = new TourPopulationFactory{};
    std::vector<tour*> tours = factory->createPopulation();

    //evaluate population

    //while termination criteria not reached.
        //select solutions for next population
        //perform crossover and mutation
        //evaluate population

    for(const auto & tour : tours) {
        delete tour;
    }
}