#pragma once
#include <mutex>
#include <condition_variable>

std::mutex mu;                                                                                // create a mutex to use throughout
std::condition_variable cv;                                                                   // create a condition variable to wait for threads to finish in sequence
int ready = 0;                                                                                // set flag to false