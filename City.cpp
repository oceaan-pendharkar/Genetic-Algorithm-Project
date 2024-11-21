#include "City.hpp"

#include <cmath>

const int City::TWO = 2;

double get_distance_between_cities(const City * a, const City * b) {
    int power = City::TWO;
    return sqrt(pow(b->x - a->x, power) + pow(b->y - a->y, power));
}
