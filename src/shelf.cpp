#include "../headers/shelf.h"
#include "../headers/common.h"
using namespace std;


shelf::shelf(){}

shelf::~shelf(){
    
}

void shelf::insert(book* b){
    this->books.push_back(b);
}