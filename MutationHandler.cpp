#include "MutationHandler.hpp"

std::pair<std::string, bool> MutationHandler::handle_population(std::vector<Tour *> *population) {

    // **For testing**
    std::cout << "Passing through Mutation Handler!" << std::endl;
    for(const auto & tour : *population) {
        std::cout << "distance: " << tour->get_tour_distance() << " | fitness: " << tour->get_tour_fitness() << std::endl;
    }
    std::cout << std::endl;

    //if no more handlers exist, return with success message
    if (!next_handler) {
        return std::make_pair("", true);
    }

    //else call next handler in sequence
    return next_handler->handle_population(population);
}
