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
