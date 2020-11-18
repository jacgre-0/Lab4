#pragma once
#include "Point2D.h"

class PolyLine {
public:
    PolyLine(int length);
public:
    void add_point(Point2D point);
    PolyLine at(int index);
    void remove_point();
    bool contains(const Point2D& point);
    int get_total_points() const;
    float total_length();
    void print_coords() const;
private:
    int length;
    int numPoints{};
    Point2D* points{};
    bool isFull{};
};