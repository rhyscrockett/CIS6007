#pragma once
//THIS IS WHERE WE WILL COMPARE THE LOTTTERY TICKET GENERATED TO THE STRUCTS OF THE CSV FILES
#include <vector>
#include <algorithm>

#include "LotteryGenerator.h"
#include "LotteryResults.h"
#include "LocksAndCondtions.h"

int counter = 0;

void checkNumbers(std::vector<int> rn, std::vector<int> dataset) {
    std::unique_lock<std::mutex> lock(mu);                                                                          // use the mutex to lock the block
    cv.wait(lock, [] { return ready == 2; });                                                                       // wait until the ready flag is at 2 (both random number and reader have finished)
    //for (auto row : dataset) {                                                                                    // using a row of the dataset
        //for (auto n : row) {                                                                                      // using a number of the row
        for (auto n : dataset) {
            if (std::find(rn.begin(), rn.end(), n) != rn.end()) {                                                   // find in the ticket the matching numbers in the dataset
                //std::cout << "Found " << n << std::endl;                                                          // when number found print with the number
                counter++;                                                                                          // increment the counter 
            }
            //else                                                                                                  // else print the number and not found
                //std::cout << n << " Not found!" << std::endl;
        }
        std::cout << "Winning numbers: " << counter << std::endl;                                                   // after the loop print the total number of winning numbers found
        counter = 0;                                                                                                // reset the counter
        ready = 0;                                                                                                  // reset the ready counter so the next threads can use
        mu.unlock();                                                                                                // unlock the mutex
}
