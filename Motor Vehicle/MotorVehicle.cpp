#include "MotorVehicle.h"
#include <random>

MotorVehicle::MotorVehicle(Engine engine, Body body, Owner owner, int numberOfTires)
    :
    engine(engine),
    body(body),
    owner(owner),
    numberOfTires(numberOfTires)
{
    //Create a distribution object over the range [20,50)
    std::uniform_real_distribution<float> dist(20.0f, 50.0f);
    //I am declaring eng static so that it is only seeded once. 
    //The default constructor of the engine is using a default
    //seed value so I won't have to explicitly seed it.
    static std::default_random_engine eng;

    tireDiameters = new float[numberOfTires];

    for (int i = 0; i < numberOfTires; i++) {
        //Create the actual (pseudo) random number.
        tireDiameters[i] = dist(eng);
    }
}

MotorVehicle::~MotorVehicle() {
    delete[] tireDiameters;
}

void MotorVehicle::Print() const {
    int j{};
    std::cout << "Number of tires: " << numberOfTires << std::endl;

    for (int i = 0; i < numberOfTires; i++) {
        j = i + 1;
        std::cout << "Tire diameter of tire " << j << ": " << tireDiameters[i] << std::endl;
    }

    engine.Print();
    body.Print();
    owner.Print();
}
