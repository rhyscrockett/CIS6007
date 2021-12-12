#pragma once
#include "Shape.h"

class Rectangle : Shape {
    double width;
    double height;

    Point* verticies;

public:
    // Constructors
    Rectangle(double _width, double _height) : width(_width), height(_height) {}


    // Copy and Move Constructors
    Rectangle(const Rectangle& v);
    Rectangle& operator=(const Rectangle &v);
    Rectangle(Rectangle &&r);
    Rectangle& operator=(Rectangle &&r);


    // Implementations for Virtual Functions
    double get_area() const {
        return width * height;
    }

    double get_perimeter_length() const {
        return 2 * (width + height);
    }

    void move(const Point &to) {
        centre += to;
    }

    void draw() const {
        std::cout << get_area() << std::endl;
        std::cout << get_perimeter_length() << std::endl;
        std::cout << get_centre() << std::endl;
    }
    ~Rectangle() { delete[] verticies; };
};