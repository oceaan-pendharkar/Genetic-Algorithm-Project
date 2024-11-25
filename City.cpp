#include "City.hpp"

#include <cmath>

constexpr int TWO = 2;

double get_distance_between_cities(const City * a, const City * b) {
    return sqrt(pow(b->x - a->x, TWO) + pow(b->y - a->y, TWO));
}
