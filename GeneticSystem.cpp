#include "GeneticSystem.hpp"

bool GeneticSystem::iterate_next(std::vector<Tour*> * population, int & iterations) {
    std::pair<std::string, bool> result;

    // Calls the three handlers in a chain
    result = chain_head->handle_population(population);

    if(result.second == true) {

    }

}