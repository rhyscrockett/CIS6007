#include <string>
#include <vector>
#include <ctime>

#include <sstream>
#include <fstream>

struct Readings {
    std::string type;
    double value;
    std::time_t timestamp;

    friend std::ostream& operator<<(std::ostream& out, const Readings& sensor_data);
};
std::vector<Readings> sensor_data;