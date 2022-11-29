#pragma once

class PageEntry{
    public:
        PageEntry();
        PageEntry(int page, int pid);
        void setPage(int page);
        void setPid(int pid);
        int getPage() const;
        int getPid() const;
    private:
        int page_;
        int pid_;
};