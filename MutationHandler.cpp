#include "MutationHandler.hpp"

constexpr int ONE = 1;
constexpr int ONE_HUNDRED = 100;

bool MutationHandler::handle_population(std::vector<Tour> *population) {
    // for (const auto & i : *population) {
    //     for (int j=0; j<i.get_number_of_cities(); j++) {
    //         std::cout << i.get_city_name(j) << " ";
    //     }
    //     std::cout << std::endl;
    // }

    //fill mutation population
    for(const auto & i : *population) {
        mutation_population.push_back(i);
    }

    //seed random number generator
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(ONE, ONE_HUNDRED);

    //mutate 1/4 of the population
    for(size_t i = 0; i < mutation_population.size(); i++) {
        //only mutate every 4th tour in the population
        if(i % 4 == 0) {
            for(int j = 0; j<mutation_population[i].get_number_of_cities() - 1; j++) {
                //Pick a random mutation value for each city (if value < MUTATION_RATE, swap with adjacent city)
                const int mutation_value = distribution(generator);
                if(mutation_value < MUTATION_RATE) {
                    mutation_population[i].swap_cities(j, j+1);
                }
            }
        }
    }

    *population = mutation_population;
    mutation_population.clear();

    // std::cout << "after mutation: " << std::endl;
    // for (const auto & i : *population) {
    //     for (int j=0; j<i.get_number_of_cities(); j++) {
    //         std::cout << i.get_city_name(j) << " ";
    //     }
    //     std::cout << std::endl;
    // }


    //if no more handlers exist, return with success message
    if (!next_handler) {
        return true;
    }

    //else call next handler in sequence
    return next_handler->handle_population(population);
}
