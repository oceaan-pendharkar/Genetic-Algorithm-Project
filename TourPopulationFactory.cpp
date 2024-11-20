#include "TourPopulationFactory.hpp"
#include "city.hpp"
#include <iostream>
#include <random>
using namespace std;

constexpr double ZERO = 0;
constexpr double MAP_BOUNDARY = 1000;

/**
 * Initializing the random device outside the function scope to avoid issues
 */
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<double> dist(ZERO, MAP_BOUNDARY);

/**
 * Generate Coordinate : a helper function
 * Returns a city coordinate
 * @return a coordinate for a city, a double
 */
double generate_coordinate() {
    return dist(gen);
}

TourPopulationFactory::TourPopulationFactory(tour *t) {
    this->t = t;
    cout << "How many cities would you like to include in your population?" << endl;
    cin >> this->cities_in_tour;
    cout << "How big should the population be?" << endl;
    cin >> this->population_size;
}

std::vector<tour*> TourPopulationFactory::createPopulation() const {
    vector<city*> cities;
    int counter = 0;
    // create a list of cities with ids and randomly generated coordinates within our range
    for(int i=0; i<cities_in_tour; i++) {
        string name = to_string(counter++);
        const double x = generate_coordinate();
        const double y = generate_coordinate();
        cities[i] = new city(x, y, name);
    }

    const auto t = new tour(cities);
    vector<tour*> tours;
    // create a list of tours based on this one tour that contains our cities
    for (int i=0; i<population_size; i++) {
        // our tour copy constructor shuffles the original order
        tours[i] = new tour(*t);
    }

    //sort the tours in increasing level of fitness
    ranges::sort(tours, [](const tour*a, const tour* b) {
        return a->get_tour_fitness() < b->get_tour_fitness();
    });

    return tours;
}





