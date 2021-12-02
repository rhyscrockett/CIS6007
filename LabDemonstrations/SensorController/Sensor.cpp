#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <thread>
#include <mutex>

#include <fstream>
#include <sstream>

#include <algorithm>
#include <iterator>

#include "IRandom.h"
#include "SensorConfig.h"

std::mutex _mu;

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << std::endl;
    for (int i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i != vec.size() - 1)
            os << "";
    }
    os << std::endl;
    return os;
}

std::ostream& operator<<(std::ostream& out, const Readings& sensor_data) {
    out  << sensor_data.type << sensor_data.value << " - Timestamp: " << ctime(&sensor_data.timestamp);
    return out;
}

/* // old print statement
void print(const std::string& s, const double& p) {
    std::cout << s;
    std::cout << p << " ";
    std::cout << std::endl;
}
*/

void light_sensor() {
    std::unique_lock<std::mutex> lock(_mu);
    Readings rLight;
    rLight.type = "Light Level: ";
    IRandom rand(1, 100);
    for (auto i = 0; i < 1000; i++) {
        int n = rand();
        rLight.value = n;
    }
    std::chrono::system_clock::time_point time = std::chrono::system_clock::now();
    rLight.timestamp = std::chrono::system_clock::to_time_t (time);
    sensor_data.push_back(rLight); // add the type and value for the light level to the common vector.
    //print(rLight.type, rLight.value);
}

void temperature_sensor() {
    std::unique_lock<std::mutex> lock(_mu);
    Readings rTemp;
    rTemp.type = "Temperature Reading: ";
    IRandom rand(1, 80);
    for (auto i = 0; i < 1000; i++) {
        int n = rand();
        rTemp.value = n;
    }
    std::chrono::system_clock::time_point time = std::chrono::system_clock::now();
    rTemp.timestamp = std::chrono::system_clock::to_time_t (time);
    sensor_data.push_back(rTemp); // add the type and value for the temperature reading to the common vector.
    //print(rTemp.type, rTemp.value);
}

int main() {
    std::thread light (light_sensor); // create thread for light
    std::thread temp (temperature_sensor); // create thread for temperature

    light.join(); // join the threads
    temp.join();

    //generate_timestamp();
    std::cout << sensor_data; // print the vector.
    return 0;
}