#include <iostream>
#include <vector>
#include <cmath>

double sum = 0;
double avg = 0;
double sDeviation = 0;

void print_vector(std::vector<double>& func) {
  // Iterate through the values in the vector, printing them with a space between.
  for (int i = 0; i < func.size(); ++i) {
    std::cout << func[i] << " ";
  }
  // Prints a new line after the vector list has finished.
  std::cout << std::endl;
}

double total(std::vector<double>& func) {
  // Iterate through the vector, adding each value to the sum together.
  for (int i = 0; i < func.size(); i++) {
    sum += func[i];
  }
  // Return the full sum of vector
  return sum;
}

double mean(std::vector<double>& func) {
  // Sets the mean value (total/values) to the variable avg.
  avg = sum / func.size();
  // Return the full avg using the total function and this function.
  return avg;
}

double standard_deviation(std::vector<double>& func) {
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
  print_vector(data);
  
  // Calculate the total of the above data vector.
  std::cout << "Total value is: " << total(data) << std::endl;

  // Calculate the mean average of the above data vector.
  std::cout << "Mean value is: " << mean(data) << std::endl;
  
  // Calculate the Standard Deviation of the above data vector.
  std::cout << "Standard Deviation is: " << standard_deviation(data) << std::endl;
  return 0;
}
