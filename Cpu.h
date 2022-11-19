#pragma once
#include "Process.h"


class CPU{
    public:
        /**
         * @brief Construct a new CPU object. runningPID will be 0;
         */
        CPU();

        /**
         * @brief Set the runningPID. This sets the holder to a value
         * @param pid The process ID the CPU is currently executing
         */
        void setRunningPID(int pid);

        /**
         * @brief Set the priority of the currently running process
         * @param priority The priority of the currently running process
         */
        void setRunningPriority(int priority);

        /**
         * @brief Getter function that returns the PID the cpu is running
         * @return The process ID the cpu is running
         */
        int returnPID() const;

        /**
         * @brief Returns the priority of the currently running process
         * @return int priority of running process
         */
        int returnPriority() const;

        /**
         * @brief Checks if the CPU is being currently executing a program
         * @return true if it is not executing a program
         * @return false if it is executing a program
         */
        bool isEmpty() const;
    private:
        int runningPID;
        int processPriority;
};