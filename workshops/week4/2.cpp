#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <future>
#include <numeric>

#include "IRandom.h"

template<typename T>
void print(const std::vector<T>& v, const int& limit) {
    if (v.empty())
        return;
    for (auto i = 0; i < limit; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

double sumVector(const std::vector<int>& v) {
    auto start = &v[0];
    auto end = start + v.size();
    double total = std::accumulate(start, end, 0);
    return total;
}

int main() {
    IRandom rand(1, 100);
    std::vector<int> data;
    for (auto i = 0; i < 10; i++) {
        int n = rand();
        data.push_back(n);
    }
    print(data, 10);
    std::cout << "----------------------\n";

    auto sTimer1 = std::chrono::high_resolution_clock::now();
    double r1 = sumVector(data);
    std::cout << "Sum of Vector: " << r1 << std::endl;
    auto eTimer1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(eTimer1 - sTimer1);
    std::cout << "Execution Time (No Partitions): " << duration1.count() << " ms. " << std::endl;
}
