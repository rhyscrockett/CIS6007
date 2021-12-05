#include <iostream>

#include "LotteryGenerator.h"

int main() {

    std::vector<int> tickets;

    generateNumbers(tickets);
    print(tickets);
    return 0;
}