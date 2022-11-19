#include "Cpu.h"

CPU::CPU(){
    runningPID = 0;
    processPriority = -1;
}

void CPU::setRunningPID(int pid){
    runningPID = pid;
}

void CPU::setRunningPriority(int priority){
    processPriority = priority;
}

int CPU::returnPriority() const{
    return processPriority;
}

int CPU::returnPID() const{
    return runningPID;
}

bool CPU::isEmpty() const{
    return runningPID == 0;
}