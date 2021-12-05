#include <iostream>

#include "LotteryGenerator.h"
#include "LotteryChecker.h"

int main() {

    std::vector<int> tickets;
    std::thread genTicket (generateNumbers, std::ref(tickets));

    std::vector<Ticket> dataset; // vector to hold the cvs numbers
    std::thread checkTicket (checkNumbers, "Lottery-numbers-csv/lotto-results-2001.csv", std::ref(dataset));
    
    genTicket.join();
    checkTicket.join();

    print(tickets);
    printCSV(dataset);

    return 0;
}