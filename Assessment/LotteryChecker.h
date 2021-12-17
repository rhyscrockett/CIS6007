#pragma once
//THIS IS WHERE WE WILL COMPARE THE LOTTTERY TICKET GENERATED TO THE STRUCTS OF THE CSV FILES
#include <vector>
#include <algorithm>

#include "LotteryGenerator.h"
#include "LotteryResults.h"
#include "LocksAndCondtions.h"

int counter = 0;

void checkNumbers(std::vector<int> rn, std::vector<int> dataset) {
    std::unique_lock<std::mutex> lock(mu);                                                                          // lock the thread
    cv.wait(lock, [] { return ready; });
    for (auto n : dataset) {
        if (std::find(rn.begin(), rn.end(), n) != rn.end()) {
            //std::cout << "Found " << n << std::endl;
            counter++;
        }
        //else
            //std::cout << n << " Not found!" << std::endl;
    }
    std::cout << "Winning numbers: " << counter << std::endl;
    counter = 0;
}
