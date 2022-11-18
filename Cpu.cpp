#include "Cpu.h"

CPU::CPU(){
    running = nullptr;
}

void CPU::updateRunning(Process* p1){
    running = p1;
}

int CPU::getRunningPID() const{
    return running->getPID();
}