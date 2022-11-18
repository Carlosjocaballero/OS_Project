#pragma once
#include "Process.h"


class CPU{
    public:
        CPU();
        void updateRunning(Process* p1);
        int getRunningPriority() const;

        int getRunningPID() const;

    private:
        Process run
};