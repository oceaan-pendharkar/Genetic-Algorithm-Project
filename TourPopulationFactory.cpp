#include "TourPopulationFactory.hpp"
#include "city.hpp"
#include <iostream>
#include <random>
using namespace std;

constexpr double ZERO = 0;
constexpr double MAP_BOUNDARY = 1000;
constexpr int MINIMUM_SIZE = 10;

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

TourPopulationFactory::TourPopulationFactory() {
    cout << "How many cities would you like to include in your population? (Minimum size: 10)" << endl;
    cin >> this->cities_in_tour;
    if (cities_in_tour < MINIMUM_SIZE) {
        cout << "That number is too small. Please enter a number 10 or greater." << endl;
        cin >> this->cities_in_tour;
    }
    cout << "How many cities should we visit? (Minimum size: 10)" << endl;
    cin >> this->population_size;
    if (population_size < MINIMUM_SIZE) {
        cout << "That number is too small. Please enter a number 10 or greater." << endl;
        cin >> this->population_size;
    }
}

std::vector<Tour*> TourPopulationFactory::createPopulation() const {
    vector<City*> cities;
    int counter = 0;
    // create a list of cities with ids and randomly generated coordinates within our range
    for(int i=0; i<cities_in_tour; i++) {
        string name = to_string(counter++);
        const double x = generate_coordinate();
        const double y = generate_coordinate();
        cities.push_back(new City(x, y, name));
    }

    const auto t = new Tour(cities);
    // create a list of tours based on this one tour that contains our cities
    vector<Tour*> tours;
    tours.reserve(population_size);
    for (int i=0; i<population_size; i++) {
        // our tour copy constructor shuffles the original order
        tours.push_back(new Tour(*t));
    }

    //sort the tours in decreasing level of fitness
    ranges::sort(tours, [](const Tour*a, const Tour* b) {
        return a->get_tour_fitness() > b->get_tour_fitness();
    });

    delete t;
    return tours;
}





