#include "common.h"
#include "book.h"
using namespace std;
#ifndef SHELF_H
#define SHELF_H

class shelf{
    protected:
        vector<book*> books;

    public:
        void insert(book* b);
        void show_by_time();
        book* serach(string name);
        book* serach_by_ISBN(string ISBN);
};

#endif