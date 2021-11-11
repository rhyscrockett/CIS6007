#include <iostream>
#include <vector>
#include <cmath>

void PrintVector(std::vector<double>& func) {
  // Iterate through the values in the vector, printing them with a space between.
  for (int i = 0; i < func.size(); ++i) {
    std::cout << func[i] << " ";
  }
  // Prints a new line after the vector list has finished.
  std::cout << std::endl;
}

double Total(std::vector<double>& func) {
  // Declare variable sum double and = to 0.
  double sum = 0;
  // Iterate through the vector, adding each value to the sum together.
  for (int i = 0; i < func.size(); i++) {
    sum += func[i];
  }
  // Return the full sum of vector
  return sum;
}

double Mean(std::vector<double>& func) {
  double sum = Total(func);
  double avg = 0;
  // Sets the mean value (total/values) to the variable avg.
  avg = sum / func.size();
  // Return the full avg using the total function and this function.
  return avg;
}

double StandardDeviation(std::vector<double>& func) {
  double avg = Mean(func);
  double sDeviation = 0;
  // Iterate through the full vector, perform the power of for each item, minus the avg.
  for (int i = 0; i < func.size(); ++i) {
    sDeviation += pow(func[i] - avg, 2);
  }
  // Return the sqrt of the deviation from above.
  return sqrt(sDeviation/func.size());
}


int main() {
  std::vector<double> data = {10.1, 11.2, 12.3, 13.4, 14.5, 15.6};
  // Print starting vector to show the values.
  PrintVector(data);
  
  // Calculate the total of the above data vector.
  std::cout << "Total value is: " << Total(data) << std::endl;

  // Calculate the mean average of the above data vector.
  std::cout << "Mean value is: " << Mean(data) << std::endl;
  
  // Calculate the Standard Deviation of the above data vector.
  std::cout << "Standard Deviation is: " << StandardDeviation(data) << std::endl;
  return 0;
}
