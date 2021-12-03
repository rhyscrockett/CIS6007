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

double sumVectorA(int* start, int* end, int init) {
    double total = std::accumulate(start, end, init);
    return total;
}

double sumVectorAsyncH(std::vector<int>& v) {
    auto start = &v[0];
    auto size = v.size();
    auto end = start + size;

    auto sumVector1 = std::async(std::launch::async, sumVectorA, start, (start + size / 2), 0);
    auto sumVector2 = std::async(std::launch::async, sumVectorA, (start + size / 2), (start + size), 0);

    double total = sumVector1.get() + sumVector2.get();
    return total;
}

double sumVectorAsyncQ(std::vector<int>& v) {
    auto start = &v[0];
    auto size = v.size();
    auto end = start + size;

    auto sumVector1 = std::async(std::launch::async, sumVectorA, start, (start + size / 4), 0);
    auto sumVector2 = std::async(std::launch::async, sumVectorA, (start + size / 4), (start + size / 2), 0);
    auto sumVector3 = std::async(std::launch::async, sumVectorA, (start + size * 3 / 4), (start + size), 0);
    auto sumVector4 = std::async(std::launch::async, sumVectorA, (start + size * 3 / 4), (start + size), 0);

    double total = sumVector1.get() + sumVector2.get() + sumVector3.get() + sumVector4.get();
    return total;
}

int main() {
    IRandom rand(1, 100);
    std::vector<int> data;
    for (auto i = 0; i < 1000000; i++) {
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

    auto sTimer2 = std::chrono::high_resolution_clock::now();
    double r2 = sumVectorAsyncH(data);
    std::cout << "Sum of Vector: " << r2 << std::endl;
    auto eTimer2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(eTimer2 - sTimer2);
    std::cout << "Execution Timer (2 Partitions): " << duration2.count() << " ms. " << std::endl;

    auto sTimer3 = std::chrono::high_resolution_clock::now();
    double r3 = sumVectorAsyncQ(data);
    std::cout << "Sum of Vector: " << r3 << std::endl;
    auto eTimer3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(eTimer3 - sTimer3);
    std::cout << "Execution Timer (4 Partitions): " << duration3.count() << " ms. " << std::endl;
}
