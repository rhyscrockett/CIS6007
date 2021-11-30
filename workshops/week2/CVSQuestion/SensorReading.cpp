#include <iostream>
#include <string>
#include "SensorUtilities.h"
#include <vector>
#include <algorithm>

//using namespace std;

struct ConfigData
{
  std::string filename;
};


void usage() {
  std::cerr << "Program usage: ./program -i <options> " << std::endl;
  std::cerr << "The options can be \n";
  std::cerr << "	-h						prints this usage statement. \n";
  std::cerr << "	-i	<filepath/filename>	Input filename. \n";
  exit(-1);
}

void parse_commandline_arguments(const int argc, const char** argv, ConfigData &config) {

  if (argc <= 1) usage();

  for (int i = 1; i < argc; ++i) {

    std::string argument(argv[i]);

    if (argument.compare("-h") == 0) usage();
    else if (argument.compare("-i") == 0) {
      if (i == argc - 1) usage();
      config.filename = argv[i += 1];
    }
    else {
      std::cerr << " Invalid option provided. " << argv[i] << std::endl;
      usage();
    }
  }
}

template<typename T>
void print_v(const std::vector<T>& v) {
  if (v.empty()) return;
  for (auto& i : v) std::cout << i << std::endl;
}


int main(int argc, const char* argv[])
{
   
  ConfigData config;
  parse_commandline_arguments(argc, argv, config);
  
  std::cout << "Input file name: " << config.filename << std::endl;
  
  std::vector<SensorReading> dataset;
  read_file(config.filename, dataset);

  //print_v(dataset);

  // compute average
  auto avg_temperature = [](const std::vector<SensorReading>& data) -> double {
    double sum = 0;
    for (auto& r : data) {
      sum += r.temperature;
    }
    return (sum / data.size());
  };
  
  std::cout << "Average temperature: " << avg_temperature(dataset) << std::endl;

  // extract all the readings where temperature > 30.0
  std::vector<SensorReading> matches;
  const double threshold = 30.0;
  
  std::copy_if(dataset.begin(), dataset.end(), std::back_inserter(matches), [&](const SensorReading& r) {
    return r.temperature > threshold;
  });
  
  print_v(matches);
  std::cout << "Number of entries temperature > 30.0: " << matches.size() << std::endl;
  return 0;
}
