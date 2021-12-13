#include <iostream>
#include <thread>

#include "LotteryGenerator.h"
#include "LotteryResults.h"

int main() {

    std::vector<int> tickets;
    std::thread genTicket (generateNumbers, std::ref(tickets));

    std::vector<Ticket> dataset01;
    std::thread readWinnings01 (checkNumbers, "Lottery-numbers-csv/lotto-results-2001.csv", std::ref(dataset01));

    genTicket.join();
    readWinnings01.join();

    print(tickets);
    printCSV(dataset01);

    return 0;
}