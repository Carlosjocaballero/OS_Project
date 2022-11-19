#pragma once

class Process{
    public:
        /**
         * @brief Construct a new Process object. Needed to use the operator[] in hashmap
         */
        Process();

        /**
         * @brief Construct a new Process object
         * @param pid Process ID of the process
         * @param priority Priority integer of the process
         */
        Process(int pid, int priority);

        /**
         * @brief Return the process ID
         * @return The process ID
         */
        int getPID() const;

        /**
         * @brief Return the priority of the process
         * @return int priority of process
         */
        int getPriority() const;

        /**
         * @brief Return the program counter
         * @return int program counter
         */
        int getPC() const;

        /**
         * @brief Update the program counter
         * @param newPC the new program counter
         */
        void updatePC(int newPC);
    private:
        int pid_;
        int pc;
        int priority_;
};