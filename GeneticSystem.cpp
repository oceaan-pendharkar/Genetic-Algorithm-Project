#include "GeneticSystem.hpp"

bool GeneticSystem::iterate_next(std::vector<Tour> & population) const {
    // Calls the three handlers in a chain
    std::pair<std::string, bool> result = chain_head->handle_population(&population);

    if(result.second == true) {
        return true;
    }

    std::cout << "Genetic System failed" << std::endl;
    return false;
}
