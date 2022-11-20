#pragma once
#include <string>

class Disk{
    public:
        Disk();
        void setProcessPriority(int processPriority);
        void setReadFile(std::string f);
        
        int getProcessPriority() const;
        std::string getFile() const;
        bool isEmpty() const;

    private:
        int priority{0};
        std::string file;
};