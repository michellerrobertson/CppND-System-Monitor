#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;
using std::stof;

Process::Process(int pid) : pid_(pid) {};
// DONE: Return this process's ID
int Process::Pid() { 
    return pid_;
}

// DONE: Return this process's CPU utilization
float Process::CpuUtilization() { 
    std::vector<string> statTime = LinuxParser::CpuUtilization(pid_);
    float upTime = (float)LinuxParser::UpTime();
    float uTime = std::stof(statTime[13]);
    float sTime = std::stof(statTime[14]);
    float cuTime = std::stof(statTime[15]);
    float csTime = std::stof(statTime[16]);
    float startTime = std::stof(statTime[21])/sysconf(_SC_CLK_TCK);
    //using stack overflow calculations
    float totalTime = uTime + sTime + cuTime + csTime;
    float seconds = upTime - startTime;
    float cpuUsage = (totalTime/sysconf(_SC_CLK_TCK))/seconds;
    
    return cpuUsage; 
}

// DONE: Return the command that generated this process
string Process::Command() { 
    return LinuxParser::Command(pid_); 
}

// DONE: Return this process's memory utilization
string Process::Ram() { 
    return LinuxParser::Ram(pid_);
}

// DONE: Return the user (name) that generated this process
string Process::User() { 
    return LinuxParser::User(pid_); 
}

// DONE: Return the age of this process (in seconds)
long int Process::UpTime() { 
    return LinuxParser::UpTime() - LinuxParser::UpTime(pid_); 
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process & a) { 
    return CpuUtilization() < a.CpuUtilization(); 
}