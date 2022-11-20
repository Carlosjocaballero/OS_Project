#include "DiskContainer.h"


void DiskContainer::setDiskPriority(int ProcessPriority){
    disk.setProcessPriority(ProcessPriority);
}

void DiskContainer::setDiskFile(std::string f){
    disk.setReadFile(f);
}

bool DiskContainer::isDiskEmpty() const{
    return disk.isEmpty();
}

bool DiskContainer::isDiskQueueEmpty() const{
    return diskQueue.empty();
}

void DiskContainer::push(Disk disk){
    diskQueue.push(disk);
}

void DiskContainer::pop(){
    diskQueue.pop();
}

Disk DiskContainer::top(){
    return diskQueue.front();
}

int DiskContainer::getDiskPriority() const{
    return disk.getProcessPriority();
}

std::string DiskContainer::getDiskFile() const{
    return disk.getFile();
}

std::queue<Disk> DiskContainer::returnDiskQueue() const{
    return diskQueue;
}