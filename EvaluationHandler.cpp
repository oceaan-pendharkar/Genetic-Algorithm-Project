#include "EvaluationHandler.hpp"

std::pair<std::string, bool> EvaluationHandler::handle_population(std::vector<Tour> *population) {

    std::sort(population->begin(), population->end(), [](const Tour& a, const Tour& b) {
        return a.get_tour_fitness() > b.get_tour_fitness();
    });

    //if no more handlers exist, return with success message
    if (!next_handler)
        return std::make_pair("", true);

    //else call next handler in sequence
    return next_handler->handle_population(population);
}
