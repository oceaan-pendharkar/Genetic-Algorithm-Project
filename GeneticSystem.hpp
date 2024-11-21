#pragma once
#include "BasePopulationHandler.hpp"
#include "CrossoverHandler.hpp"
#include "EvaluationHandler.hpp"
#include "MutationHandler.hpp"

class GeneticSystem {

    BasePopulationHandler * chain_head;

    CrossoverHandler * crossover_handler;
    MutationHandler * mutation_handler;
    EvaluationHandler * evaluation_handler;

public:
    GeneticSystem() {
        // Sets up Genetic System and creates a chain of handlers
        crossover_handler = new CrossoverHandler;
        mutation_handler = new MutationHandler;
        evaluation_handler = new EvaluationHandler;

        // Sets Handler order
        chain_head = crossover_handler;
        crossover_handler->set_handler(mutation_handler);
        mutation_handler->set_handler(evaluation_handler);
    }

    bool iterate_next(std::vector<Tour*> & population);

    ~GeneticSystem() {
        delete crossover_handler;
        delete mutation_handler;
        delete evaluation_handler;
    }
};
