#pragma once

#include "Planet.h"

using namespace std;

// Create a new obj from class planet.
class GasGiant : public Planet {

private:
    const string planet_type = "gas giant";

public:
  GasGiant(const double _mass, const double _distance, const float _obliquity, const string _name) :
    Planet(_mass, _distance, _obliquity, _name){
    std::cout << "Gas Giant constructor." << std::endl;
  }

  
  // Derived class overriding the virtual function from the base class Planet.
  string get_planetype() const {
    return planet_type;
  }

  // Destructor of the derived class.
  ~GasGiant(){
    std::cout << "Gas Giant destructor." << std::endl;
  }
};
