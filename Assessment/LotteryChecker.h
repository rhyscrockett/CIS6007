#pragma once
//THIS IS WHERE WE WILL COMPARE THE LOTTTERY TICKET GENERATED TO THE STRUCTS OF THE CSV FILES
#include <vector>
#include "LotteryGenerator.h"
#include "LotteryResults.h"

int counter = 0;

/*
void checkNumbers(std::vector<int> rn, std::vector<int> dataset) {
    for (auto n : rn) {
        std::sort(rn.begin(), rn.end());
        std::sort(dataset.begin(), dataset.end());
        if (std::binary_search(dataset.begin(), dataset.end(), n)) {
            std::cout << "Found " << n << "\n";
            counter++;
        }
        else {
            std::cout << n << " Not found!" << "\n";
        }
    }
}
*/

void checkNumbers(std::vector<int> rn, std::vector<int> dataset) {
    for (auto n : dataset) {
        //std::sort(rn.begin(), rn.end());
        //std::sort(dataset.begin(), dataset.end());
        if (std::find(rn.begin(), rn.end(), n) != rn.end()) {
            std::cout << "Found " << n << std::endl;
            counter++;
        }
        else
            std::cout << n << " Not found!" << std::endl;
    }
}
