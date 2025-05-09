#include "../headers/all.h"
using namespace std;

void show_book_by_time(shelf* s) {
    vector<PSI>* book_list = s->show_by_time();
    if (book_list->empty()) {
        printf("No books available\n");
    } else {
        printf("%-30s %-5s\n","BOOK NAME","AVAILABLE COPIES");
        for (const auto& book : *book_list) {
            printf("%-30s %16d\n", book.first.c_str(), book.second);
        }
    }
}