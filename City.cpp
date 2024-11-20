#include "City.hpp"

#include <cmath>

double get_distance_between_cities(const City * a, const City * b) {
    constexpr int power = 2;
    return sqrt(pow(b->x - a->x, power) + pow(b->y - a->y, power));
}
