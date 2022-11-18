#pragma once
#include "Process.h"
#include "Cpu.h"

class SimulatedOS{
    public:
        void NewProcess(int n);
        void Exit();
        void printCPU() const;
    private:
        CPU gpu;

};