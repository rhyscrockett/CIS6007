#include <iostream>
#include <vector>
#include <cmath>

template<typename P>
void PrintVector(std::vector<P> &func) {
  // Iterate through the values in the vector, printing them with a space between.
  for(int i = 0; i < func.size(); ++i) {
    std::cout << func[i] << " ";
  }
  // Prints a new line after the vector list has finished printing.
  std::cout << std::endl;
}

template<typename T>
T Total(std::vector<T> &func) {
  // Set sum to the value that will be passed by the data vector to T.
  T sum = 0;
  for(int i = 0; i < func.size(); i++) {
    sum += func[i];
  }
  return sum;
}

template<typename M>
M Mean(std::vector<M> &func) {
  // Set sum using the Total function to M.
  M sum = Total(func);
  // Set avg to the value that will be passed by the data vector to M.
  M avg = 0;
  avg = sum / func.size();
  return avg;
}

template<typename S>
double StandardDeviation(std::vector<S> &func) {
  // Set avg using the Mean function to S.
  S avg = Mean(func);
  // Declare sDeviation a double and set to 0.
  double sDeviation = 0;
  for(int i = 0; i < func.size(); ++i) {
    sDeviation += pow(func[i] - avg, 2);
  }
  return sqrt(sDeviation/func.size());
}


int main() {
  // Declare the two test vectors, one INT and one DOUBLE.
  std::vector<int> data = {10, 11, 12, 13, 14, 15};
  std::vector<double> doubleData = {10.1, 11.2, 12.3, 13.4, 14.5, 15.6};

  // Print the vectors to screen showing each element.
  PrintVector(data);
  PrintVector(doubleData);
  std::cout << std::endl;

  // Print total value of INT vector first, DOUBLE vector second.
  std::cout << "Total value INT is: " << Total<int>(data) << std::endl;
  std::cout << "Total value DOUBLE is: " << Total<double>(doubleData) << std::endl;
  // Print new line
  std::cout << std::endl;

  // Print total mean of INT vector first, DOUBLE vector second.
  std::cout << "Total mean INT value is: " << Mean<int>(data) << std::endl;
  std::cout << "Total mean DOUBLE value is: " << Mean<double>(doubleData) << std::endl;
  std::cout << std::endl;
  
  // Print the standard deviation of INT first, DOUBLE second.
  std::cout << "Standard Deviation INT is: " << StandardDeviation<int>(data) << std::endl;
  std::cout << "Standard Deviation DOUBLE is: " << StandardDeviation<double>(doubleData) << std::endl;
  std::cout << std::endl;
  return 0;
}
