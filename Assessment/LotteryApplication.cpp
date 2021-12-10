#include <iostream>

#include "LotteryGenerator.h"
#include "LotteryChecker.h"

int main() {

    std::vector<int> tickets;
    std::thread genTicket (generateNumbers, std::ref(tickets));

    std::vector<Ticket> dataset2001, dataset2002, dataset2003, dataset2004, dataset2005, dataset2006, dataset2007, dataset2008, dataset2009, dataset2010,
    dataset2011, dataset2012, dataset2013, dataset2014, dataset2015, dataset2016, dataset2017, dataset2018, dataset2019, dataset2020; // vectors to hold each cvs numbers for each year


    std::thread checkResults1 (checkNumbers, "Lottery-numbers-csv/lotto-results-2001.csv", std::ref(dataset2001));
    std::thread checkResults2 (checkNumbers, "Lottery-numbers-csv/lotto-results-2002.csv", std::ref(dataset2002));
    std::thread checkResults3 (checkNumbers, "Lottery-numbers-csv/lotto-results-2003.csv", std::ref(dataset2003));
    std::thread checkResults4 (checkNumbers, "Lottery-numbers-csv/lotto-results-2004.csv", std::ref(dataset2004));
    std::thread checkResults5 (checkNumbers, "Lottery-numbers-csv/lotto-results-2005.csv", std::ref(dataset2005));
    std::thread checkResults6 (checkNumbers, "Lottery-numbers-csv/lotto-results-2006.csv", std::ref(dataset2006));
    std::thread checkResults7 (checkNumbers, "Lottery-numbers-csv/lotto-results-2007.csv", std::ref(dataset2007));
    std::thread checkResults8 (checkNumbers, "Lottery-numbers-csv/lotto-results-2008.csv", std::ref(dataset2008));
    std::thread checkResults9 (checkNumbers, "Lottery-numbers-csv/lotto-results-2009.csv", std::ref(dataset2009));
    std::thread checkResults10 (checkNumbers, "Lottery-numbers-csv/lotto-results-2010.csv", std::ref(dataset2010));
    std::thread checkResults11 (checkNumbers, "Lottery-numbers-csv/lotto-results-2011.csv", std::ref(dataset2011));
    std::thread checkResults12 (checkNumbers, "Lottery-numbers-csv/lotto-results-2012.csv", std::ref(dataset2012));
    std::thread checkResults13 (checkNumbers, "Lottery-numbers-csv/lotto-results-2013.csv", std::ref(dataset2013));
    std::thread checkResults14 (checkNumbers, "Lottery-numbers-csv/lotto-results-2014.csv", std::ref(dataset2014));
    std::thread checkResults15 (checkNumbers, "Lottery-numbers-csv/lotto-results-2015.csv", std::ref(dataset2015));
    std::thread checkResults16 (checkNumbers, "Lottery-numbers-csv/lotto-results-2016.csv", std::ref(dataset2016));
    std::thread checkResults17 (checkNumbers, "Lottery-numbers-csv/lotto-results-2017.csv", std::ref(dataset2017));
    std::thread checkResults18 (checkNumbers, "Lottery-numbers-csv/lotto-results-2018.csv", std::ref(dataset2018));
    std::thread checkResults19 (checkNumbers, "Lottery-numbers-csv/lotto-results-2019.csv", std::ref(dataset2019));
    std::thread checkResults20 (checkNumbers, "Lottery-numbers-csv/lotto-results-2020.csv", std::ref(dataset2020));


    genTicket.join();
    checkResults1.join();
    checkResults2.join();
    checkResults3.join();
    checkResults4.join();
    checkResults5.join();
    checkResults6.join();
    checkResults7.join();
    checkResults8.join();
    checkResults9.join();
    checkResults10.join();
    checkResults11.join();
    checkResults12.join();
    checkResults13.join();
    checkResults14.join();
    checkResults15.join();
    checkResults16.join();
    checkResults17.join();
    checkResults18.join();
    checkResults19.join();
    checkResults20.join();

    print(tickets);
    printCSV(dataset2001);
    printCSV(dataset2002);
    printCSV(dataset2003);
    printCSV(dataset2004);
    printCSV(dataset2005);
    printCSV(dataset2006);
    printCSV(dataset2007);
    printCSV(dataset2008);
    printCSV(dataset2009);
    printCSV(dataset2010);
    printCSV(dataset2011);
    printCSV(dataset2012);
    printCSV(dataset2013);
    printCSV(dataset2014);
    printCSV(dataset2015);
    printCSV(dataset2016);
    printCSV(dataset2017);
    printCSV(dataset2018);
    printCSV(dataset2019);
    printCSV(dataset2020);

    return 0;
}