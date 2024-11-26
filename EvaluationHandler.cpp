#include "EvaluationHandler.hpp"

#include <iomanip>

#include "GeneticSystem.hpp"

constexpr int FIRST = 0;
constexpr int SIX = 6;

void print_iteration(const std::vector<Tour> & population, const int & iterations,
                     const bool & new_elite_found, const double & improvement_factor);

bool EvaluationHandler::handle_population(std::vector<Tour> *population) {

    std::sort(population->begin(), population->end(), [](const Tour& a, const Tour& b) {
        return a.get_tour_fitness() > b.get_tour_fitness();
    });

    // If new Elite is found, set the new values
    if (data->tours[FIRST].get_tour_distance() < data->best_distance) {
        data->new_elite_found = true;
        data->best_distance = data->tours[FIRST].get_tour_distance();
        data->improvement_factor = data->base_distance / data->best_distance;
    } else {
        data->new_elite_found = false;
    }

    // Print the new values
    print_iteration(data->tours, data->iterations++, data->new_elite_found, data->improvement_factor);

    //if no more handlers exist, return with success message
    if (!next_handler)
        return true;

    //else call next handler in sequence
    return next_handler->handle_population(population);
}

void print_iteration(const std::vector<Tour> & population, const int & iterations,
                     const bool & new_elite_found, const double & improvement_factor) {
    std::cout << "Iteration: " << iterations << std::endl;

    if (new_elite_found) {
        std::cout << "NEW ELITE FOUND:" << std::endl;
    }

    std::cout << "Distance: " << std::fixed << std::setprecision(2)
        << population[FIRST].get_tour_distance() << std::endl;

    if (!new_elite_found) {
        std::cout << "Best non-elite distance: " << std::fixed << std::setprecision(2)
            << population[FIRST].get_tour_distance() << std::endl;
    }
    std::cout << "Improvement over base: " << std::fixed << std::setprecision(SIX)
        << improvement_factor << std::endl << std::endl;
}
