#include <iostream>
#include <vector>
#include <cmath>

// Hopefully make a function template to declare the variable sum, as a template meaning it loads the required type at compile time, working with Int, Double etc..

// THIS IS THE MAIN PROBLEM.
float sum = 0;
float avg = 0;
double sDeviation = 0;


template<typename T>
T Total(std::vector<T> &func) {
  for(int i = 0; i < func.size(); i++) {
    sum += func[i];
  }
  return sum;
}

template<typename M>
M Mean(std::vector<M> &func) {
  avg = sum / func.size();
  return avg;
}

template<typename S>
double StandardDeviation(std::vector<S> &func) {
  for(int i = 0; i < func.size(); ++i) {
    sDeviation += pow(func[i] - avg, 2);
  }
  return sqrt(sDeviation/func.size());
}


int main() {
  //std::vector<int> data = {10, 11, 12, 13, 14, 15};
  //std::vector<double> data = {10.1, 11.2, 12.3, 13.4, 14.5, 15.6};
  std::vector<float> data = {10.11, 11.22, 12.33, 13.44, 14.55, 15.66};
  
  std::cout << "Total value is: " << Total(data) << std::endl;

  std::cout << "Total mean value is: " << Mean(data) << std::endl;

  std::cout << "Standard Deviation is: " << StandardDeviation(data) << std::endl;
  return 0;
}
