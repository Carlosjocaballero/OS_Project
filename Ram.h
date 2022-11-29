#pragma once
#include "PageEntry.h"
#include <unordered_map>
#include <list>

class Ram{
  public:
    Ram();
    void insert(int page, pid);

  private:
    std::unordered_map<int, PageEntry> pageTable;
    std::list<int> usedProcesses;
    int frameCounter;
};