#pragma once
#include "Owner.h"
#include "Engine.h"
#include "Body.h"

class MotorVehicle {
public:
    MotorVehicle(Engine engine, Body body, Owner owner, int numberOfTires);
    ~MotorVehicle();
public:
    void Print() const;
private:
    Engine engine;
    Body body;
    Owner owner;

    float* tireDiameters;
    int numberOfTires;
};