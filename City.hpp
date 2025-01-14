#pragma once
#include <string>

/**
 * A city has x and y coordinates to indicate its position relative to other cities.
 */
class City {
    /**
     * Coordinates: x  (longitude) and y (latitude)
     * x and y must be within the range [0, 1000] inclusive
     */
    double x;
    double y;

    /**
     * Name: the name of the city
     */
    std::string name;

public:
    /**
     * Constructor
     * @param x position on x-axis (i.e. longitude) of city, an int
     * @param y position on y-axis (i.e. latitude) of city, an int
     * @param name the name of the city, a string
     */
    City(const double x, const double y, std::string& name):x(x), y(y), name(name){}

    /**
     * Get Distance Between Cities
     *
     * Gets the distance between 2 cities using the pythagorean distance formula d = sqrt((x2-x1)^2 + (yz-y1)^2)
     *
     * @param a a city
     * @param b another city
     * @return the distance between the two cities
     */
    friend double get_distance_between_cities(const City * a, const City * b);

    /**
     * Get name: gets the name of a city
     * @return the name of a city, a string
     */
    std::string get_name() { return name; }
};
