#include "MutationHandler.hpp"

std::pair<std::string, bool> MutationHandler::handle_population(std::vector<Tour *> *population) {

    // //Create a temporary container to hold the new values
    // std::vector<Tour *> temp;
    //
    // //Keep the previous elite
    // temp.push_back((*population)[0]);
    //
    // //Cross parents until the new vector is filled
    //
    // //Delete previous values
    // for (Tour* tour : *population) {
    //     delete tour;
    // }
    // population->clear();
    //
    // // Replace contents with temp vector
    // *population = std::move(temp);

    //if no more handlers exist, return with success message
    if (!next_handler) {
        return std::make_pair("", true);
    }

    //else call next handler in sequence
    return next_handler->handle_population(population);
}
