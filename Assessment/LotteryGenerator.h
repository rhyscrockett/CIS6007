#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <unordered_set>

#include "IRandom.h"
// generate numbers function: Using the IRandom class, the range for number generation is 1, 50 - NOTE: This removes duplicates next to each other, not across the entire vector!

// Generate random numbers function
void generateNumbers(std::vector<int> &vec) {
  std::vector<int>::iterator it;                                                               // create a new vector that will be used to iterator through
    IRandom rand(1, 50);                                                                       // loop through the numbers generated and push to vec
    for (auto i = 0; i < 7; i++) {
        int n = rand();
        vec.push_back(n);
    }
    it = std::unique(vec.begin(), vec.end());                                                  // loop through the iteratotion vector created above
    vec.resize(std::distance(vec.begin(), it));                                                // resize the vector based on the starting point and the 
}

/*
// generate number function: Using the IRandom class, the range for number generation is 1, 50.
void generateNumbers(std::vector<int> &vec) {
  std::unordered_set<int> s;
  IRandom rand(1, 50);
  for (auto i = 0; i < 7; i++) {                                                                // Loop through the numbers generated and push to vec
    int n = rand();                                                                             
    vec.push_back(n);
  }
  auto end = std::remove_if(vec.begin(), vec.end(),                                             // lambda expression to use the unordered set to store the 
                            [&s](int const &i) {                                                // vector created above and search through checking for duplicates
                              return !s.insert(i).second;
                            });
  vec.erase(end, vec.end());                                                                    // erase the duplicates found in the set
}
*/
// print function
template<typename T>
void print(const std::vector<T>& v) {
    if (v.empty())
      return;
    std::cout << "Your Lottery Ticket: ";
    for (auto& i : v)
      std::cout << i << " ";
    std::cout << std::endl;
}
