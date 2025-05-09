#include "../headers/all.h"
using namespace std;

void execute(int command, shelf* s) {
    string name, author, publisher, ISBN;
    time_t publication_date;
    int copies;
    switch(command){
        case 0:
            cout << "Showing books by time" << endl;
            show_book_by_time(s);
            break;
        case 1:
            cout << "Borrowing a book" << endl;
            cout << "Enter book name: ";
            cin >> name;
            cout << "Enter number of copies: ";
            cin >> copies;
            borrow(s, name, copies);
            break;
        case 2:
            cout << "Returning a book" << endl;
            cout << "Enter book name: ";
            cin >> name;
            cout << "Enter number of copies: ";
            cin >> copies;
            return_book(s, name, copies);
            break;
        default:
            cout << "Invalid command" << endl;
            break;
    }
}