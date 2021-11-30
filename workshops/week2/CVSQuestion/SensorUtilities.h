#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

//using namespace std;

struct SensorReading
{
  int lightlevel;
  double temperature;
  std::string timestamp;
  
  friend std::ostream& operator<<(std::ostream& out, const SensorReading& data);
};

std::ostream& operator<<(std::ostream& out, const SensorReading& data) {
  out << "Light Level: " << data.lightlevel << ", Temperature: " << data.temperature << ", Timestamp:" << data.timestamp;
  return out;
}

void read_file(const std::string &filename, std::vector<SensorReading> &dataset) {

  std::ifstream fhandle(filename);

  // error checkings:
  /**
   * check if the file exists. 
   * check file permissions
   */
	
  std::string line = "";
  int linecounter = 0;

  try {
    while (getline(fhandle, line)) {
      if (linecounter < 1) { ++linecounter; continue; }
      
      std::stringstream ss(line);
      int counter = 0;
      
      SensorReading reading;
      
      while (ss.good())
	{
	  std::string value;
	  getline(ss, value, ',');
	  
	  // count = 8 > Light value, 10 = temp, 11: time. 		
	  counter++;
	  if (counter <= 7) continue;
	  if (counter == 8) reading.lightlevel = std::stoi(value);
	  else if (counter == 10) reading.temperature = std::stod(value);
	  else if (counter == 11) {
	    reading.timestamp = value;
	    // need a more parsing of value to conver the string to time_t. 
	  }
	}
      dataset.push_back(reading);
    }
  }
  catch (std::exception &e) {
    std::cerr << "Error occurred during the file read operation: " << e.what() << std::endl;
    fhandle.close();
    return;
  }
  
  fhandle.close();
}
