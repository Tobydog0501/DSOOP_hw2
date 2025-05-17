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


void show_details(shelf* s) {
    cin.ignore();
    int cmd;
    cout << "Enter 0 to search by name, 1 to search by ISBN: ";
    cin >> cmd;
    string name;
    cout << "Enter book name/ISBN: ";
    cin.ignore();
    getline(cin, name);
    book* b;
    if(cmd == 0){
        b = s->search(name);
    }else{
        b = s->search_by_ISBN(name);
    }
    // cin.ignore();
    if (b == nullptr) {
        printf("Book not found\n");
    } else {
        time_t pub_date = b->get_publication_date();
        struct tm *tm_ptr = localtime(&pub_date);
        char date_str[11]; // Buffer for "YYYY/MM/DD" (10 chars) plus null terminator
        if (tm_ptr != nullptr) {
            strftime(date_str, sizeof(date_str), "%Y/%m/%d", tm_ptr);
        } else {
            date_str[0] = '\0';
        }
        printf("Book details:\n");
        printf("%-20s %20s\n","Name:", b->get_name().c_str());
        printf("%-20s %20s\n","Author:", b->get_author().c_str());
        printf("%-20s %20s\n","Publisher:", b->get_publisher().c_str());
        printf("%-20s %20s\n","ISBN:", b->get_ISBN().c_str());
        printf("%-20s %20s\n","Publication date:", date_str);
        printf("%-20s %20d\n","Copies available:", b->get_available_copies());
        printf("%-20s %20d\n","Total copies:", b->get_copies());
    }
}

void borrow_book(shelf* s) {
    cin.ignore();
    string name;
    int copies;
    cout << "Enter book name: ";
    // cin.ignore();
    getline(cin, name);
    cout << "Enter number of copies: ";
    cin >> copies;
    bool b = borrow(s, name, copies);
    if (!b) {
        printf("Invalid Operation\n");
    } else {
        printf("Borrowed %d copies of %s\n", copies, name.c_str());
    }
}


void c_return_book(shelf* s){
    cin.ignore();
    string name;
    int copies;
    cout << "Enter book name: ";
    // cin.ignore();
    getline(cin, name);
    cout << "Enter number of copies: ";
    cin >> copies;
    bool b = return_book(s, name, copies);
    if (!b) {
        printf("Invalid Operation\n");
    } else {
        printf("Returned %d copies of %s\n", copies, name.c_str());
    }
}

void add_book(shelf* s) {
    cin.ignore();
    string name, author, publisher, ISBN;
    time_t publication_date;
    int copies;
    cout << "Enter book name: ";
    // cin.ignore();
    getline(cin, name);
    cout << "Enter author name: ";
    getline(cin, author);
    cout << "Enter publisher name: ";
    getline(cin, publisher);
    cout << "Enter ISBN: ";
    getline(cin, ISBN);
    cout << "Enter publication date (YYYY/MM/DD): ";
    string date_str;
    cin >> date_str;
    struct tm tm = {};
    strptime(date_str.c_str(), "%Y/%m/%d", &tm);
    publication_date = mktime(&tm);
    cout << "Enter number of copies: ";
    cin >> copies;
    cin.ignore();
    if(create_book(s, name, author, publisher, ISBN, publication_date, copies)){
        printf("Book added successfully\n");
    } else {
        printf("Book already exists\n");
    }
}

void remove_book(shelf* s) {
    string name;
    cout << "Enter book name: ";
    cin.ignore();
    getline(cin, name);
    book* b = s->search(name);
    if (b == nullptr) {
        printf("Book not found\n");
    } else {
        s->pop();
        printf("Removed %s\n", name.c_str());
    }
}