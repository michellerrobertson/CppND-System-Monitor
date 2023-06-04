#include <string>

#include "format.h"

using std::string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
  int hours;
  int mins;
  int secs;
  int remainder;
  std::string value;
  hours = seconds/3600;
  remainder = seconds%3600;
  mins = remainder/60;
  secs = remainder%60;
  value = std::to_string(hours) + ":" + std::to_string(mins) + ":" + std::to_string(secs);
  return value;
}