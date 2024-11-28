#pragma once
#include "BasePopulationHandler.hpp"
#include "CrossoverHandler.hpp"
#include "EvaluationHandler.hpp"
#include "MutationHandler.hpp"

/**
 * GeneticInfo is the info our genetic system needs to run.
 * This info gets populated within the run() method of our SingeltonFacade (the implementation of which is abstracted)
 */
struct GeneticInfo {
    /**
     * The first elite in the original population generated
     */
    Tour base_elite;

    /**
     * The distance of the base_elite
     */
    double base_distance{};

    /**
     * The current best distance (of the current elite)
     */
    double best_distance{};

    /**
     * Improvement factor (needed to pass to the reporting, which is performed by the evaluation handler)
     */
    double improvement_factor{};

    /**
     * Keeps track of how many iterations we've performed
     */
    int iterations{0};

    /**
     * Mutation rate is the chance of each city getting swapped in a tour that has been selected for mutation
     */
    int mutation_rate{15};

    /**
     * holds our current vector of tours
     */
    std::vector<Tour> tours;

    /**
     * true if a new elite is found in an iteration
     */
    bool new_elite_found{};
};

/**
 * Our genetic system is the overall manager of our chain of command.
 * It sets each handler's next handler and creates the chain.
 */
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

    /**
     * Handles the population of tours at each step of the chain of command
     *
     * @param population the current popoulation of tours
     * @return true if a link in the chain handled the population successfully
     */
    bool iterate_next(std::vector<Tour> & population) const;

    ~GeneticSystem() {
        delete crossover_handler;
        delete mutation_handler;
        delete evaluation_handler;
    }
};
