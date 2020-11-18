#include "Polyline.h"
#include <iostream>

int main() {
    Point2D p1{ 1,2 };
    Point2D p2{ 3,2 };
    {
        PolyLine polyLine(5);
        //Add some points
        polyLine.add_point(new Point2D(1, 2));
        polyLine.add_point(new Point2D(3, 1));

        //Check if the polyline contains some points
        std::cout << std::boolalpha << polyLine.contains(p1) << std::endl; //true
        std::cout << std::boolalpha << polyLine.contains(p2) << std::endl; //false
        //Print the total length (distance) of the polyline
        std::cout << '\n' << polyLine.total_length() << std::endl;
        //Print number of points in the polyline
        std::cout << "Number of points: " << polyLine.get_total_points() << std::endl;
        //print all the points coords
        polyLine.print_coords();

        std::cout << std::endl;
        //Remove a point and print the coord and total length again
        polyLine.remove_point();
        std::cout << "Coords "; polyLine.print_coords();
        std::cout << "Distance: " << polyLine.total_length() << std::endl;

        std::cout << std::endl;

        //Try to add to many points
        polyLine.add_point(new Point2D(3, 5));
        polyLine.add_point(new Point2D(7, 9));
        polyLine.add_point(new Point2D(8, 10));
        polyLine.add_point(new Point2D(3, 4));
        polyLine.add_point(new Point2D(2, 9));

        //Print Distance, number of points and coords
        std::cout << "Distance: " << polyLine.total_length() << std::endl;
        std::cout << "Number of points: " << polyLine.get_total_points() << std::endl;
        std::cout << "Coords: " << std::endl; polyLine.print_coords();

        std::cout << std::endl;

        //Try to remove to many points
        polyLine.remove_point();
        polyLine.remove_point();
        polyLine.remove_point();
        polyLine.remove_point();
        polyLine.remove_point();
        polyLine.remove_point();

        //Print Distance, number of points and coords
        std::cout << "Distance: " << polyLine.total_length() << std::endl;
        std::cout << "Number of points: " << polyLine.get_total_points() << std::endl;
        std::cout << "Coords: " << std::endl; polyLine.print_coords();
    }
    std::cin.get();
}