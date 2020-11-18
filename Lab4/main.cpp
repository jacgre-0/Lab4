#include "MotorVehicle.h"
int main() {
    std::string name{};
    std::string address{};
    bool allowedToDrive{};

    std::string color{};
    float width{};
    float height{};

    float sizeInLitres{};
    int numberOfcylinders{};
    int numberOfTires{};

    std::cout << "Give the owners name: ";
    std::cin >> name;


    std::cout << "Give the owners address: ";
    std::cin >> address;

    std::cout << "Is the owner allowed to drive? (1/0) ";
    std::cin >> allowedToDrive;

    std::cout << "Give the color of the body: ";
    std::cin >> color;


    std::cout << "Give the width of the body: ";
    std::cin >> width;


    std::cout << "Give the height of the body: ";
    std::cin >> height;


    std::cout << "Give the engine size in litres: ";
    std::cin >> sizeInLitres;

    std::cout << "Give the number of cylinders: ";
    std::cin >> numberOfcylinders;

    std::cout << "Give the number of tires on the vehicle: ";
    std::cin >> numberOfTires;

    MotorVehicle vehicle {
        {sizeInLitres, numberOfcylinders},
        {color, width, height},
        {name, address, allowedToDrive},
        numberOfTires
    };

    std::cout << std::endl;
    vehicle.Print();
    return 0;
}