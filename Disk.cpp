#include "Disk.h"

Disk::Disk(){}

void Disk::setReadFile(std::string f){
    file = f;
}

void Disk::setProcessPriority(int processPriority){
    priority = processPriority;
}

int Disk::getProcessPriority() const{
    return priority;
}

std::string Disk::getFile() const{
    return file;
}

bool Disk::isEmpty() const{
    return priority == 0;
}