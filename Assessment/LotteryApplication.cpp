#include <iostream>
#include <thread>
#include <mutex>
#include "LotteryGenerator.h"
#include "LotteryResults.h"
#include "LotteryChecker.h"


int main() {

    std::vector<int> myticket;
    std::vector<int> generatedTicket;

    std::thread generate (generateNumbers, std::ref(myticket));
    print(myticket);

    std::thread results (checkResults, "Lottery-numbers-csv/lotto-results-2001.csv", std::ref(generatedTicket));
    printCSV(generatedTicket);

    std::thread check (checkNumbers, myticket, generatedTicket);
    std::cout << "Common numbers: " << counter << std::endl;

    generate.join();
    check.join();
    results.join();

    return 0;
}