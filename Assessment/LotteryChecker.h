#pragma once
//THIS IS WHERE WE WILL COMPARE THE LOTTTERY TICKET GENERATED TO THE STRUCTS OF THE CSV FILES
#include <vector>
#include <algorithm>

#include "LotteryGenerator.h"
#include "LotteryResults.h"

int counter = 0;

template <typename T, typename D>
void checkNumbers(std::vector<T> rn, std::vector<D> dataset) {
    for (auto n : dataset) {
        if (std::find(rn.begin(), rn.end(), n) != rn.end()) {
            //std::cout << "Found " << n << std::endl;
            counter++;
        }
        //else
            //std::cout << n << " Not found!" << std::endl;
    }
    std::cout << "Common numbers: " << counter << std::endl;
    counter = 0;
}
