#include "../headers/all.h"
using namespace std;

bool create_book(shelf *s,string name, string author, string publisher, string ISBN, time_t publication_date, int copies,int avail){
    book* b = new book(name, author, publisher, ISBN, publication_date, copies,avail);
    if(s->insert(b)){
        deprint("Book added successfully\n");
        return true;
    }else{
        deprint("Book already exists\n");
        return false;
    }

}

bool create_book(shelf *s,string name, string author, string publisher, string ISBN, time_t publication_date, int copies){
    book* b = new book(name, author, publisher, ISBN, publication_date, copies);
    if(s->insert(b)){
        deprint("Book added successfully\n");
        return true;
    }else{
        deprint("Book already exists\n");
        return false;
    }
}

book* search(shelf *s, string name){
    book* b = s->search(name);
    if (b == nullptr) {
        deprint("Book not found\n");
        return nullptr;
    }
    return b;
}

bool borrow(shelf *s, string name, int copies){
    book* b = s->search(name);
    if (b == nullptr) {
        deprint("Book not found\n");
        return false;
    }
    if (b->get_available_copies() < copies) {
        deprint("Not enough copies available\n");
        return false;
    }
    b->modify_copies(-1*copies);
    deprint("Borrowed %d copies of %s\n",copies, name.c_str());
    return true;
}

bool return_book(shelf *s, string name, int copies){
    book* b = s->search(name);
    if (b == nullptr) {
        deprint("Book not found\n");
        return false;
    }
    if (b->get_available_copies() + copies > b->get_copies()) {
        deprint("Cannot return more copies than borrowed\n");
        return false;
    }
    if(copies <= 0){
        deprint("Cannot return less than 1 copies\n");
        return false;
    }
    b->modify_copies(copies);
    deprint("Returned %d copies of %s\n",copies, name.c_str());
    return true;
}


bool search_by_ISBN(shelf *s, string ISBN){
    book* b = s->search_by_ISBN(ISBN);
    if (b == nullptr) {
        deprint("Book not found\n");
        return false;
    }
    deprint("Book found: %s\n", b->get_name().c_str());
    return true;
}