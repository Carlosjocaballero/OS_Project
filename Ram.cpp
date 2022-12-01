#include "Ram.h"

Ram::Ram(){
    frameCounter = 0;
    maxFrame = 0;
}

void Ram::insert(int page, int pid){
    if(isInTable(page, pid)){
        int frame;
        for(auto itr = pageTable.begin(); itr != pageTable.end(); itr++){
            if(itr->second.getPage() == page && itr->second.getPid() == pid){
                usedMemory.remove(itr->first);
                usedMemory.push_front(itr->first);
                break;
            } 
        }
    }
    else if(!isFullyUsed()){
        int frame;
        for(auto itr = pageTable.begin(); itr != pageTable.end(); itr++){
            if(itr->second.getPid() == -1){
                frame = itr->first;
                break;
            } 
        }
        pageTable.at(frame).setPage(page);
        pageTable.at(frame).setPid(pid);
        usedMemory.push_front(frame);
    }
    else if(maxFrame <= frameCounter){
        pageTable.at(usedMemory.back()).setPage(page);
        pageTable.at(usedMemory.back()).setPid(pid);
        usedMemory.push_front(usedMemory.back());
        usedMemory.pop_back();
    }
    else{
        PageEntry pe(page, pid);
        pageTable.insert({frameCounter, pe});
        usedMemory.push_front(frameCounter);
        frameCounter++;
    }
}

void Ram::remove(int pid){

    for(auto itr = pageTable.begin(); itr != pageTable.end(); itr++){
        if(itr->second.getPid() == pid){
            usedMemory.remove(itr->first);
            itr->second.setPage(-1);
            itr->second.setPid(-1); 
        }
    }
}

void Ram::setMaxFrame(int mf){
    maxFrame = mf;
}

bool Ram::isFullyUsed() const{
    for(auto x : pageTable){
        if(x.second.getPid() == -1) return false;
    }
    return true;
}

bool Ram::isInTable(int page, int pid)
{
    for(auto itr = pageTable.begin(); itr != pageTable.end(); itr++){
        if(itr->second.getPage() == page && itr->second.getPid() == pid) return true;
    }
    return false;
}

void Ram::print() const{
    std::cout << "Frame\tPage\tPID" << std::endl;
    for(int i = 0; i < pageTable.size(); i++){
        std::cout << i << "\t" << pageTable.at(i).getPage() << "\t" << pageTable.at(i).getPid() << std::endl;
    }
    
    // TESTING /////
    std::list<int> temp = usedMemory;

    for(int i = 0; i < usedMemory.size(); i++){
        std::cout << temp.front() << " ";
        temp.pop_front();
    }
    std::cout << std::endl;
}