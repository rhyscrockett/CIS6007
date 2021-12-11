#include <random>

// Create a class IRandom
class IRandom
{
private:        
    std::default_random_engine re;                              // set the random seed to re
    std::uniform_int_distribution<> dist;                       // set the distribution to dist

public:
    IRandom(int low, int high) : dist { low, high } {}          // constructor setting low and high to int

    int operator() () {                                         // operator returning the distribution using the random seed
        return dist(re);
    }
};