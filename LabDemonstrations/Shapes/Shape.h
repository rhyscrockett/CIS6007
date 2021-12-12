#pragma once
#include "Point.h"

class Shape {
protected:
    Point centre;

public:
    // Virtual Methods
    virtual double get_area() const = 0;
    virtual double get_perimeter_length() const = 0;
    virtual void move(Point to);
    virtual void draw() const;

    Point get_centre() const {
        return centre;
    }

    // Destructor
    ~Shape() = default;
};
