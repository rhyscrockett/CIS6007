#pragma once

#include <iostream>
#include <string>

enum PLANET_TYPES {
  Dwarf, Gas 
};

struct ConfigData {

  // Instance variables to cache configuration variables
  std::string planet_name;
  double mass_value;
  double distance;
  float obliquity;
  std::string planet_type;
  PLANET_TYPES type;

  ConfigData() = default;
  ~ConfigData() = default;
  
};
