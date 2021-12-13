//THIS IS WHERE WE WILL COMPARE THE LOTTTERY TICKET GENERATED TO THE STRUCTS OF THE CSV FILES
#include <vector>
#include "LotteryGenerator.h"
#include "LotteryResults.h"

int totalMatchingDigits = 0;
std::vector<int> matchingDigits;

void getMatchingNumbers(const std::vector<int> &vec, const std::vector<Ticket> &dataset) {
    for (int i = 0; i < dataset.size(); i++) {
        for (int j = 0; j < vec.size(); j++) {
            
        }
    }
}

