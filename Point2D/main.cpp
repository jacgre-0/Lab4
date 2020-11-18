#include "Point2D.h"
#include <iostream>

int main() {
    //create two points and calculate the distance between two points and print the result,
    Point2D a(5,3);
    Point2D b(8,9);

    auto dist = a.distance(b);

    std::cout << "Distance: " << dist << std::endl;

    //create a new point by using either the copy constructor or operator ( = ),
    auto c = a;
    //print the field values of the new point, 
    //and do a comparison with aand b to see which point has the same value with the newly created point
    std::cout << c.to_string() << std::endl;

    if (c == a) {
        std::cout << "The new point has the same value as point a" << std::endl;
    }

    if (c == b) {
        std::cout << "The new point has the same value as point b" << std::endl;
    }

    //create a new point by using the + operator (i.e.add two existing point objects and assign the result to a new object),
    auto d = a + b;
    //print the value of the new pointand calculate the distance between any other point with new one
    std::cout << d.to_string() << std::endl;
    std::cout << "Distane: " << d.distance(c) << std::endl;

    //compare the new point with other points to see whether the new point is really a new 
    //or has the same value some other point. (make sure that the other points’ values are not all 0)
    if (d == a) {
        std::cout << "The new point has the same value as point a" << std::endl;
    }

    if (d == b) {
        std::cout << "The new point has the same value as point b" << std::endl;
    }


    if (d == c) {
        std::cout << "The new point has the same value as point c" << std::endl;
    }

    else {
        std::cout << "The new point has a unique value" << std::endl;
    }

    return 0;
}