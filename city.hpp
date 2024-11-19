#pragma once

/**
 * A city has x and y coordinates to indicate its position relative to other cities.
 */
class city {
    /**
     * Coordinates: x  (longitude) and y (latitude)
     * x and y must be within the range [0, 1000] inclusive
     */
    int x;
    int y;

    /**
     * Constructor
     * @param x position on x-axis (i.e. longitude) of city, an int
     * @param y position on y-axis (i.e. latitude) of city, an int
     */
    city(const int x, const int y):x(x), y(y){}
};
