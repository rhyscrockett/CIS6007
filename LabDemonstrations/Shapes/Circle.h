#pragma once
#define _USE_MATH_DEFINES

#include <cmath>
#include "Shape.h"

class Circle : Shape {
    double radius;

public:
    // Constructors
    Circle(double _radius) : radius(_radius){}
    
    friend std::ostream& operator<<(std::ostream& out, Circle &c);

    // Copy and Move Constructors
    Circle(const Circle& v);
    Circle& operator=(const Circle &v);
    Circle(Circle &&r);
    Circle& operator=(Circle &&r);

    // Implementations for Virtual Functions
    double get_area() const {
        return 2 * M_PI * radius;
    }

    double get_perimeter_length() const {
        return M_PI * (radius * radius);
    }

    void move(const Point &to) {
        centre += to;
    } 

   void draw() const{
       get_area();
   }

    // Destructor
   ~Circle() = default;
};