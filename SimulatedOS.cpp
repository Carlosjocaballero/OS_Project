#include "SimulatedOS.h"
#include <iostream>

SimulatedOS::SimulatedOS(int numberOfDisks, int amountOfRAM, int pageSize){
    pidCounter = 1;
    cpu.setRunningPID(0);
}

void SimulatedOS::NewProcess(int priority){
    Process pros(pidCounter, priority);
    processTable[pidCounter++] = pros;
    ;
}

void SimulatedOS::printCPU() const{
    if(cpu.isEmpty()) std::cout << "CPU is idle" << std::endl;

}