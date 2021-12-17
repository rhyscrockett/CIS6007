#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <mutex>

#include "IRandom.h"
#include "LocksAndCondtions.h"

// Generate random numbers function
void generateNumbers(std::vector<int> &vec) {
  std::unique_lock<std::mutex> lock(mu);
  std::vector<int>::iterator it;                                                               // create a new vector that will be used to iterator through
    IRandom rand(1, 50);                                                                       // loop through the numbers generated and push to vec
    for (auto i = 0; i < 7; i++) {
        int n = rand();
        vec.push_back(n);
    }
    it = std::unique(vec.begin(), vec.end());                                                  // loop through the iteratotion vector created above
    vec.resize(std::distance(vec.begin(), it));                                                // resize the vector based on the starting point and the 
}

// print function
template<typename T>                                                                           // template function
void print(const std::vector<T>& v) {                                                          // using the vector T
    if (v.empty())                                                                             // check if empty or not
      return;                                                                                  // return; end the function if empty
    std::cout << "Your Lottery Ticket: ";                                                      // print string
    for (auto& i : v)                                                                          // loop through the vector printing each number with a space " "
      std::cout << i << " ";
    std::cout << std::endl;                                                                    // new line
}
