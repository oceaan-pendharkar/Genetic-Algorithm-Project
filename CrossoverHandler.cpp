#include "CrossoverHandler.hpp"

#include <chrono>

const int CrossoverHandler::ONE = 1;
const int CrossoverHandler::TWO = 2;
const int CrossoverHandler::PARENT_POOL_SIZE = 5;

bool CrossoverHandler::handle_population(std::vector<Tour> *population) {
    // Add the current elite to crossover_population
    crossover_population.push_back(population->front());

    //Set up number of loops required to fill new vector
    const std::size_t population_size = population->size();
    if (population_size < PARENT_POOL_SIZE * TWO) {
        throw std::invalid_argument("Population size is too small for crossover algorithm");
    }

    //Crossover Algorithm
    while (crossover_population.size() < population_size) {
        generate_child(population, population_size);
    }

    // Replace contents of population and clear crossover vector
    *population = crossover_population;
    crossover_population.clear();

    //if no more handlers exist, return with success message
    if (!next_handler) {
        return true;
    }

    //else call next handler in sequence
    return next_handler->handle_population(population);
}

void CrossoverHandler::generate_child(std::vector<Tour> * population, size_t size) {

    //Create a vector of integers and shuffle them to set up RNG
    std::vector<size_t> numbers;
    for (size_t i = ONE; i < size; i++) numbers.push_back(i);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

    //Find the first Parent
    Tour parent_one = (*population)[numbers[0]];
    for (int i = 1; i < PARENT_POOL_SIZE; i++) {
        if ((*population)[numbers[i]].get_tour_fitness() > parent_one.get_tour_fitness()) {
            parent_one = (*population)[numbers[i]];
        }
    }

    //Find the second parent
    Tour parent_two = (*population)[numbers[PARENT_POOL_SIZE]];
    for (int i = PARENT_POOL_SIZE + ONE; i < TWO * PARENT_POOL_SIZE; i++) {
        if ((*population)[numbers[i]].get_tour_fitness() > parent_two.get_tour_fitness()) {
            parent_two = (*population)[numbers[i]];
        }
    }

    //Pick a random index for crossing the next parent
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(ONE, parent_one.get_number_of_cities() - ONE);
    int cross_index = distribution(generator);

    //Get the list of cities from both parents
    std::vector<City *> parent_one_cities = parent_one.get_cities();
    std::vector<City *> parent_two_cities = parent_two.get_cities();

    //Initialize the new child
    Tour child;

    //Push cities from Parent One up to the index
    for (int i = 0; i < cross_index; i++) {
        child.push_city(parent_one_cities[i]);
    }
    //Push cities from Parent Two up to the index
    //we need to start from index 0 again to fill the child with all the cities parent 1 didn't populate
    for (int i = 0; i < parent_two.get_number_of_cities(); i++) {
        if (!child.contains_city_with_name(parent_two_cities[i]->get_name())) {
            child.push_city(parent_two_cities[i]);
        }
    }

    //Push the newly created child onto crossover vector
    crossover_population.push_back(child);
}

