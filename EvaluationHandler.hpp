#pragma once
#include <iostream>
#include "BasePopulationHandler.hpp"

class EvaluationHandler : public BasePopulationHandler {
public:
    /**
        Evaluates the mutated
        :return: a bool indicating successful handling of the population or not.
     */
    EvaluationHandler() = default;

    bool handle_population(std::vector<Tour> *population) override;

};