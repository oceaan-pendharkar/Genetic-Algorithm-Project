#include "CrossoverHandler.hpp"

#include <chrono>

const int CrossoverHandler::ONE = 1;
const int CrossoverHandler::TWO = 2;
const int CrossoverHandler::PARENT_POOL_SIZE = 5;
const int CrossoverHandler::NUMBER_OF_PARENTS = 2;

std::pair<std::string, bool> CrossoverHandler::handle_population(std::vector<Tour *> * population) {

    std::cout << "Test: At Start of Crossover, size is population is: " << population->size() << std::endl;
    for (const auto &tour : *population) {
        if (!tour) {
            std::cout << "Error: Found a null pointer in population!" << std::endl;
            continue;
        }
        std::cout << "distance: " << tour->get_tour_distance()
                  << " | fitness: " << tour->get_tour_fitness()
                  << std::endl;
    }

    std::cout << std::endl;

    //Create a temporary container to hold the new values
    std::vector<Tour *> temp;

    //Keep the previous elite
    if (population->empty() || !(*population)[0]) {
        throw std::logic_error("Population is empty or the first element is null");
    }

    // **For testing**
    std::cout << "Elite Tour - Distance: " << (*population)[0]->get_tour_distance()
              << " | Fitness: " << (*population)[0]->get_tour_fitness() << std::endl;

    temp.push_back(new Tour(*(*population)[0]));

    std::cout << "Test: Temp Test A, size is population is: " << temp.size() << std::endl;
    for (const auto &tour : temp) {
        if (!tour) {
            std::cout << "Error: Found a null pointer in population!" << std::endl;
            continue;
        }
        std::cout << "distance: " << tour->get_tour_distance()
                  << " | fitness: " << tour->get_tour_fitness()
                  << std::endl;
    }

    //Set up number of loops required to fill new vector
    const std::size_t population_size = population->size();
    if (population_size < PARENT_POOL_SIZE * TWO) {
        throw std::invalid_argument("Population size is too small for crossover algorithm");
    }

    //Crossover Algorithm
    while (temp.size() < population_size) {

        // Set up new parents and child pointers
        Tour * parent_one = nullptr;
        Tour * parent_two = nullptr;
        Tour * child = nullptr;

        //Create a vector with ints and shuffle them to set up RNG
        std::vector<size_t> numbers;
        for (size_t i = ONE; i < population_size; i++) numbers.push_back(i);
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));

        if (numbers.size() < PARENT_POOL_SIZE * TWO) {
            throw std::logic_error("Not enough unique parents available for selection");
        }

        //Find the first Parent
        parent_one = (*population)[numbers[0]];
        for (int i = 1; i < PARENT_POOL_SIZE; i++) {
            if ((*population)[numbers[i]]->get_tour_fitness() > parent_one->get_tour_fitness()) {
                parent_one = (*population)[numbers[i]];
            }
        }

        //Find the second parent
        parent_two = (*population)[numbers[PARENT_POOL_SIZE]];
        for (int i = PARENT_POOL_SIZE + ONE; i < TWO * PARENT_POOL_SIZE; i++) {
            if ((*population)[numbers[i]]->get_tour_fitness() > parent_two->get_tour_fitness()) {
                parent_two = (*population)[numbers[i]];
            }
        }

        //Obtain the number of cities visted
        std::size_t size_cities = parent_one->get_number_of_cities();
        if (size_cities > static_cast<std::size_t>(std::numeric_limits<int>::max())) {
            throw std::overflow_error("size_cities is too large to fit in an int");
        }
        if (size_cities <= 1) {
            throw std::logic_error("Not enough cities for crossover operation");
        }
        int number_of_cities = static_cast<int>(size_cities);

        if (number_of_cities <= 1) {
            throw std::logic_error("Not enough cities for crossover operation");
        }

        //Pick a random index for crossing the next parent
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<> distribution(ONE, number_of_cities - ONE);
        int cross_index = distribution(generator);

        //Get the list of cities from both parents
        std::vector<City *> parent_one_cities = parent_one->get_cities();
        std::vector<City *> parent_two_cities = parent_two->get_cities();

        // Initialize the child
        std::vector<City *> empty;
        child = new Tour(empty);

        //Push cities from Parent One up to the index
        for (int i = 0; i < cross_index; i++) {
            child->push_city(parent_one_cities[i]);
        }
        //Push cities from Parent Two up to the index
        for (int i = cross_index; i < number_of_cities; i++) {
            child->push_city(parent_two_cities[i]);
        }

        //Add newly created Child to the temporary vector
        temp.push_back(child);
    }

    std::cout << "Test: Temp Test B, size is population is: " << temp.size() << std::endl;
    for (const auto &tour : temp) {
        if (!tour) {
            std::cout << "Error: Found a null pointer in population!" << std::endl;
            continue;
        }
        std::cout << "distance: " << tour->get_tour_distance()
                  << " | fitness: " << tour->get_tour_fitness()
                  << std::endl;
    }

    //Delete previous values
    for (Tour* tour : *population) {
        delete tour;
    }
    population->clear();

    // Replace contents with temp vector
    *population = std::move(temp);

    std::cout << "Test: At End of Crossover, size is population is: " << population->size() << std::endl;
    for (const auto &tour : *population) {
        if (!tour) { // Null pointer check
            std::cout << "Error: Found a null pointer in population!" << std::endl;
            continue;
        }
        std::cout << "distance: " << tour->get_tour_distance()
                  << " | fitness: " << tour->get_tour_fitness()
                  << std::endl;
    }
    std::cout << std::endl;

    //if no more handlers exist, return with success message
    if (!next_handler) {
        return std::make_pair("", true);
    }

    //else call next handler in sequence
    return next_handler->handle_population(population);
}
