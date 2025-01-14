#pragma once
#include <random>
#include <vector>
#include <algorithm>
#include <iostream>
#include "City.hpp"

/**
 * A tour has a list of cities.
 *
 * The distance between each pair of cities is determined using the pythagorean distance formula:
 * d = sqrt((x2-x1)^2 + (yz-y1)^2)
 *
 * Cities are visited in the order they are arranged in the tour.
 */
class Tour {
 static const double SCALAR;
 /**
  * Cities: our list of cities in the tour
  */
 std::vector<City*> cities;

public:
 /**
  * Constructor
  * Initializes a shuffled order of the passed-in cities
  * @param cities the vector of cities in a tour
  */
 Tour() {}
 explicit Tour(const std::vector<City*> &cities):cities(cities) {}

 /**
  *
  * @param t the tour to copy into this one
  */
 void shuffle_cities() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::shuffle(std::begin(cities), std::end(cities), gen);
 }

 /**
  * Push City: Adds a new City to our list of cities
  * @param new_city the city to add to our list of cities
  */
 void push_city(City * new_city) { cities.push_back(new_city); }

 /**
  * Get Cities: gets the cities
  * @return the vector of pointers to city within this tour
  */
 std::vector<City*> get_cities() { return cities; }

 /**
  * Get number of cities: gets the number of cities
  * @return the number of cities, an int
  */
 int get_number_of_cities() const { return static_cast<int>(cities.size()); }

 /**
  * Get city name: gets the name of a city at a particular index
  * @param i the name of the city and the index given, a string
  * @return
  */
 std::string get_city_name(const int i) const { return cities[i]->get_name(); }

 /**
  * Get Tour Distance
  *
  * Gets the sum of all the distances between each city on the tour
  * (i.e. the total distance of the tour)
  * This includes the distance from the last city back to the first city!
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
  * Contains City with Name
  * Determines if a tour already contains a city with a given name
  *
  * @param name the name of the city to check, a string
  * @return true if the tour contains a city with the given name
  */
 bool contains_city_with_name(const std::string &name) const;

 /**
  * Swap Cities swaps the position of two cities in a tour.
  *
  * @param a an index of a city, an int
  * @param b an index of another city, an int
  */
 void swap_cities(int a, int b);
};
