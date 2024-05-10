#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class SingletonExample {
private:
    static SingletonExample instance;
    int data;
    SingletonExample() : data(0) {} // private constructor

public:
    static SingletonExample& getInstance() {
        return instance;
    }

    int getData() const {
        return data;
    }

    void setData(int value) {
        data = value;
    }
};

SingletonExample SingletonExample::instance; // define the static instance

int main() {
    SingletonExample& singleton = SingletonExample::getInstance();
    singleton.setData(10);
    std::cout << "Singleton data: " << singleton.getData() << std::endl;
    return 0;
}