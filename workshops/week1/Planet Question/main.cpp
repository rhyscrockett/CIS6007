#include "GasGiant.h"
#include "DwarfPlanet.h"
#include "ConfigData.h"

#include <iostream>
#include <vector>

void print_all_types(const std::vector<Planet*> &p) {
  for(auto& planet : p) {
    std::cout << planet->get_planetype() << std::endl;
  }
}

void usage() {

  std::cerr << "usage: ./output <options> \n" << std::endl;
  std::cerr << "The options can be: \n";
  std::cerr << "    -h    prints this usage statement \n";
  std::cerr << "    -m    <mass value> \n";
  std::cerr << "    -n    <planet name> \n";
  std::cerr << "    -d    <distance to sun> \n";
  std::cerr << "    -o    <obliquity> \n";
  std::cerr << "    -t    <planet type: Gas, Dwarf> \n";
  exit(1);
}

void parse_command_line_args(const int argc, const char** argv, ConfigData & config) {

  for(auto i = 1; i < argc; ++i) {
    std::string argument(argv[i]);

    if(argument.compare("-h") == 0) usage();
    else if(argument.compare("-o") == 0) {
      if(i == argc - 1) usage();
      config.obliquity = std::stod(argv[i += 1]);
    } else if(argument.compare("-m") == 0) {
      if(i == argc - 1) usage();
      config.mass_value = std::stod(argv[i += 1]);
    } else if(argument.compare("-n") == 0) {
      if(i == argc - 1) usage();
      config.planet_name = argv[i += 1];
    } else if(argument.compare("-d") == 0) {
      if(i == argc - 1) usage();
      config.distance = std::stod(argv[i += 1]);
    } else if(argument.compare("-t") == 0) {
      if(i == argc - 1) usage();
      config.planet_type = argv[i += 1];
      std::cout << config.planet_type << std::endl;
      if(config.planet_type.compare("Gas") == 0) config.type = Gas;
      else if(config.planet_type.compare("Dwarf") == 0) config.type = Dwarf;
    }
    else {
      std::cerr << "Unrecognized option: " << argv[i] << std::endl;
      usage();
    }
  }
}

Planet* create_planet_object(const ConfigData &config) {

  std::cout << config.type << std::endl;

  if(config.type == Gas) {
    return (new GasGiant(config.mass_value, config.distance, config.obliquity, config.planet_name));
  } else if (config.type == Dwarf) {
    return (new DwarfPlanet(config.mass_value, config.distance, config.obliquity, config.planet_name));
  } else {
    return nullptr;
  }
}


int main(int argc, char const* argv[]) {

  ConfigData config;
  parse_command_line_args(argc, argv, config);
  
  std::vector<Planet*> solar_system;

  solar_system.emplace_back(create_planet_object(config));
  print_all_types(solar_system);
  
  return 0;
}
