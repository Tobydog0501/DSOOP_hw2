#ifndef UTILS_CLI_H
#define UTILS_CLI_H
#include "common.h"
#include "book.h"
#include "shelf.h"
using namespace std;

void show_book_by_time(shelf* s);
void show_details(shelf* s);
void borrow_book(shelf* s);
void c_return_book(shelf* s);
void add_book(shelf* s);
void remove_book(shelf* s);

#endif