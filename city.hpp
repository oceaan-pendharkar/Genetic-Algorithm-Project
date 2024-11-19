#pragma once

/**
 * A city has x and y coordinates to indicate its position relative to other cities.
 */
class city {
    /**
     * Coordinates: x  (longitude) and y (latitude)
     * x and y must be within the range [0, 1000] inclusive
     */
    double x;
    double y;

    /**
     * Constructor
     * @param x position on x-axis (i.e. longitude) of city, an int
     * @param y position on y-axis (i.e. latitude) of city, an int
     */
    city(const double x, const double y):x(x), y(y){}

    /**
     * Get Distance Between Cities
     *
     * Gets the distance between 2 cities using the pythagorean distance formula d = sqrt((x2-x1)^2 + (yz-y1)^2)
     * 
     * @param a a city
     * @param b another city
     * @return the distance between the two cities
     */
    friend double get_distance_between_cities(city a, city b);
};
