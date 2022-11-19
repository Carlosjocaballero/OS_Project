#pragma once
#include "Process.h"
#include "Cpu.h"
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

class SimulatedOS{
    public:
        SimulatedOS( int numberOfDisks, int amountOfRAM, int pageSize );
        void NewProcess(int priority);
        void Exit();
        void PrintReadyQueue() const;
        void PrintCPU() const;
    private:
        CPU cpu;
        std::priority_queue< int, std::vector<int>> pq;
        std::unordered_map<int, Process> processTable;
        int pidCounter{0};
};