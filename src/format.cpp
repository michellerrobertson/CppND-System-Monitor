#include <string>

#include "format.h"

using std::string;

// DONE: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
  long hours;
  long mins;
  long secs;
  std::string value;
  mins = seconds/60;
  hours = mins/60;
  mins = mins%60;
  secs = seconds%60;
  value = std::to_string(hours) + ":" + std::to_string(mins) + ":" + std::to_string(secs);
  if(secs<10) {
    value = std::to_string(hours) + ":" + std::to_string(mins) + ":0" + std::to_string(secs);
  }
  return value;
}