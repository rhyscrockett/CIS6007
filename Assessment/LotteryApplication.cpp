#include <iostream>

#include "LotteryGenerator.h"
#include "LotteryChecker.h"

int main() {

    std::vector<int> tickets;
    generateNumbers(tickets);
    print(tickets);

    std::vector<Ticket> dataset; // vector to hold the cvs numbers
    checkNumbers("Lottery-numbers-csv/lotto-results-2001.csv", std::ref(dataset));
    printCSV(dataset);
    return 0;
}