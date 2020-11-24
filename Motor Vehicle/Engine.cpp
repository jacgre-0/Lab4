#include "Engine.h"
#include <iostream>

Engine::Engine(float sizeInLitres, int numberOfCylinders)
    :
    sizeInLitres(sizeInLitres),
    numberOfCylinders(numberOfCylinders)
{}

void Engine::Print() const {
    std::cout << "Size (In litres): " << sizeInLitres << "\nNumber of cylinders: " << numberOfCylinders << std::endl;
}