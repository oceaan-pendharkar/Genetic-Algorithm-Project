#include "EvaluationHandler.hpp"

bool EvaluationHandler::handle_population(std::vector<Tour> *population) {

    std::cout << "Evaluation handler reached" << std::endl;

    std::sort(population->begin(), population->end(), [](const Tour& a, const Tour& b) {
        return a.get_tour_fitness() > b.get_tour_fitness();
    });

    // for(const auto & tour : *population) {
    //      std::cout << "distance: " << tour.get_tour_distance() << " | fitness: " << tour.get_tour_fitness() << std::endl;
    // }

    //if no more handlers exist, return with success message
    if (!next_handler)
        return true;

    //else call next handler in sequence
    return next_handler->handle_population(population);
}
