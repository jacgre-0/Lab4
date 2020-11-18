#include "Polyline.h"
#include <iostream>

PolyLine::PolyLine(int length)
    :
    length(length)
{
    points = new Point2D[length];
}

void PolyLine::add_point(Point2D point) {
    if (isFull) {
        std::cout << "Error! Polyline is already full." << std::endl;
        return;
    }

    points[numPoints] = point;

    if (++numPoints == length) {
        isFull = true;
    }
}

Point2D PolyLine::at(int index) const {

    if (index < numPoints || index < 0) {
        return points[index];
    }
    std::cout << "Error! index is not valid" << std::endl;
    return Point2D();
}

bool PolyLine::contains(const Point2D& point) {
    for (int i = 0; i < length; i++) {
        if (points[i] == point)
            return true;
    }
    return false;
}

int PolyLine::get_total_points() const {
    return numPoints;
}

float PolyLine::total_length() const {
    float dist{};

    for (int i = 0; i < numPoints-1; i++) {
        dist += points[i].distance(points[i + 1]);
    }
    return dist;
}

void PolyLine::print_coords() const {
    for (int i = 0; i < numPoints; i++) {
        std::cout << points[i].to_string() << std::endl;
    }
}
