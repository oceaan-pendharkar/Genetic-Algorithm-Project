#pragma once
class SingletonFacade {
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
};