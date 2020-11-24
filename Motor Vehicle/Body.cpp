#include "Body.h"

Body::Body(std::string color, float width, float height)
    :
    color(color),
    width(width),
    height(height)
{}

void Body::Print() const {
    std::cout << "Color: " << color << "\nWidth: " << width << "\nHeight: " << height << std::endl;
}