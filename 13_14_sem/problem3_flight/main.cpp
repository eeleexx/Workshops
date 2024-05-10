///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       30.01.2024
///
/// TASK DESCRIPTION
///
/// Describe the “Flight” structure with flight identifier fields,
/// departure airport, destination airport and departure time
/// (structure “Time”). Write a function that takes as input
/// vector of flights and airport name displaying information
/// first about all flights arriving at the specified airport, and then
/// about all flights departing from this airport.
///
#include <iostream>
#include <fstream> 
#include <vector>

struct Time {
    int hour, minute;
};

struct Flight {
    std::string flight_identifier;
    std::string departure_airport;
    std::string destination_airport;
    Time departure_time;

    Flight(std::string id, std::string departure, std::string arrival, Time time)
        : flight_identifier(id), departure_airport(departure), destination_airport(arrival), departure_time(time) {}

    static void display_flights(const std::vector<Flight> flights, std::string airportName) {
        std::cout << "Arriving at " << airportName << "\n";
        for (auto flight : flights) {
            if (flight.destination_airport == airportName) {
                std::cout << "Flight " << flight.flight_identifier << " to " << flight.destination_airport << " at " << flight.departure_time.hour << ":" << flight.departure_time.minute << "\n";
            }
        }
        std::cout << "\n" << "Departing flights from " << airportName << ":\n";
        for (auto flight : flights) {
        if (flight.departure_airport == airportName) {
            std::cout << "Flight " << flight.flight_identifier << " to " << flight.destination_airport << " at " << flight.departure_time.hour << ":" << flight.departure_time.minute << "\n";
            }
        }
    }
};

int main() {
    
    std::vector<Flight> flights = {
        Flight("AB123", "JFK", "LAX", Time{15, 30}),
        Flight("CD456", "LAX", "JFK", Time{17, 45}),
        Flight("EF789", "JFK", "MIA", Time{9, 15}), 
        Flight("PI736", "JFK", "LAX", Time{0, 0}),
        Flight("XK626", "LAX", "MIA", Time{1, 15}),
        Flight("KQ339", "MIA", "ORD", Time{2, 30}),
        Flight("DU389", "ORD", "ATL", Time{3, 45}),
        Flight("JA533", "ATL", "DFW", Time{4, 0}),
        Flight("PZ803", "DFW", "DEN", Time{5, 15}),
        Flight("BT194", "DEN", "SFO", Time{6, 30}),
        Flight("TC675", "SFO", "SEA", Time{7, 45}),
        Flight("CJ099", "SEA", "LAS", Time{8, 0}),
        Flight("EO461", "LAS", "JFK", Time{9, 15}),       
    };

    Flight::display_flights(flights, "JFK");

    return 0;
}