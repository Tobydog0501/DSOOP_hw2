#include "../headers/book.h"
using namespace std;

book::book(string name, string author, string publisher, string ISBN, time_t publication_date, int copies, int available_copies){
    this->name = name;
    this->author = author;
    this->publisher = publisher;
    this->ISBN = ISBN;
    this->publication_date = publication_date;
    this->copies = copies;
    this->available_copies = available_copies;
}

book::~book(){}

string book::get_author(){
    return this->author;
}

string book::get_name(){
    return this->name;
}

string book::get_publisher(){
    return this->publisher;
}

string book::get_ISBN(){
    return this->ISBN;
}

time_t book::get_publication_date(){
    return this->publication_date;
}

int book::get_copies(){
    return this->copies;
}

int book::get_available_copies(){
    return this->available_copies;
}

void book::modify_copies(int c){
    this->available_copies += c;
    if(this->available_copies < 0){
        this->available_copies = 0;
    }
}
