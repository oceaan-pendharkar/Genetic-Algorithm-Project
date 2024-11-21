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

    GeneticSystem() {
        crossover_handler = new CrossoverHandler;
        mutation_handler = new MutationHandler;
        evaluation_handler = new EvaluationHandler;
    }

    bool iterate_next(std::vector<Tour*> * population, int & iterations);

    ~GeneticSystem() {
        delete crossover_handler;
        delete mutation_handler;
        delete evaluation_handler;
    }
};
