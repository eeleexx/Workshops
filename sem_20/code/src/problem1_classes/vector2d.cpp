#include <iostream>
#include <random>
#include <set>

class Vector3D
{
public:
    double _x, _y, _z;

    // Task 1, empty constructor
    Vector3D() : _x(0.0), _y(0.0), _z(0.0) {}

    // Task 2, constructor with arguments
    Vector3D(double x, double y, double z) : _x(x), _y(y), _z(z) {}

    // Task 3, copy constructor
    Vector3D(const Vector3D& v2) : _x(v2._x), _y(v2._y), _z(v2._z) {}

    // Task 4. Getters and setters (define for other attributes)
    // getter
    double getX() const { return _x; }

    // setter
    void setX(double x) { _x = x; }

    double getY() const { return _y; }
    void setY(double y) { _y = y; }

    double getZ() const { return _z; }
    void setZ(double z) { _z = z; }

    // Task 8. Magnitude
    double magnitude() const {
        return sqrt(_x * _x + _y * _y + _z * _z);
    }
};

// Task 5. Operator +
Vector3D operator+(const Vector3D& v1, const Vector3D& v2) {
    return Vector3D(v1._x + v2._x, v1._y + v2._y, v1._z + v2._z);
}

// Task 6. Operator * (dot product)
double operator*(const Vector3D& v1, const Vector3D& v2) {
    return v1._x * v2._x + v1._y * v2._y + v1._z * v2._z;
}

// Task 7. Operator * (scalar product)
Vector3D operator*(const Vector3D& v1, double d) {
    return Vector3D(v1._x * d, v1._y * d, v1._z * d);
}

// Task 9. Operator <
bool operator<(const Vector3D& v1, const Vector3D& v2) {
    return v1.magnitude() < v2.magnitude();
}

// Task 10. Operator << (printing)
std::ostream& operator<<(std::ostream& out, const Vector3D& v) {
    out << "(" << v._x << ", " << v._y << ", " << v._z << ")";
    return out;
}

// Task 11. Operator >> (reading)
std::istream& operator>>(std::istream& in, Vector3D& v) {
    in >> v._x >> v._y >> v._z;
    return in;
}

void fillMultiset(size_t n, std::multiset<Vector3D>& mset) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distr(-1, 1);

    for (size_t i = 0; i < n; ++i) {
        double x = distr(gen);
        double y = distr(gen);
        double z = distr(gen);
        mset.insert(Vector3D(x, y, z));
    }
}

void printMultiset(const std::multiset<Vector3D>& mset) {
    for (const auto& v : mset) {
        std::cout << v << std::endl;
    }
}

double calcAverageMagnitude(const std::multiset<Vector3D>& mset) {
    double sum = 0;
    for (const auto& v : mset) {
        sum += v.magnitude();
    }
    return sum / mset.size();
}

int main() {
    std::multiset<Vector3D> s;
    const size_t setSize = 100;
    fillMultiset(100, s);

    std::cout << "Multiset contents:" << std::endl;
    printMultiset(s);

    double averageMagnitude = calcAverageMagnitude(s);
    std::cout << "Average magnitude is " << averageMagnitude << std::endl;

    return 0;
}