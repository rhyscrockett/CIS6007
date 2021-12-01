#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include "IRandom.h"
#include "NumberStorage.h"

// print fuction
template<typename T>
void print(const std::vector<T>& v) {
    if (v.empty())
    return;
    for (auto i = 0; i < 6; ++i)
    std::cout << v[i] << " ";
    std::cout << std::endl;
}

// create copy vector function
template<typename T>
std::vector<T> create_copy(std::vector<T> const &vec) {
    std::vector<T> v(vec.size());
    std::copy(vec.begin(), vec.end(), v.begin());
    return v;
}


int main () {
    std::cout << "Hello World" << std::endl; // test
    IRandom rand(1, 50); // generate value between 1 and 50

    std::vector<int> data; // create a vector to loop through the iterations
    for (auto i = 0; i < 1000; ++i) {
        int n = rand();
        data.push_back(n); // push back the random numbers to the data vector
    }
    print(data); // print the first 6 elements of the vector

    //std::vector<int> example = create_copy(data); // create a new vector and the create_copy function on the data vector
    //print(example); // print the first 6 elements of the new vector

    Tickets t1; // call the struct and create variable t1
    t1.ticket = create_copy(data); // set t1 ticket vector from struct to copy the data vector generated above
    std::cout << "Copy: ";
    print(t1.ticket); // print the t1 ticket
    return 0;
}