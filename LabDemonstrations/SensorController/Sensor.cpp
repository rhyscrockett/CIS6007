#include <iostream>
#include <thread>
#include <queue>
#include <chrono>
#include <ctime>
#include <mutex>
#include <condition_variable>

#include "IRandom.h"
#include "SensorConfig.h"

std::queue<Readings> msg_queue;                                                                 // create a queue using the structure Readings

std::mutex _mu;                                                                                 // create a mutex to use later for locking 
std::condition_variable _cond;                                                                  // create a conditional_variable to use for notifying consumer

// Temperature Sensor Function: Generate a random number between 1 and 80 (°C)
void temperatureSensor() {
    int counter = 0;
    IRandom rand(1, 80);
    while(true) {                                                                               // start a infinite loop and lock the process
        std::unique_lock<std::mutex> lock(_mu);
        int n = rand();                                                                         // use the rand funct and store in n
        Readings rTemp;                                                                         // create the Readings obj rTemp
        rTemp.type = "Temperature";                                                             // store the type for temp
        rTemp.value = n;                                                                        // store the temperture value generated above
        std::chrono::system_clock::time_point time = std::chrono::system_clock::now();          // start a time point at this instance into the variable time
        rTemp.timestamp = std::chrono::system_clock::to_time_t(time);                           // store the timestamp using the time variable
        msg_queue.push(rTemp);                                                                  // push the created vector to the msg_queue
        _cond.notify_one();                                                                     // notify consumer an item has been added                               
        counter++;                                                                              // increment the counter
    }
}

// Light Level Sensor Function: Generate a random number between 0 and 100 (%)
void lightLevelSensor() {
    int counter = 0;
    IRandom rand(0, 100);
    while (true) {                                                                              // start an infinite loop and lock the process
        std::unique_lock<std::mutex> lock(_mu);
        int n = rand();                                                                         // use the rand funct and store in n
        Readings rLight;                                                                        // create the Readings obj rLight
        rLight.type = "Light Level";                                                            // store the type for light
        rLight.value = n;                                                                       // store the light percentage generated above
        std::chrono::system_clock::time_point time = std::chrono::system_clock::now();          // start a time point at this instance into the variable time
        rLight.timestamp = std::chrono::system_clock::to_time_t(time);                          // store the timestamp using the time variable
        msg_queue.push(rLight);                                                                 // push the created vector to the msg_queue
        _cond.notify_one();                                                                     // notify consumer an item has been added
        counter++;                                                                              // increment the counter
    }
}

void smartHomeApplication(int &frequency) {
    while(true) {                                                                               // start an infinite loop
        std::unique_lock<std::mutex> lock(_mu);                                                 // lock the process
        _cond.wait(lock, []() { return !msg_queue.empty(); });                                  // predicate: checks if the store is empty, if yes return false;
        auto value = msg_queue.front();                                                         // create a variable to access the next element in the queue
        msg_queue.pop();                                                                        // removes the next element in the queue
        std::this_thread::sleep_for(std::chrono::seconds(frequency));                           // call sleep_for to pause the process supplied by the variable frequency
        if (value.type == "Temperature") {                                                      // for loop - checks if temperature; prints the message with the degree notation
            std::cout << "Adjusting " << value.type << " to "
                << value.value << "°C at: " << ctime(&value.timestamp) 
                    << std::endl;
        }
        else if (value.type == "Light Level") {                                                 // for loop - checks if light level; prints the message with the percentage notation
            std::cout << "Adjusting " << value.type << " to " 
                << value.value << "% at: " << ctime(&value.timestamp) 
                    << std::endl;
        }
    }
}

int main(int argc, const char* argv[]) {

    Frequency userInput;                                                                        // create obj userInput using the Frequency structure
    parseCommandlineArguments(argc, argv, userInput);
    std::cout << "Frequency Value: " << userInput.frequency << " seconds" << std::endl;         // print a message displaying what frequency value was entered
    int sleepTimer = std::stoi(userInput.frequency);                                            // create a variable sleepTimer to be used with the functions and threads


    std::thread temp(temperatureSensor);                                                        // temperatureSensor thread (producer)
    std::thread light(lightLevelSensor);                                                        // lightLevelSensor thread (producer)
    std::thread app(smartHomeApplication, std::ref(sleepTimer));                                // application thread (consumer)

    temp.join();                                                                                // join all threads
    light.join();
    app.join();

    return 0;
}