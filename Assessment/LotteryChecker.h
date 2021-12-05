#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Ticket {
  std::string date;   // the date of the winning numbers
  int no1;
  int no2;
  int no3;
  int no4;
  int no5;
  int no6;
  int no7;            // all the numbers from a ticket
  
  friend std::ostream& operator<<(std::ostream& out, const Ticket& value);
};

std::ostream& operator<<(std::ostream& out, const Ticket& value) {
  out << "Date: " << value.date << ", No 1: '" << value.no1 << "', No 2: '" << value.no2
    << "', No 3: '" << value.no3 << "', No 4: '" << value.no4 << "', No 5: '" << value.no5
      << "', No 6: '" << value.no6 << "', No 7: '" << value.no7 << "'";
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
          ticket.no1 = std::stoi(value);
        else if (counter == 4)
          ticket.no2 = std::stoi(value);
        else if (counter == 5)
          ticket.no3 = std::stoi(value);
        else if (counter == 6)
          ticket.no4 = std::stoi(value);
        else if (counter == 7)
          ticket.no5 = std::stoi(value);
        else if (counter == 8)
          ticket.no6 = std::stoi(value);
        else if (counter == 9)
          ticket.no7 = std::stoi(value);
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