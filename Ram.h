#pragma once
#include "PageEntry.h"
#include <iostream>
#include <unordered_map>
#include <list>

class Ram{
  public:
    Ram();
    void insert(int page, int pid);
    void remove(int pid);
    int positionOfRemoved();
    void setMaxFrame(int mf);
    bool isFullyUsed() const;
    bool isInTable(int page, int pid);
    void print() const;



  private:
    std::unordered_map<int, PageEntry> pageTable;
    std::list<int> usedMemory;
    int maxFrame;
    int frameCounter;
};