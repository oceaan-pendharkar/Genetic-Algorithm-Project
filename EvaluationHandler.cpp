#include "EvaluationHandler.hpp"

std::pair<std::string, bool> EvaluationHandler::handle_population(std::vector<Tour> *population) {

    //if no more handlers exist, return with success message
    if (!next_handler)
        return std::make_pair("", true);

    //else call next handler in sequence
    return next_handler->handle_population(population);
}
