#include <iostream>
#include <thread>

#include "LotteryGenerator.h"
#include "LotteryResults.h"
#include "LotteryChecker.h"

int main() {

    std::vector<int> ticket;
    generateNumbers(std::ref(ticket));

    std::vector<int> generatedTicket;
    checkNumbers("Lottery-numbers-csv/lotto-results-2001.csv", std::ref(generatedTicket));

    checkNumbers(std::ref(ticket), std::ref(generatedTicket));

    std::cout << counter << std::endl;

    print(ticket);
    //printCSV(generatedTicket);

    return 0;
}