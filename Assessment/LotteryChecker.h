#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Ticket {
  std::string date;   // the date of the winning numbers
  int numbers[7];
  
  friend std::ostream& operator<<(std::ostream& out, const Ticket& value);
};

std::ostream& operator<<(std::ostream& out, const Ticket& value) {
  out << "Date: " << value.date << " {No 1: '" << value.numbers[0] << "', No 2: '" << value.numbers[1]
    << "', No 3: '" << value.numbers[2] << "', No 4: '" << value.numbers[3] << "', No 5: '" << value.numbers[4]
      << "', No 6: '" << value.numbers[5] << "', No 7: '" << value.numbers[6] << "'}";
  return out;
}

void checkNumbers(const std::string &filename, std::vector<Ticket> &dataset) {
  std::ifstream file(filename); // input the file name in to file variable

  std::string line = ""; // empty line
  int linecounter = 0; // line counter set to 0

  try {
    while (getline(file, line)) {
      if (linecounter < 1) {
        ++linecounter;
        continue;
      }

      std::stringstream ss(line);
      int counter = 0;

      Ticket ticket;

      while (ss.good()) {
        std::string value;
        getline(ss, value, ',');

        counter++;
        if (counter <= 1)
          continue;
        if (counter == 2)
          ticket.date = value;
        else if (counter == 3)
          ticket.numbers[0] = std::stoi(value);
        else if (counter == 4)
          ticket.numbers[1] = std::stoi(value);
        else if (counter == 5)
          ticket.numbers[2] = std::stoi(value);
        else if (counter == 6)
          ticket.numbers[3] = std::stoi(value);
        else if (counter == 7)
          ticket.numbers[4] = std::stoi(value);
        else if (counter == 8)
          ticket.numbers[5] = std::stoi(value);
        else if (counter == 9)
          ticket.numbers[6] = std::stoi(value);
      }
      dataset.push_back(ticket);
    }
  }
  catch (std::exception &e) {
    std::cerr << "Error occured during the file read operation: " << e.what() << std::endl;
    file.close();
    return;
  }
  file.close();
}

template<typename T>
void printCSV(const std::vector<T>& v) {
  if (v.empty())
    return;
  for (auto& i : v)
    std::cout << i << std::endl;
}