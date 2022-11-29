#include "PageEntry.h"

PageEntry::PageEntry(){}

PageEntry::PageEntry(int page, int pid) : page_{page}, pid_{pid}{}

void PageEntry::setPage(int page){
    page_ = page;
}

void PageEntry::setPid(int pid){
    pid_ = pid;
}

int PageEntry::getPage() const{
    return page_;
}

int PageEntry::getPid() const{
    return pid_;
}