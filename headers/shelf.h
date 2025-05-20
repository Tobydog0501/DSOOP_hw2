#ifndef SHELF_H
#define SHELF_H
#include "common.h"
#include "book.h"
using namespace std;

typedef vector<book*>::iterator pos;

class shelf {
protected:
    vector<book*> books;
    vector<book*> books_Name;

public:
    shelf();
    ~shelf();
    pos get_last(vector<book*>& vec);
    pos get_root(vector<book*>& vec);
    vector<book*> get_all_books();
    void swap(vector<book*>& vec, pos p1, pos p2);
    bool is_root(vector<book*>& vec, pos& idx);
    pos left(vector<book*>& vec, pos& idx);
    pos right(vector<book*>& vec, pos& idx);
    pos get_parent(vector<book*>& vec, pos& idx);
    bool insert(book* b);
    void pop();
    vector<PSI>* show_by_time();
    book* search(string name);
    book* search_by_ISBN(string ISBN);
    vector<book*> search_by_year(int year);

private:
    static bool compare_by_date(book* b1, book* b2);
    static bool compare_by_name(book* b1, book* b2);
    void insert_into_heap(vector<book*>& vec, book* b, bool (*compare)(book*, book*));
};

#endif