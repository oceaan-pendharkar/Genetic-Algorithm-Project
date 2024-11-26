#pragma once
#include <iostream>
#include "BasePopulationHandler.hpp"

struct GeneticInfo;

class EvaluationHandler : public BasePopulationHandler {
    GeneticInfo * data{};
public:
    EvaluationHandler() = default;

    /**
     *
     * @param data our GeneticInfo to update and evaluate our genetic algorithm at each iteration
     */
    explicit EvaluationHandler(GeneticInfo * data):data(data){}

    /**
        Evaluates the mutated
        :return: a bool indicating successful handling of the population or not.
     */
    bool handle_population(std::vector<Tour> *population) override;


};
