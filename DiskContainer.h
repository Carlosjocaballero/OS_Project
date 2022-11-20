#pragma once
#include "Disk.h"
#include <queue>
#include <string>

class DiskContainer{
    public:
        void setDiskPriority(int ProcessPriority);
        void setDiskFile(std::string f);
        void push(Disk disk);
        void pop();
        Disk top();
        int getDiskPriority() const;
        std::string getDiskFile() const;
        std::queue<Disk> returnDiskQueue() const;
        bool isDiskEmpty() const;
        bool isDiskQueueEmpty() const;
    private:
        Disk disk;
        std::queue<Disk> diskQueue;
};