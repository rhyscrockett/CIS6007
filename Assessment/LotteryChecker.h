#pragma once
//THIS IS WHERE WE WILL COMPARE THE LOTTTERY TICKET GENERATED TO THE STRUCTS OF THE CSV FILES
#include <vector>

#include "LotteryGenerator.h"
#include "LotteryResults.h"

int counter = 0;

void checkNumbers(std::vector<int> rn, std::vector<int> dataset) {
    std::unique_lock<std::mutex> lock(mu);
    for (auto n : dataset) {
        //std::sort(myticket.begin(), myticket.end());
        //std::sort(generatedTicket.begin(), generatedTicket.end());
        if (std::find(rn.begin(), rn.end(), n) != rn.end()) {
            std::cout << "Found " << n << std::endl;
            counter++;
        }
        else
            std::cout << n << " Not found!" << std::endl;
    }
}
