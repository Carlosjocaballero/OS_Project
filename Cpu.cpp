#include "Cpu.h"

CPU::CPU(){
    runningPID = 0;
}

void CPU::setRunningPID(int pid){
    runningPID = pid;
}

int CPU::returnPID() const{
    return runningPID;
}

bool CPU::isEmpty() const{
    return runningPID == 0;
}