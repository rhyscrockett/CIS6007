#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

#include "IRandom.h"
#include "Adder.h"
#include "Multiplier.h"

template<typename T>
void printV(const std::vector<T>& v) {
  if (v.empty())
    return;
  for (auto& item : v) std::cout << item << " , ";
  std::cout << std::endl;
}

template<typename T>
void printV(const std::vector<T>& v, const int limit) {
  if (v.empty())
    return;
  for (auto i = 0; i < limit; ++i)
    std::cout << v[i] << " ";
  std::cout << std::endl;
}

int main() {
   IRandom rand(1, 10);

  // Create a vector called data of type INT, cycle through creating a 1000 numbers generating a random in N, add n to the end of data vector.
  std::vector<int> data;
  for (auto i = 0; i < 500; ++i) {
    int n = rand();
    data.push_back(n);
  }
  std::cout << "The random numbers generated are: " << std::endl;
  printV(data, 10); // print the 10 numbers randomly generated

  auto aStart = std::chrono::high_resolution_clock::now(); // start the clock

  // added a lambda to replace the function call.
  auto addLambda = [](int& item) {return item += 10;};
  std::for_each(data.begin(), data.end(), addLambda);
  std::cout << "-----------------------\n";
  printV(data, 10);

  /*
  // Addr to add value 10 (add(10) to all items in the vector<int> data.
  Adder<int> add(10);
  for (auto& item : data)
    item = add(item); // loop through the vector data, adding the value 10 to each item
  std::cout << "-----------------------\n";
  printV(data, 10); // print a divider and the limit of 10 printing integers
  */
  
  auto aEnd = std::chrono::high_resolution_clock::now(); // end the clock
  auto aDuration = std::chrono::duration_cast<std::chrono::microseconds>(aEnd- aStart); // sum the duration in microseconds
  std::cout << "Adder Time Taken: " << aDuration.count() << " ms. " << std::endl; // print time taken in ns

  auto mStart = std::chrono::high_resolution_clock::now(); // start the clock

  // added a lambda to replace the function call for multiply
  auto multiplyLambda = [](int& item) {return item *= 2; };
  std::for_each(data.begin(), data.end(), multiplyLambda);
  std::cout << "-----------------------\n";
  printV(data, 10);
  
  /*
  Multiplier<int> multiply(2); // Use the Multiplier functor to multiply by 2
  for (auto& item : data) // loop through the vector data, multiplying each value by 2
    item = multiply(item);
  std::cout << "-----------------------\n";
  printV(data, 10); // print a divider and the limit of 10 printing integers
  */
  
  auto mEnd = std::chrono::high_resolution_clock::now(); // end the clock
  auto mDuration = std::chrono::duration_cast<std::chrono::microseconds>(mEnd - mStart); // sum the duration time taken in microseconds
  std::cout << "Multiplier Time Take: " << mDuration.count() << " ms. " << std::endl; // print the time taken in ns

  std::cout << "-----------------------\n";

  std::cout << "The final unique numbers extracted from the vector are: " << std::endl;

  // default comparison
  std::vector<int>::iterator it; // create an iterator variable with a vector
  it = std::unique (data.begin(), data.end()); // iterate through the data vector from beginning to end finding unique values
  data.resize(std::distance(data.begin(), it)); // after unique values have been identified, form a new array with that vector
  printV(data, 10); // print the updated list
}
