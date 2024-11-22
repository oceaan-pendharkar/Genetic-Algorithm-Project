#pragma once
#include <string>
#include <vector>

#include "Tour.hpp"

class BasePopulationHandler {
public:
    BasePopulationHandler * next_handler = nullptr;

    BasePopulationHandler() = default;
    BasePopulationHandler(BasePopulationHandler * handler) : next_handler(handler) {}
    virtual ~BasePopulationHandler() = default;

    /*
        Each handler would have a specific implementation of how it
        processes a form.
        :param population: a vector of candidate tours
        :return: a tuple where the first element is a string stating the
        outcome and the reason, and the second a bool indicating
        successful handling of the form or not.
     */
    virtual std::pair<std::string,bool> handle_population(std::vector<Tour> * population) = 0;

    /*
        Each handler can invoke another handler at the end of it's
        processing of the form. This handler needs to implement the
        BasePopulationHandler interface.
        :param handler: a BasePopulationHandler
     */
    void set_handler(BasePopulationHandler * handler) { next_handler = handler;}
};
