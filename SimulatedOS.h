#pragma once
#include "Process.h"
#include "Cpu.h"
#include <unordered_map>

class SimulatedOS{
    public:
        SimulatedOS( int numberOfDisks, int amountOfRAM, int pageSize );
        void NewProcess(int priority);
        void Exit();
        void printCPU() const;
    private:
        CPU cpu;
        std::unordered_map<int, Process> processTable;
        int pidCounter{0}; 

};