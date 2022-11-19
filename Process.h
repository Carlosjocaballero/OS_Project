#pragma once

class Process{
    public:
        /**
         * @brief Construct a new Process object
         * 
         * @param pid PID of the process
         * @param priority Priority of the process
         */
        Process(int& pid, int& priority);
        int getPID() const;
        int getPriority() const;
        int getPC() const;
        void updatePC(int newPC);
    private:
        int pid_;
        int pc;
        int priority_;
};