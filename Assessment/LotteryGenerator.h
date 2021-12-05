#include <iostream>
#include <thread>

#include "IRandom.h"

// Generate random numbers function
void generateNumbers(std::vector<int> &vec) {
    IRandom rand(1, 50);
    for (auto i = 0; i < 7; i++) {
        int n = rand();
        vec.push_back(n);
    }
}

// print function
template<typename T>
void print(const std::vector<T>& v) {
    if (v.empty())
      return;
    for (auto& i : v)
      std::cout << i << " ";
    std::cout << std::endl;
}
