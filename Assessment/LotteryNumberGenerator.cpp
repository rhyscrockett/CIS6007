#include <iostream>

#include "IRandom.h"
#include "NumberStorage.h"

template<typename T>
void print(const std::vector<T>& v, const int& limit) {
    if (v.empty())
    return;
    for (auto i = 0; i < limit; ++i)
    std::cout << v[i] << " ";
    std::cout << std::endl;
}

int main () {
    std::cout << "Hello World" << std::endl; // test
    IRandom rand(1, 50); // generate value between 1 and 50

    std::vector<int> data;
    for (auto i = 0; i < 500; ++i) {
        int n = rand();
        data.push_back(n);
    }
    print(data, 6);
}