#include "MutationHandler.hpp"

std::pair<std::string, bool> MutationHandler::handle_population(std::vector<Tour> *population) {

    //**TO DO: Implement Mutation Logic**

    //if no more handlers exist, return with success message
    if (!next_handler) {
        return std::make_pair("", true);
    }

    //else call next handler in sequence
    return next_handler->handle_population(population);
}
