#pragma once
#include <iostream>

class Engine {
public:
    Engine(float sizeInLitres, int numberOfCylinders);
    void Print() const;
private:
    float sizeInLitres;
    int numberOfCylinders;
};