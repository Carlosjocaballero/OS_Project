#pragma once
#include "Process.h"
#include "Cpu.h"
#include "DiskContainer.h"

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


class SimulatedOS{
    public:
        SimulatedOS( int numberOfDisks, int amountOfRAM, int pageSize );
        void NewProcess(int priority);
        void Exit();
        void DiskReadRequested(int diskNumber, std::string fileName);
        void DiskJobCompleted(int diskNumber);
        void PrintCPU() const;
        void PrintReadyQueue() const;
        void PrintDisk(int diskNumber) const;
        void PrintDiskQueue(int diskNumber) const;
    private:
        CPU cpu;
        std::priority_queue< int, std::vector<int>> pq;
        std::vector<DiskContainer> disks;
        std::unordered_map<int, Process> processTable;
        int pidCounter{0};
};