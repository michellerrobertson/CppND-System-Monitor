#include "processor.h"
#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>
#include <dirent.h>
#include <sstream>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;
using std::stof;
using std::stoi;
using std::to_string;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() { 
  std::string line, key, user, nice, system, idle, iowait, irq, softirq, steal;
  prevUser = user_;
  prevNice = nice_;
  prevSystem = system_;
  prevIdle = idle_;
  prevIowait = iowait_;
  prevIrq = irq_;
  prevSoftirq = softirq_;
  prevSteal = steal_;
  std::ifstream stream(LinuxParser::kProcDirectory + LinuxParser::kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> key >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal;
    user_ = std::stof(user);
    nice_ = std::stof(nice);
    system_ = std::stof(system);
    idle_ = std::stof(idle);
    iowait_ = std::stof(iowait);
    irq_ = std::stof(irq);
    softirq_ = std::stof(softirq);
    steal_ = std::stof(steal);
  }
  //using stack overflow calculations
  prev_Idle = prevIdle + prevIowait;
  Idle = idle_ + iowait_;
  prevNonIdle = prevUser + prevNice + prevSystem + prevIrq + prevSoftirq + prevSteal;
  NonIdle = user_ + nice_ + system_ + irq_ + softirq_ + steal_;
  prevTotal = prev_Idle + prevNonIdle;
  Total = Idle + NonIdle;
  totald = Total - prevTotal;
  idled = Idle - prev_Idle;
  return (totald-idled)/totald;

}