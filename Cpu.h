#pragma once
#include "Process.h"


class CPU{
    public:
        CPU();
        void setRunningPID(int priority);
        int returnPID() const;

        bool isEmpty() const;
    private:
        int runningPID;
};