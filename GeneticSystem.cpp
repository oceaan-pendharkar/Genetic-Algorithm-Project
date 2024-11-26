#include "GeneticSystem.hpp"

bool GeneticSystem::iterate_next(std::vector<Tour> & population) const {
    // Calls the three handlers in a chain
    bool result = chain_head->handle_population(&population);

    if(result == true) {
        return true;
    }

    std::cout << "Genetic System failed" << std::endl;
    return false;
}
