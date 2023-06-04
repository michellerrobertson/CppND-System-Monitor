#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
 float prevUser, prevNice, prevSystem, prevIdle, prevIowait, prevIrq, prevSoftirq, prevSteal;
 float user_, nice_, system_, idle_, iowait_, irq_, softirq_, steal_;
 float prev_Idle, Idle, prevNonIdle, NonIdle, prevTotal, Total, totald, idled;
};

#endif