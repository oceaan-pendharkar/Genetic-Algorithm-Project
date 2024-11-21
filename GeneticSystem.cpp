#include "GeneticSystem.hpp"

bool GeneticSystem::iterate_next(std::vector<Tour*> & population) {
    std::pair<std::string, bool> result;

    // Calls the three handlers in a chain
    result = chain_head->handle_population(&population);

    if(result.second == true) {
        return true;
    }

    std::cout << "Genetic System failed" << std::endl;
    return false;
}