#include "headers/all.h"
using namespace std;

int main() {
    shelf* s = new shelf();

    create_book(s, "The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "9780743273565", 0, 5);
    create_book(s, "1984", "George Orwell", "Secker & Warburg", "9780451524935", 30, 3);
    create_book(s, "To Kill a Mockingbird", "Harper Lee", "J.B. Lippincott & Co.", "9780061120084", 9, 4);
    create_book(s, "Pride and Prejudice", "Jane Austen", "T. Egerton", "9780141439518", 1, 2);
    // Inserting books

    // Print out
    show_book_by_time(s);
    borrow(s, "The Great Gatsb", 2);
    borrow(s, "The Great Gatsby", 2);
    show_book_by_time(s);
    borrow(s, "The Great Gatsby", 2);
    show_book_by_time(s);
    borrow(s, "The Great Gatsby", 2);
    borrow(s, "1984", 2);
    show_book_by_time(s);
    return_book(s, "The Great Gatsby", 7);
    show_book_by_time(s);
    // c_return_book(s); 
    add_book(s);
    show_book_by_time(s);
    remove_book(s);
    show_book_by_time(s);
    // show_details(s);
    // book* b = s->search("1984");
    return 0;
}
