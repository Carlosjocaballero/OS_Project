#include "SimulatedOS.h"

SimulatedOS::SimulatedOS(int numberOfDisks, int amountOfRAM, int pageSize){
    pidCounter = 1;
}


void SimulatedOS::NewProcess(int priority){
    Process pros(pidCounter, priority);
    processTable.insert({priority, pros});
    if(cpu.isEmpty()) {
        cpu.setRunningPID(processTable[priority].getPID());
        cpu.setRunningPriority(processTable[priority].getPriority());
    }
    else{
        pq.push(pros.getPriority());
        if(pq.top() > cpu.returnPriority()){
            pq.push(cpu.returnPriority());
            cpu.setRunningPID(processTable[pq.top()].getPID());
            cpu.setRunningPriority(pq.top());
            pq.pop();
        }
    }
    pidCounter++;
}

void SimulatedOS::PrintCPU() const{
    if(cpu.isEmpty()) std::cout << "CPU is idle" << std::endl;
    std::cout << "CPU: " << cpu.returnPID() << std::endl;
}



void SimulatedOS::PrintReadyQueue() const{
    std::priority_queue<int, std::vector<int>> temp = pq;
    std::cout << "Ready-Queue: ";
    while(!temp.empty()){
        std::cout << processTable.at(temp.top()).getPID() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}