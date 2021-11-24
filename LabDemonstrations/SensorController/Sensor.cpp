#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <ctime>

#include "IRandom.h"

std::mutex _mu;

// struct to hold the temperature and light level readings
struct readings {
  std::string type; // string for which type of reading it will be
  double value; // value of the reading (degree Celsius in temp, percentage in light)
  std::time_t timestamp; // print the timestamp when the changes were made
};
std::vector<readings> sensor_data; // common vector to populate with the sensor data of temp and light

// template function to print the temperature readings with a space
template<typename T>
void printTemp(const std::vector<T>& v, const int& limit) {
  if (v.empty())
    return;
  for (auto i = 0; i < limit; ++i)
    std::cout << v[i] << "°C ";
  std::cout << std::endl;
}

// template function to print the light readings with a percentage
template<typename T>
void printLight(const std::vector<T>& v, const int& limit) {
  if (v.empty())
    return;
  for (auto i = 0; i < limit; ++i)
    std::cout << v[i] << "% ";
  std::cout << std::endl;
}

// function to randomly generate integers to populate the sensor temperatures
void random_temperature() {
  std::unique_lock<std::mutex> lock(_mu); // create a lock for this thread to run without interruptions
  IRandom randTemp(8, 80);
  std::vector<int> dataTemp;
  for (auto i = 0; i < 1000; ++i) {
    int n = randTemp();
    dataTemp.push_back(n);
  }
  std::cout << "Random Temperature Readings are: "; 
  printTemp(dataTemp, 15); // call print temp command with the data vector generated, and a limit of 15
  std::chrono::system_clock::time_point today = std::chrono::system_clock::now(); // create a variable with the current time
  std::time_t tt; // variable tt 
  tt = std::chrono::system_clock::to_time_t ( today ); // set tt to the time created above
  std::cout << "Timestamp: " << ctime(&tt); // print time stamp with the formatted timestamp created above
  std::cout << std::endl;
}

// function to randomly generate integer to populate the sensor light percentages
void random_light_level() {
  std::unique_lock<std::mutex> lock(_mu); // create a lock for this thread to run without interruptions
  IRandom randLight(1, 100);
   std::vector<int> dataLight;
   for (auto i = 0; i < 1000; ++i) {
     int n = randLight();
     dataLight.push_back(n);
   }
   std::cout << "Random Light Level Readings are: ";
   printLight(dataLight, 15);
   std::chrono::system_clock::time_point today = std::chrono::system_clock::now();
   std::time_t tt;
   tt = std::chrono::system_clock::to_time_t (today);
   std::cout << "Timestamp: " << ctime(&tt);
   std::cout << std::endl;
}

// producer - to be used
void temperature_sensor() {
  
}

// producer - to be used
void light_level_sensor() {

}

//consumer - to be used
void smart_home_application() {

}

int main() {
  
  std::thread temp (random_temperature); // create a thread (temp) calling the random_temperature function
  std::thread light(random_light_level); // create a thread (light) calling the random_light_level function

  temp.join(); // join the threads and wait for both to be complete
  light.join();
  
  std::cout << "Hello Smart World!" << std::endl; // print final statement showing successful iteration 
  return 0;
}
