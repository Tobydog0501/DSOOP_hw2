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