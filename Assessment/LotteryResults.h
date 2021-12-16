#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// A struct to hold the ticket information
struct Ticket {                                                                                                   // the date of the winning numbers
  int numbers[7];                                                                                                 // an array with the 7 winning numbers 
  friend std::ostream& operator<<(std::ostream& out, const Ticket& value);                                        // operator overload for "<<" outputting the ticket
};

std::ostream& operator<<(std::ostream& out, const Ticket& value) {                                                // Formatting the printing of the ticket
  out << value.numbers[0] << " " << value.numbers[1]
    << " " << value.numbers[2] << " " << value.numbers[3] << " " << value.numbers[4]
      << " " << value.numbers[5] << " " << value.numbers[6];
  return out;
}

// Check Number Function: Load a CSV file, parse through and print the correct values
void checkNumbers(const std::string &filename, std::vector<int> &dataset) {
  std::ifstream file(filename);                                                                                   // input the file name in to file variable
  std::string line = "";                                                                                          // empty line
  int linecounter = 0;                                                                                            // line counter set to 0

  try {                                                                                                           // Try and Catch loop
    while (getline(file, line)) {                                                                                 // while we have the line of the file
      if (linecounter < 1) {                                                                                      // and if the line counter is less than 1
        ++linecounter;                                                                                            // increment counter to make sure we have the right line
        continue;                                                                                                 // continue out of the loop
      }

      std::stringstream ss(line);                                                                                 // create a string stream for the line
      int counter = 0;                                                                                            // set a new counter to 0
      //Ticket ticket;                                                                                            // Create ticket obj which we use to parse each line to the ticket

      while (ss.good()) {                                                                                         // while the ss is still working
        std::string value;                                                                                        // new string for holding the value
        getline(ss, value, ',');                                                                                  // parse the column converting the value to string with , seperator

        counter++;                                                                                                // increment the counter
        if (counter <= 1)                                                                                         // error checking; if the counter is less than or equal to 1
          continue;                                                                                               // continue to the next column                                                                                  // set the value to the date for the ticket
        if (counter == 3)                                                                                         // else if counter is equal to 3
          //ticket.numbers[0] = std::stoi(value);                                                                 // set the value to int (stoi) for the first number of the winning ticket
          dataset.push_back(std::stoi(value)); 
        else if (counter == 4)                                                                                    // cont...
          //ticket.numbers[1] = std::stoi(value);
          dataset.push_back(std::stoi(value)); 
        else if (counter == 5)
          //ticket.numbers[2] = std::stoi(value);
          dataset.push_back(std::stoi(value));
        else if (counter == 6)
          //ticket.numbers[3] = std::stoi(value);
          dataset.push_back(std::stoi(value));
        else if (counter == 7)
          //ticket.numbers[4] = std::stoi(value);
          dataset.push_back(std::stoi(value));
        else if (counter == 8)
          //ticket.numbers[5] = std::stoi(value);
          dataset.push_back(std::stoi(value));
        else if (counter == 9)
          //ticket.numbers[6] = std::stoi(value);
        dataset.push_back(std::stoi(value));
      }
      //dataset.push_back(ticket);                                                                                 // push the ticket to the dataset parameter
    }
  }
  catch (std::exception &e) {                                                                                      // catch the try loop if there is an exception
    std::cerr << "Error occured during the file read operation: " << e.what() << std::endl;                        // output error message
    file.close();                                                                                                  // close the file
    return;                                                                                                        // return ending the function
  }
  file.close();                                                                                                    // if program runs with no exception, close the file
}

// print function                                                                                                  
template<typename T>                                                                                               // template function
void printCSV(const std::vector<T>& v) {                                                                           // using the vector T 
  if (v.empty())                                                                                                   // check if empty or not
    return;                                                                                                        // return; end the function if empty
  for (auto& i : v)                                                                                                // print string
    std::cout << i << " ";                                                                                         // loop through the vector printing each line
  std::cout << std::endl;
}