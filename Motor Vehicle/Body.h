#pragma once
#include <string>
#include <iostream>

class Body {
public:
    Body(std::string color, float width, float height);
    void Print() const;
private:
    std::string color;
    float width;
    float height;
};
