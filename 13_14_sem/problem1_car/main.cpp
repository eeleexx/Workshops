///////////////////////////////////////////////////////////////////////////////
/// \file
/// \version    0.1.0
/// \date       14.02.2024
///
/// TASK DESCRIPTION
///
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
/*
Car
Define a Car struct with private attributes
for year of manufacture (year), color (color),
number of doors (count_doors), fuel level
(fuel_level) and mileage (mileage).
Implement a constructor to initialize these
attributes. Fuel level and mileage must be
the default values are 50.0 and 0.0 respectively.
Implement the drive(double distance) method.
which reduces the fuel level depending on
distance traveled and increases mileage.
  Assume that the car consumes 1 liter
  fuel for 10 km.
Implement the refuel(double amount) method to
  add fuel to the tank.
Add a stop() method that prints a message
that the car has been stopped.
Implement an info() method that prints information
about the car: year of manufacture, color, number of doors,
fuel level and mileage.
Implement methods to change colors
car and obtaining current color values,
fuel level and mileage.
In the main function, create several Car objects with different characteristics.
Test all class methods to make sure they work correctly. Try walking some distance, refueling the car, changing its color and then displaying information about it.
*/

struct Car {
    int year;
    std::string color;
    int count_doors;
    int fuel_level;
    int mileage;
    Car(int y, std::string c, int d, double f = 50.0, double dis = 0.0) {
        year = y;
        color = c;
        count_doors = d;
        fuel_level = f;
        mileage = dis;
    };

    void drive(double distance) {
      double consumptionPerkm = 0.1;
      double fuelNeeded = consumptionPerkm * distance;
      if (fuel_level >= fuelNeeded) {
        mileage += distance;
        fuel_level -= fuelNeeded;
        std::cout << "Distance driven: " << distance << " km." << "\n";
      } else {
        std::cout << "Not enough fuel!" << "\n";
      }
    }

    void refuel(double amount) {
      fuel_level += amount;
      std::cout << "Replenished: " << amount << " liters" << "\n";
    }

    void stop() {
      std::cout << "The car is stopped" << "\n";
    }

    void info() {
        std::cout << "Car Info: Year: " << year << ", Color: " << color
                  << ", Doors: " << count_doors << ", Fuel Level: " << fuel_level
                  << " liters, Mileage: " << mileage << " km." << "\n";
    }
    void changeColor(std::string newColor) {
      color = newColor;
      std::cout << "Changed color to: " << color << "\n";
    }

    void changeYear(int newYear) {
      year = newYear;
      std::cout << "Changed year to: " << year << "\n";
    }

    void changeDoors(int newDoors) {
      count_doors = newDoors;
      std::cout << "Amount of doors changed to: " << count_doors << "\n";
    }

    std::string getColor() const {
        return color;
    }

    double getFuelLevel() const {
        return fuel_level;
    }

    double getMileage() const {
        return mileage;
    }

    void print() {
        std::cout << year << ' ' << color << ' ' << count_doors << ' ' << fuel_level << ' ' << mileage << '\n';
    }
};

int main() {
  Car car1(2010, "black", 5);
      car1.drive(100);
      car1.refuel(20);
      car1.changeColor("red");
      car1.info();

      Car car2(2022, "white", 3, 60.0, 150.0);
      car2.drive(50);
      car2.changeDoors(4);
      car2.stop();
      car2.info();

}