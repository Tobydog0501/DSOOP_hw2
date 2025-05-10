#ifndef UTILS_COMMON_H
#define UTILS_COMMON_H
#include "common.h"
#include "book.h"
#include "shelf.h"
using namespace std;

bool create_book(shelf *s,string name, string author, string publisher, string ISBN, time_t publication_date, int copies);
bool create_book(shelf *s,string name, string author, string publisher, string ISBN, time_t publication_date, int copies,int avail);

bool borrow(shelf *s, string name, int copies);

bool return_book(shelf *s, string name, int copies);
book* search(shelf *s, string name);
bool search_by_ISBN(shelf *s, string ISBN);


#endif