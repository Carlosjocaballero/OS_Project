#include "SimulatedOS.h"

SimulatedOS::SimulatedOS(int numberOfDisks, int amountOfRAM, int pageSize) : pageSize_(pageSize){
    pidCounter = 1;
    disks.resize(numberOfDisks);
    maxPage = amountOfRAM / pageSize;
    ram.setMaxFrame(maxPage);
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

    ram.insert(0, processTable[priority].getPID());


    pidCounter++;
}

void SimulatedOS::Exit(){
    ram.remove(cpu.returnPID());

    if(!pq.empty()){
        cpu.setRunningPID(processTable[pq.top()].getPID());
        cpu.setRunningPriority(pq.top());
        pq.pop();
    }
    else{
        cpu.setRunningPID(0);
        cpu.setRunningPriority(0);
    }

}

void SimulatedOS::DiskReadRequested( int diskNumber, std::string fileName ){
        if(cpu.isEmpty()) std::cout << "CPU is idle. No process is running." << std::endl;
        else{
            if(disks[diskNumber].isDiskQueueEmpty() && disks[diskNumber].getDiskPriority() == 0){
                disks[diskNumber].setDiskPriority(cpu.returnPriority());
                Exit();
                disks[diskNumber].setDiskFile(fileName);
            }
            else{
                Disk temp;
                temp.setProcessPriority(cpu.returnPriority());
                temp.setReadFile(fileName);
                disks[diskNumber].push(temp);
                Exit();
            }
        }
}

void SimulatedOS::FetchFrom(unsigned int memoryAddress){
    processTable[cpu.returnPriority()].updatePC(memoryAddress);
    int corrPage = memoryAddress/pageSize_;
    ram.insert(corrPage, cpu.returnPID());

}

void SimulatedOS::DiskJobCompleted(int diskNumber){
    if(cpu.isEmpty()) {
        cpu.setRunningPID(processTable[disks[diskNumber].getDiskPriority()].getPID());
        cpu.setRunningPriority(disks[diskNumber].getDiskPriority());
    }
    else{
        pq.push(disks[diskNumber].getDiskPriority());
        if(pq.top() > cpu.returnPriority()){
            pq.push(cpu.returnPriority());
            cpu.setRunningPID(processTable[pq.top()].getPID());
            cpu.setRunningPriority(pq.top());
            pq.pop();
        }
    }

    disks[diskNumber].setDiskPriority(disks[diskNumber].top().getProcessPriority());
    disks[diskNumber].setDiskFile(disks[diskNumber].top().getFile());
    if(!disks[diskNumber].returnDiskQueue().empty()) disks[diskNumber].pop();
}

void SimulatedOS::PrintCPU() const{
    if(cpu.isEmpty()) std::cout << "CPU is idle" << std::endl;
    else
    std::cout << "CPU: " << cpu.returnPID() << std::endl;
}



void SimulatedOS::PrintReadyQueue() const{
    std::priority_queue<int, std::vector<int>> temp = pq;
    std::cout << "Ready-Queue: ";
    if(temp.empty()){
        std::cout << "idle" << std::endl;
    }
    else{
        while(!temp.empty()){
            std::cout << processTable.at(temp.top()).getPID() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }
}

void SimulatedOS::PrintRAM() const{
    ram.print();
}



void SimulatedOS::PrintDisk(int diskNumber) const{
    if(disks[diskNumber].isDiskEmpty()) std::cout << "Disk " << diskNumber << ": Idle" << std::endl;
    else{
        std::cout << "Disk " << diskNumber << ": PID " << processTable.at(disks[diskNumber].getDiskPriority()).getPID() << ", \"" << disks[diskNumber].getDiskFile() << "\"\n";
    }
}

void SimulatedOS::PrintDiskQueue(int diskNumber) const{
    if(diskNumber > disks.size() - 1) std::cout << "Instruction ignored. no disk with such number exists" << std::endl;
    else{
        std::cout << "Disk " << diskNumber << " I/O queue: ";
        if(disks[diskNumber].isDiskQueueEmpty()) std::cout << "Empty" << std::endl;
        else{
            std::queue<Disk> temp = disks[diskNumber].returnDiskQueue();
            while(!temp.empty()){
                std::cout << processTable.at(temp.front().getProcessPriority()).getPID() << " ";
                temp.pop();
            }
            std::cout << std::endl;
        }
    }

}