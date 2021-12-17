#include <iostream>
#include <thread>
#include <mutex>
#include "LotteryGenerator.h"
#include "LotteryResults.h"
#include "LotteryChecker.h"
#include <condition_variable>
#include "LocksAndCondtions.h"

// Function to clear the dataset each iteration (sequential design)
void clearDataset(std::vector<int> &vec) {
    while (!vec.empty()) {
        vec.clear();
    }
}

int main() {

    std::vector<int> myticket;
    //std::vector<int> dataset;
    // Create the datasets for each CSV file
    std::vector<int> dataset01, dataset02, dataset03, dataset04, dataset05, dataset06, dataset07, dataset08,
                       dataset09, dataset10, dataset11, dataset12, dataset13, dataset14, dataset15,
                        dataset16, dataset17, dataset18, dataset19, dataset20;
    
    auto sTimer = std::chrono::system_clock::now(); // start a timer
    std::thread gen (generateNumbers, std::ref(myticket)); // generate a ticket using a thread
    print(myticket); // print the ticket

    
    std::thread cr1 (checkResults, "Lottery-numbers-csv/lotto-results-2001.csv", std::ref(dataset01));
    std::thread cn1 (checkNumbers, std::ref(myticket), std::ref(dataset01));

    std::thread cr2 (checkResults, "Lottery-numbers-csv/lotto-results-2002.csv", std::ref(dataset02));
    std::thread cn2 (checkNumbers, std::ref(myticket), std::ref(dataset02));

    std::thread cr3 (checkResults, "Lottery-numbers-csv/lotto-results-2003.csv", std::ref(dataset03));
    std::thread cn3 (checkNumbers, std::ref(myticket), std::ref(dataset03));

    std::thread cr4 (checkResults, "Lottery-numbers-csv/lotto-results-2004.csv", std::ref(dataset04));
    std::thread cn4 (checkNumbers, std::ref(myticket), std::ref(dataset04));

    std::thread cr5 (checkResults, "Lottery-numbers-csv/lotto-results-2005.csv", std::ref(dataset05));
    std::thread cn5 (checkNumbers, std::ref(myticket), std::ref(dataset05));

    std::thread cr6 (checkResults, "Lottery-numbers-csv/lotto-results-2006.csv", std::ref(dataset06));
    std::thread cn6 (checkNumbers, std::ref(myticket), std::ref(dataset06));

    std::thread cr7 (checkResults, "Lottery-numbers-csv/lotto-results-2007.csv", std::ref(dataset07));
    std::thread cn7 (checkNumbers, std::ref(myticket), std::ref(dataset07));

    std::thread cr8 (checkResults, "Lottery-numbers-csv/lotto-results-2008.csv", std::ref(dataset08));
    std::thread cn8 (checkNumbers, std::ref(myticket), std::ref(dataset08));

    std::thread cr9 (checkResults, "Lottery-numbers-csv/lotto-results-2009.csv", std::ref(dataset09));
    std::thread cn9 (checkNumbers, std::ref(myticket), std::ref(dataset09));

    std::thread cr10 (checkResults, "Lottery-numbers-csv/lotto-results-2010.csv", std::ref(dataset10));
    std::thread cn10 (checkNumbers, std::ref(myticket), std::ref(dataset10));

    std::thread cr11 (checkResults, "Lottery-numbers-csv/lotto-results-2011.csv", std::ref(dataset11));
    std::thread cn11 (checkNumbers, std::ref(myticket), std::ref(dataset11));

    std::thread cr12 (checkResults, "Lottery-numbers-csv/lotto-results-2012.csv", std::ref(dataset12));
    std::thread cn12 (checkNumbers, std::ref(myticket), std::ref(dataset12));

    std::thread cr13 (checkResults, "Lottery-numbers-csv/lotto-results-2013.csv", std::ref(dataset13));
    std::thread cn13 (checkNumbers, std::ref(myticket), std::ref(dataset13));

    std::thread cr14 (checkResults, "Lottery-numbers-csv/lotto-results-2014.csv", std::ref(dataset14));
    std::thread cn14 (checkNumbers, std::ref(myticket), std::ref(dataset14));

    std::thread cr15 (checkResults, "Lottery-numbers-csv/lotto-results-2015.csv", std::ref(dataset15));
    std::thread cn15 (checkNumbers, std::ref(myticket), std::ref(dataset15));

    std::thread cr16 (checkResults, "Lottery-numbers-csv/lotto-results-2016.csv", std::ref(dataset16));
    std::thread cn16 (checkNumbers, std::ref(myticket), std::ref(dataset16));

    std::thread cr17 (checkResults, "Lottery-numbers-csv/lotto-results-2017.csv", std::ref(dataset17));
    std::thread cn17 (checkNumbers, std::ref(myticket), std::ref(dataset17));

    std::thread cr18 (checkResults, "Lottery-numbers-csv/lotto-results-2018.csv", std::ref(dataset18));
    std::thread cn18 (checkNumbers, std::ref(myticket), std::ref(dataset18));

    std::thread cr19 (checkResults, "Lottery-numbers-csv/lotto-results-2019.csv", std::ref(dataset19));
    std::thread cn19 (checkNumbers, std::ref(myticket), std::ref(dataset19));

    std::thread cr20 (checkResults, "Lottery-numbers-csv/lotto-results-2020.csv", std::ref(dataset20));
    std::thread cn20 (checkNumbers, std::ref(myticket), std::ref(dataset20));

    gen.join();
    cr1.join();
    cn1.join();
    cr2.join();
    cn2.join();
    cr3.join();
    cn3.join();
    cr4.join();
    cn4.join();
    cn5.join();
    cr5.join();
    cn6.join();
    cr6.join();
    cn7.join();
    cr7.join();
    cn8.join();
    cr8.join();
    cn9.join();
    cr9.join();
    cn10.join();
    cr10.join();
    cn11.join();
    cr11.join();
    cn12.join();
    cn12.join();
    cr13.join();
    cn13.join();
    cr14.join();
    cn14.join();
    cr15.join();
    cn15.join();
    cr16.join();
    cn16.join();
    cr17.join();
    cn17.join();
    cr18.join();
    cn18.join();
    cr19.join();
    cn19.join();
    cr20.join();
    cn20.join();

    auto eTimer = std::chrono::system_clock::now(); // end the timer
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(eTimer - sTimer).count(); // calculate the time taken
    std::cout << "Parallel Time taken: " << duration << " ms. " << std::endl; // print time taken
  

    /*
    // Sequential Operation:
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
    */
    return 0;
}