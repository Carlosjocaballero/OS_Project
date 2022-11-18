#include "Process.h"
#include <iostream>
Process::Process(int& pid, int& priority){
    pid_ = pid;
}

Process::Process(int&& pid, int&& priority){
    pid_ = pid;
}

void Process::updatePC(int newPC){
    pc = newPC;
}

int Process::getPC() const{
    return pc;
}

int Process::getPID() const{
    std::cout << pid_ << std::endl;
    return pid_;
}

int Process::getPriority() const{
    return priority_;
}
