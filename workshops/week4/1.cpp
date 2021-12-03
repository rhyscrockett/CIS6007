#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <thread> // needed for threads
#include <mutex> // needed for mutex
#include <string>
#include <future> // needed for promise and future

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

void maximum_value(std::vector<int>& v, std::promise<int>&& p) {
  std::unique_lock<std::mutex> lock(mu);
  double max = *std::max_element(v.begin(), v.end());
  p.set_value(max);
}

void average(std::vector<int>& v, std::promise<int>&& p) {
  std::unique_lock<std::mutex> lock(mu);
  int total = 0;
  for (auto& item : v) {
    total += item;
  }
  double average = total / v.size();
  p.set_value(average);
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

  // parallel execution
  auto pStart = std::chrono::high_resolution_clock::now();

  // declare two promises for maximum value and average value
  std::promise<int> max_promise;
  std::promise<int> avg_promise;

  //declare two futures to get from the promise
  std::future<int> max_future = max_promise.get_future();
  std::future<int> avg_future = avg_promise.get_future();

  // initiate the threads using the move function to add it to the promise
  std::thread maxThread(maximum_value, std::ref(data), std::move(max_promise));
  std::thread avgThread(average, std::ref(data), std::move(avg_promise));

  // print the max value
  std::cout << "Max Value: ";
  std::cout << max_future.get() << std::endl;

  std::cout << "----------------------------\n";

  // print the average value
  std::cout << "Average for Vector: ";
  std::cout << avg_future.get() << std::endl;

  std::cout << "----------------------------\n";

  // join the threads when they are finished
  maxThread.join();
  avgThread.join();

  // end the timer and create a duration time and print to console
  auto pEnd = std::chrono::high_resolution_clock::now();
  auto pDuration = std::chrono::duration_cast<std::chrono::microseconds>(pEnd - pStart);
  std::cout << "Parallel Execution Time: " << pDuration.count() << " ms. " << std::endl;

  std::cout << "----------------------------\n";
}
