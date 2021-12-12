#pragma once
#include "Point.h"

class Shape {
protected:
    Point centre;

public:
    virtual double get_area() const = 0;
    virtual double get_perimeter_length() const = 0;
    virtual void move() const;
    virtual void draw() const;

    Point get_centre() const {
        return centre;
    }

    ~Shape() {}
};
