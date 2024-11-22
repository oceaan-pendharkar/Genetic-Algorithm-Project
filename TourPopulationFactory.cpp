#include "TourPopulationFactory.hpp"
#include "city.hpp"
#include <iostream>
#include <random>
using namespace std;

constexpr double ZERO = 0;
constexpr double MAP_BOUNDARY = 1000;
constexpr int MINIMUM_SIZE = 10;

/**
 * Initializing the random device outside the function scope to avoid issues
 */
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<double> dist(ZERO, MAP_BOUNDARY);

/**
 * Generate Coordinate : a helper function
 * Returns a city coordinate
 * @return a coordinate for a city, a double
 */
double generate_coordinate() {
    return dist(gen);
}

TourPopulationFactory::TourPopulationFactory() {
    cout << "How many cities would you like to include in your population?" << endl;
    cin >> this->cities_in_tour;
    while (cities_in_tour < MINIMUM_SIZE) {
        cout << "Please enter a number larger than 10" << endl;
        cin >> this->cities_in_tour;
    }
    cout << "How many cities should we visit?" << endl;
    cin >> this->population_size;
    while (population_size < MINIMUM_SIZE) {
        cout << "Please enter a number larger than 10" << endl;
        cin >> this->population_size;
    }
}

std::vector<Tour> TourPopulationFactory::createPopulation() const {

    // Populate a list of city names and shuffle the list
    std::vector<std::string> canadian_cities = {
        "Abbotsford", "Airdrie", "Ajax", "Amherstburg", "Aurora",
        "Barrie", "Belleville", "Brampton", "Brantford", "Burlington",
        "Calgary", "Cambridge", "Charlottetown", "Chilliwack", "Colwood",
        "Dartmouth", "Delta", "Dieppe", "Drummondville", "Duncan",
        "Edmonton", "Estevan", "Etobicoke", "Fredericton", "Fort McMurray",
        "Gatineau", "Guelph", "Halifax", "Hamilton", "Kamloops",
        "Kelowna", "Kingston", "Kitchener", "Langley", "Lethbridge",
        "London", "Longueuil", "Markham", "Medicine Hat", "Mississauga",
        "Moncton", "Montreal", "Nanaimo", "New Westminster", "Niagara Falls",
        "North Bay", "North Vancouver", "Oakville", "Oshawa", "Ottawa",
        "Peterborough", "Pickering", "Prince George", "Quebec City", "Red Deer",
        "Regina", "Richmond", "Richmond Hill", "Saskatoon", "Sherbrooke",
        "St. Albert", "St. Catharines", "St. John's", "Sudbury", "Surrey",
        "Thunder Bay", "Toronto", "Trois-Rivieres", "Vancouver", "Victoria",
        "Windsor", "Winnipeg", "Yellowknife", "Yorkton"
    };
    random_device rd;
    mt19937 g(rd());
    shuffle(canadian_cities.begin(), canadian_cities.end(), g);

    vector<City*> cities;

    // create a list of cities with ids and randomly generated coordinates within our range
    for(int i=0; i<cities_in_tour; i++) {
        const double x = generate_coordinate();
        const double y = generate_coordinate();
        string name = canadian_cities[i];
        cities.push_back(new City(x, y, name));
    }

    // Create a base tour
    const Tour base_tour(cities);

    // create a list of tours based on this one tour that contains our cities
    vector<Tour> tours;
    tours.reserve(population_size);
    for (int i=0; i<population_size; i++) {
        Tour new_tour = base_tour;
        new_tour.shuffle_cities();
        tours.push_back(Tour(new_tour));
    }

    //sort the tours in decreasing level of fitness
    std::sort(tours.begin(), tours.end(), [](const Tour& a, const Tour& b) {
        return a.get_tour_fitness() > b.get_tour_fitness();
    });

    return tours;
}





