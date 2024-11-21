#pragma once
#include <iostream>
#include <string>
#include "BasePopulationHandler.hpp"

class MutationHandler : public BasePopulationHandler {
public:
    /*
        Creates two sets of "Parent" tours and crosses them to generate new tours
        :param population: a vector of candidate tours
        :return: a tuple where the first element is a string stating the
        outcome and the reason, and the second a bool indicating
        successful handling of the form or not.
     */
    MutationHandler() = default;

    std::pair<std::string,bool> handle_population(std::vector<Tour*> * population) override;

};