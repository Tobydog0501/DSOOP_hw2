#ifndef SHELF_H
#define SHELF_H
#include "common.h"
#include "book.h"
using namespace std;

typedef vector<book*>::iterator pos;

class shelf {
protected:
    vector<book*> books;

public:
    shelf();
    ~shelf();
    pos get_last();
    pos get_root();
    vector<book*> get_all_books();
    void swap(pos p1, pos p2);
    bool is_root(pos& idx);
    pos left(pos &idx);
    pos right(pos &idx);
    pos get_parent(pos &idx);
    bool insert(book* b);
    void pop();
    vector<PSI>* show_by_time();
    book* search(string name);
    book* search_by_ISBN(string ISBN);
};

#endif