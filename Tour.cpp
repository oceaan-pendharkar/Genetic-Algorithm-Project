#include "Tour.hpp"

const double Tour::SCALAR = 1000;

double Tour::get_tour_distance() const {
    double total_distance = 0.0;
    for (size_t i=0; i<cities.size() - 1; i++) {
        total_distance += get_distance_between_cities(cities[i], cities[i+1]);
    }
    total_distance += get_distance_between_cities(cities[cities.size()-1], cities[0]);
    return total_distance;
}

double Tour::get_tour_fitness() const {
    const double distance = get_tour_distance();
    return SCALAR/distance;
}
