#pragma once
#include "Shape.h"

class Rectangle : Shape {
    double width;
    double height;

    Point* vertices;

public:
    // Constructors
    Rectangle(double _width, double _height) : width(_width), height(_height) {
        vertices = nullptr;
    }
    friend std::ostream& operator<<(std::ostream& out, Rectangle &r);

    // Copy and Move Constructors
    Rectangle(const Rectangle& v);
    Rectangle& operator=(const Rectangle &v);
    Rectangle(Rectangle &&r);
    Rectangle& operator=(Rectangle &&r);

    void setX(int _width) { width = _width; }
    void setY(int _height) { height = _height; }

    int getX() const { return width; }
    int getY() const { return height; }

    // Implementations for Virtual Functions
    double get_area() const {
        return width * height;
    }

    double get_perimeter_length() const {
        return 2 * (width + height);
    }

    void move(const Point &to) const {
        centre += to;
    }

    void draw() const {
        std::cout << get_area() << std::endl;
        std::cout << get_perimeter_length() << std::endl;
        std::cout << get_centre() << std::endl;
    }

    // Destructor
    ~Rectangle() {
        if (vertices != nullptr) {
            delete[] vertices;
            vertices = nullptr;
        }
    };
};