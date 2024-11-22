#pragma once
#include <vector>
#include "Tour.hpp"

class SingletonFacade {
    static const int FIRST;
    static const int ITERATIONS;
    static const double IMPROVEMENT_FACTOR;

    /**
     * Private default constructor
     */
    SingletonFacade() = default;

public:
    /**
     * Get Instance
     *
     * Allows us to have a single static instance of SingletonFacade in our program and access it.
     * Use this instead of a constructor.
     *
     * @return the only instance of this class in the program
     */
    static SingletonFacade& get_instance() {
        static SingletonFacade instance;
        return instance;
    }

    /**
     * We must delete the copy constructor and assignment operator
     * to make this class a singleton.
     */
    SingletonFacade(SingletonFacade const&) = delete;
    void operator=(SingletonFacade const&) = delete;

    /**
     * Run
     *
     * This function will manage the complexity of running our genetic algorithm.
     */
    static void run();

    static void print_iteration(std::vector<Tour> & population, const int & iterations,
    const bool & new_elite_found, const double & improvement_factor);
};
