#include <cmath>
#include <iostream>
#include <vector>

const double PI = 3.1415;
/*
Create a programming task that involves designing a class hierarchy for geometric shapes, specifically
 circles and rectangles, with the capability to calculate their area. At the base of this hierarchy is
 an abstract class named `Shape`, which includes protected variables `x` and `y` representing the coordinates
 of the shape's center, and a pure virtual method `area()` for calculating the area. Derived from `Shape`
 are the classes `Circle` and `Rectangle`, each implementing the `area()` method according to their unique
 properties: radius for the circle and width and height for the rectangle. In the main function of the program,
 instances of a circle and a rectangle are to be created, their areas calculated, and the results displayed on
 the screen. Afterward, the allocated memory should be properly freed. The task is to write the necessary
 classes and the main function, adhering to the principles of inheritance and polymorphism in C++.
 * */
const double PI = 3.1415;

class Shape {
 protected:
  double x, y;

 public:
  Shape(double x, double y) : x(x), y(y) {}
  virtual double area() const = 0;
  virtual ~Shape() {} // Virtual destructor to ensure proper destruction of derived objects
};

class Circle : public Shape {
 private:
  double radius;

 public:
  Circle(double r, double x, double y) : Shape(x, y), radius(r) {}
  double area() const override { return PI * radius * radius; }
};

class Rectangle : public Shape {
 private:
  double width, height;

 public:
  Rectangle(double w, double h, double x, double y) : Shape(x, y), width(w), height(h) {}
  double area() const override { return width * height; }
};

int main() {
  std::vector<std::unique_ptr<Shape>> shapes;

  shapes.push_back(std::make_unique<Circle>(5.0, 1.0, 2.0));
  shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0, 3.0, 4.0));

  for (const auto& shape : shapes) {
    std::cout << "Area: " << shape->area() << std::endl;
  }

  return 0;
}