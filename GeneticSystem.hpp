#pragma once
#include "BasePopulationHandler.hpp"
#include "CrossoverHandler.hpp"
#include "EvaluationHandler.hpp"
#include "MutationHandler.hpp"

struct GeneticInfo {
    Tour base_elite;
    double base_distance{};
    double best_distance{};
    double improvement_factor{};
    int iterations{0};
    int mutation_rate{15};
    std::vector<Tour> tours;
    bool new_elite_found{};
};

class GeneticSystem {

    BasePopulationHandler * chain_head;

    CrossoverHandler * crossover_handler;
    MutationHandler * mutation_handler;
    EvaluationHandler * evaluation_handler;

public:
    explicit GeneticSystem(GeneticInfo * data) {
        // Sets up Genetic System and creates a chain of handlers
        crossover_handler = new CrossoverHandler;
        mutation_handler = new MutationHandler(data->mutation_rate);
        evaluation_handler = new EvaluationHandler(data);

        // Sets Handler order
        chain_head = crossover_handler;
        crossover_handler->set_handler(mutation_handler);
        mutation_handler->set_handler(evaluation_handler);
    }

    bool iterate_next(std::vector<Tour> & population) const;

    ~GeneticSystem() {
        delete crossover_handler;
        delete mutation_handler;
        delete evaluation_handler;
    }
};
