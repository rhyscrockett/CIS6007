#include <iostream>

#include "IRandom.h"

using namespace std;

int main() {

  IRandom rand(1, 10);
  
  std::cout << "Random Number: " << rand() << std::endl;

  std::cout << "Hello World" << std::endl;
  
}
