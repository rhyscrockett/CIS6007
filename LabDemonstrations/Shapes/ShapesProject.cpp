#include <iostream>
#include <vector>
#include <memory>

#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"

int main() {
    Rectangle rect(4.0, 8.5);
    std::cout << "Rectangle Area: " << rect.get_area() << std::endl;
    std::cout << "Rectangle Perimeter Length: " << rect.get_perimeter_length() << std::endl;
    Point p1 (1, 2);
    rect.move(p1);
    rect.draw();

    Circle circ(18.9);
    std::cout << "Circle Area: " << circ.get_area() << std::endl;
    std::cout << "Circle Perimeter Length: " << circ.get_perimeter_length() << std::endl;
    Point c1(3, 4);
    circ.move(c1);
    circ.draw();
}