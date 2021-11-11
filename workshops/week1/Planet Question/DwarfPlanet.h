#pragma once

#include "Planet.h"

class DwarfPlanet : public Planet {

private:
  const string planet_type = "dwarf planet";

public:
  DwarfPlanet(const double _mass, const double _distance, const float _obliquity, const string _name) :
    Planet(_mass, _distance, _obliquity, _name) {
    std::cout << "Dwarf Planet constructor." << std::endl;
  }

  string get_planetype() const {
    return planet_type;
  }
  ~DwarfPlanet() {
    std::cout << "Dwarf Planet destructor." << std::endl;
  }
};
