#include <random>

class IRandom {

 private:
  std::default_random_engine re;
  std::uniform_int_distribution<> dist;

 public:

 IRandom(int low, int high) : dist { low, high } {}

  int operator() () { return dist(re); }
};
