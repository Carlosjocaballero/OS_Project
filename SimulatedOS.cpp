#include "SimulatedOS.h"
#include <iostream>

void SimulatedOS::NewProcess(int n){
    int pid = 1;
    Process* p= new Process(pid, n);
    gpu.updateRunning(p);
}

void SimulatedOS::printCPU() const{
    std::cout << gpu.getRunningPID() << std::endl;
}