#pragma once
#include <string>
#include <vector>

#include "Tour.hpp"

/**
 * Base Population Handler
 *
 * Interface that sets up the Chain of Responsibility for Genetic System
 */
class BasePopulationHandler {
public:
    BasePopulationHandler * next_handler = nullptr;

    BasePopulationHandler() = default;
    BasePopulationHandler(BasePopulationHandler * handler) : next_handler(handler) {}
    virtual ~BasePopulationHandler() = default;

    /**
        Each handler would have a specific implementation of how it
        processes the vector of candidate tours
        :param population: a vector of candidate tours
        :return: a tuple where the first element is a string stating the
        outcome and the reason, and the second a bool indicating
        successful handling of the form or not.
     */
    virtual bool handle_population(std::vector<Tour> *population) = 0;

    /**
        Each handler can invoke another handler at the end of it's
        processing of the vector of candidate tours. This handler needs to implement the
        BasePopulationHandler interface.
        :param handler: a BasePopulationHandler
     */
    void set_handler(BasePopulationHandler * handler) { next_handler = handler;}
};
