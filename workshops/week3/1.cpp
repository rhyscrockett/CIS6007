#include <iostream> // needed for input and output
#include <thread> // needed for thread creation
#include <string> // needed for the string manipulation
#include <chrono> // needed for timekeeping
#include <sstream> // needed for the stringstream function

// function - print_s (constant string to the address s, constan integer value to the address of limit
void print_s(const std::string &s, const int &limit) {
  // create auto assignment of id to that threads id
  auto id = std::this_thread::get_id();
  // create a stringstream variable ss
  std::stringstream ss;
  // assign id to ss
  ss << id;
  // for loop through if less than the limit
  for (auto i = 0; i < limit; i++) {
    // print the stringstream id in a string, with a - seperating
    std::cout << ss.str() << " - " << s << std::endl;
    // auto variable time, equal to a random number between 1000 and 0
    auto time = rand() % 1000;
    // simulate a pause of the thread using the sleep_for milliseconds of time
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
  }
}

// lecturer function prints a string as well as the set limit to print how many times
void lecturer(const std::string &s, const int &limit) {
  // print_string(using the entered string, and the limit of how many times to print
  print_s(s, limit);
}

int main() {
  // call the lecturer function with a string, and a limit
  lecturer("Lecturer is teaching...", 10);
}
