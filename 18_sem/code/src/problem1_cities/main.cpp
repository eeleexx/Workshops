#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

//     Main task - to implement the function fillCountries to put countries into
//     a container]
// (vector<Country> or map<std::string, Country>).

//     Intermediate steps:
//     1. Define operator< for both Cities and Countries based on their names.
//     2. Read cities as pairs <City, name of the country>.
//     3. Use the name of the country to find if there is such country in the
//     container.
//     4. Add a country to the container or a city to an existing country.

struct Coordinate
{
    double longitude;
    double latitude;
};

struct City
{
    std::string name;
    Coordinate coordinates;

    bool operator<(const City &other) const
    {
        return name < other.name;
    }
};

struct Country
{
    std::string name;
    std::set<City> cities;

    bool operator<(const Country &other) const
    {
        return name < other.name;
    }
};

void fillCountries(std::istream &inFile, std::vector<Country> &countries)
{
    std::string line, cityName, countryName;
    double latitude, longitude;

    while (std::getline(inFile, line))
    {
        std::istringstream ss(line);
        std::getline(ss, cityName, ',');
        ss >> latitude;
        ss.ignore();
        ss >> longitude;
        std::getline(ss, countryName);

        City city = {cityName, {longitude, latitude}};

        auto it =
            std::find_if(countries.begin(), countries.end(), [&](const Country &c) { return c.name == countryName; });

        if (it != countries.end())
        {
            it->cities.insert(city);
        }
        else
        {
            Country country = {countryName, {city}};
            countries.push_back(country);
        }
    }
}

int main()
{
    const std::string FILENAME = "/Users/eeleexx/workshops/18_sem/data/problem1_cities/cities.csv";
    std::ifstream inputFile;
    inputFile.open(FILENAME);
    if (inputFile)
    {
        std::cout << "OK\n";
    }

    std::vector<Country> countries;
    fillCountries(inputFile, countries);

    for (const auto &country : countries)
    {
        std::cout << "Country: " << country.name << "\n";
        for (const auto &city : country.cities)
        {
            std::cout << "  City: " << city.name << " [Longitude: " << city.coordinates.longitude
                      << ", Latitude: " << city.coordinates.latitude << "]\n";
        }
    }

    inputFile.close();

    return 0;
}
