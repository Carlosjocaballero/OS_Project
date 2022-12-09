#include "Process.h"

Process::Process(){}

Process::Process(int pid, int priority){
    priority_ = priority;
    pid_ = pid;
    pc = 0;
}


void Process::updatePC(int newPC){
    pc = newPC;
}

int Process::getPC() const{
    return pc;
}

int Process::getPID() const{
    return pid_;
}

int Process::getPriority() const{
    return priority_;
}
