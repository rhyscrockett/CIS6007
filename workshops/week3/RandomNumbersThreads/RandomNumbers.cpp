#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <thread> // needed for threads
#include <mutex> // needed for mutex
#include <string>

#include "IRandom.h"

std::mutex mu;

template<typename T>
void printV(const std::vector<T>& v, const int& limit) {
  if (v.empty())
    return;
  for (auto i = 0; i < limit; ++i)
    std::cout << v[i] << " ";
  std::cout << std::endl;
}

// adder function - take the value of the vector and perform some addition
void adder(std::vector<int>& v, const int& value) {
  for (auto& i : v) { // loop through the vector
    std::unique_lock<std::mutex> lock(mu); //use the mutex lock to make sure only one function has access at a time
    i += value; // add the item by i
  }
}

//multiply function - take the value from the vector and perform some multiply
void multiplier(std::vector<int>& v, const int& value) {
  for (auto& i : v) { // loop through
    std::unique_lock<std::mutex> lock(mu); // use the mutex lock while using the function
    i *= value; // times the item by i
  }
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

  std::cout << "----------------------------\n";
  
  // seriel execution
  auto sStart = std::chrono::high_resolution_clock::now(); // start the clock
  adder(data, 10); // add 10 to each data item
  std::cout << "Add by Ten: " << std::endl;
  printV(data, 10); // print the data items, up to 10
  std::cout << "----------------------------\n";
  multiplier(data, 2); // multiply the data items by 2
  std::cout << "Multiply by Two: " << std::endl;
  auto sEnd = std::chrono::high_resolution_clock::now(); // end the clock
  auto sDuration = std::chrono::duration_cast<std::chrono::microseconds>(sEnd - sStart);
  printV(data, 10);
  std::cout << "----------------------------\n";
  std::cout << "Serial Execution Time: " << sDuration.count() << " ms. " << std::endl;
  
  std::cout << "--------------------------------------------------------\n";

  // parallel execution
  auto pStart = std::chrono::high_resolution_clock::now();

  // task parallelism
  std::thread aThread(adder, std::ref(data), 10);
  std::thread mThread(multiplier, std::ref(data), 2);

  aThread.join();
  mThread.join();

  // data parallelism
  //std::for_each(std::execution::par, data.begin(), data.end(), [](int& item) { item += 10; });
  //std::for_each(std::execution::par, data.begin(), data.end(), [](int& item) { item += 2; });

  auto pEnd = std::chrono::high_resolution_clock::now();
  auto pDuration = std::chrono::duration_cast<std::chrono::microseconds>(pEnd - pStart);
  printV(data, 10);
  std::cout << "Parallel Execution Time: " << pDuration.count() << " ms. " << std::endl;

  std::cout << "--------------------------------------------------------\n";
}
