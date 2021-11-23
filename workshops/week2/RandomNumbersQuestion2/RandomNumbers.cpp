#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

#include "IRandom.h"
#include "Adder.h"

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
  printV(data, 10); // print the 10 numbers randomly generated.

  auto start = std::chrono::high_resolution_clock::now(); // start the clock

  // Addr to add value 10 to all items in the vector<int> data.
  Adder<int> add(10);

  for (auto& item : data)
    item = add(item); // loop through the vector data, adding the value 10 to each item

  std::cout << "-----------------------\n";
  printV(data, 10); // print a divider and the added value to the vector data

  auto end = std::chrono::high_resolution_clock::now(); // end the clock

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end- start); // sum the duration in microseconds

  std::cout << "Adder Time Taken: " << duration.count() << " ms. " << std::endl; // print time taken in ns
}
