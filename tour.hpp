#pragma once
#include <vector>

#include "city.hpp"

/**
 * A tour has a list of cities.
 *
 * The distance between each pair of cities is determined using the pythagorean distance formula:
 * d = sqrt((x2-x1)^2 + (yz-y1)^2)
 *
 * Cities are visited in the order they are arranged in the tour.
 */
class tour {
    /**
     * Cities: our list of cities in the tour
     */
    std::vector<city*> cities;

public:
    /**
     * Constructor
     * Initializes a shuffled order of the passed-in cities
     * @param cities the vector of cities in a tour
     */
    explicit tour(const std::vector<city*> &cities):cities(cities) {}

    /**
     * Copy constructor
     * takes another tour and shuffles its city order to create a new tour
     *
     * @param t the tour to copy into this one
     */
    tour(const tour& t):tour(t.cities) {
     std::shuffle(cities.begin(), cities.end(), cities);
    }

    /**
     * Get Tour Distance
     *
     * Gets the sum of all the distances between each city on the tour
     * (i.e. the total distance of the tour)
     *
     * @return the total tour distance, as a double
     */
     double get_tour_distance() const;

    /**
     * Get Tour Fitness
     *
     * Gets the fitness (quality) of the tour, which is inversely proportional to the total distance traveled.
     * Specifically, we divide a scalar by the total distance to get our fitness.
     *
     * @return the fitness/quality of the tour, a double
     */
    double get_tour_fitness() const;

    /**
     * Destructor: deletes all the cities within
     */
    ~tour();
};
