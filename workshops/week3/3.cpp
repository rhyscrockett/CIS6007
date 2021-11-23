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

void student(const std::string &s, const int &limit) {
  print_s(s, limit);
}

int main() {

  // create new thread titled tlecturer - calling the function inside.
  std::thread tlecturer (lecturer, std::string("Lecturer: is teaching..."), (10));
  // create new thread titled tstudent - calling the function inside.
  std::thread tstudent (student, std::string("Student: is learning..."), (10));
  // note, std::ref seems to be deleted?

  // join the two threads together and wait until both are finished
  tlecturer.join();
  tstudent.join();

  // print final string confirming that both threads have ran and ended.
  std::cout << "Thread Join Complete.\n";

}
