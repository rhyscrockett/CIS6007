#include <iostream>
#include <thread>
#include <mutex>
#include "LotteryGenerator.h"
#include "LotteryResults.h"
#include "LotteryChecker.h"

void clearDataset(std::vector<int> &vec) {
    while (!vec.empty()) {
        vec.clear();
    }
}

int main() {

    std::vector<int> myticket;
    std::vector<int> dataset;

    auto sTimer = std::chrono::system_clock::now(); // start a timer

    generateNumbers(std::ref(myticket));
    print(myticket);

    checkResults("Lottery-numbers-csv/lotto-results-2001.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2002.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2003.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2004.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2005.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2006.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2007.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2008.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2009.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2010.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2011.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2012.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2013.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2014.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2015.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2016.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2017.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2018.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2019.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    checkResults("Lottery-numbers-csv/lotto-results-2020.csv", std::ref(dataset));
    checkNumbers(myticket, dataset);
    clearDataset(dataset);

    auto eTimer = std::chrono::system_clock::now(); // end timer
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(eTimer - sTimer).count(); // calculate the time taken
    std::cout << "Sequential Time taken: " << duration << " ms. " << std::endl; // print time taken
    return 0;
}