#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <initializer_list>
#include <vector>

class Point {

private:
    int x;
    int y;

public:
    // Constructors
    Point(const int _x = 0, const int _y = 0) : x(_x), y(_y) {}

    // Copy Constructor
    Point(const Point& rhs) : x(rhs.x), y(rhs.y) {}

    
    // Copy Assignment
    Point& operator=(const Point& rhs) {
        if (this != &rhs) {
            x = rhs.x;
            y = rhs.y;
        }
        return *this;
    }

    void setX(int _x) { x = _x; }
    void setY(int _y) { y = _y; }

    int getX() const { return x; }
    int getY() const { return y; }

    Point& operator+=(const Point& rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    Point operator-(const Point& rhs) {
        Point p;
        p.x = x - rhs.x;
        p.y = y - rhs.y;
        return p;
    }

    Point operator+(const Point& rhs) {
        Point p;
        p.x = x + rhs.x;
        p.y = y + rhs.y;
        return p;
    }

    void operator-=(const Point& rhs) {
        x = x - rhs.x;
        y = y - rhs.x;
    }

    friend bool operator==(const Point& lhs, const Point& rhs);
    friend bool operator!=(const Point& lhs, const Point& rhs);
    friend std::ostream& operator<<(std::ostream& out, const Point& p);
    friend bool operator+(const Point& lhs, const Point& rhs);
    friend bool operator-(const Point& lhs, const Point& rhs);
    friend bool operator+=(const Point& lhs, const Point& rhs);
    friend bool operator-=(const Point& lhs, const Point& rhs);

    // tostring method
    std::string tostring() const {
        return "( " + std::to_string(x) + " , " + std::to_string(y) + " )";
    }

    // Destructor
    ~Point() = default;
};