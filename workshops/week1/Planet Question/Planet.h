#pragma once

#include <iostream>
#include <string>

using namespace std;

class Planet{

private:
  double 			mass;
  double			distance_to_sun;
  float			        obliquity;
  string 			planet_name;
  
public:
  // Constructor.
  Planet(const double _mass, const double _distance, const float _obliquity, const string _name):
    mass(_mass), distance_to_sun(_distance), obliquity(_obliquity), planet_name(_name) {
    std::cout << "Planet constructor." << std::endl;
  }

  // Supressing the copy and move constructors and assignment operators.
  // Copy constructor.
  Planet(const Planet& p) = delete;

  // Copy Assignment.
  Planet& operator=(const Planet& p) = delete;

  // Move Assignment.
  Planet(Planet&& p) = delete;

  // Move Assignment Operator.
  Planet& operator=(const Planet&& p) = delete;
  

  //-------------
  // getters and setters
  //-------------

  void set_mass(const double _mass) {
    mass = _mass;
  }

  double get_mass() const {
    return mass;
  }

  void set_distance_to_sun(const double _distance) {
    distance_to_sun = _distance;
  }

  double get_distance_to_sun() const {
    return distance_to_sun;
  }

  void set_obliquity(const float _obliquity) {
    obliquity = _obliquity;
  }

  double get_obliquity() const {
    return obliquity;
  }

  void set_planet_name(const string  _name) {
    planet_name = _name;
  }

  string get_planet_name() const {
    return planet_name;
  }
  
  // Pure virtual function.
  virtual string get_planetype() const = 0;

  // Base class destructor has to be virtual.
  virtual ~Planet() {
    std::cout << "Planet destructor." << std::endl;
  };
};
