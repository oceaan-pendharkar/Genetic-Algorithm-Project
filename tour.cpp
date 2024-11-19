#pragma once
#include "tour.hpp"

double tour::get_tour_distance() const {
    double total_distance = 0.0;
    for (size_t i=0; i<cities.size() - 1; i++) {
        total_distance += get_distance_between_cities(cities[i], cities[i+1]);
    }
    return total_distance;
}
