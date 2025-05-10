#include "../headers/all.h"
using namespace std;

shelf::shelf() {}

shelf::~shelf() {
    // Assuming book pointers are managed elsewhere
}

pos shelf::get_last() {
    if (books.empty()) {
        return books.end();
    }
    return books.end() - 1;
}

pos shelf::get_root() {
    return books.begin();
}

void shelf::swap(pos p1, pos p2) {
    book* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

bool shelf::is_root(pos& idx) {
    return idx == books.begin();
}

pos shelf::left(pos &idx) {
    size_t k = idx - books.begin();
    size_t left_k = 2 * k + 1;
    if (left_k < books.size()) {
        return books.begin() + left_k;
    }
    return books.end();
}

pos shelf::right(pos &idx) {
    size_t k = idx - books.begin();
    size_t right_k = 2 * k + 2;
    if (right_k < books.size()) {
        return books.begin() + right_k;
    }
    return books.end();
}

pos shelf::get_parent(pos &idx) {
    if (idx == books.begin()) {
        return books.end(); // Root has no parent
    }
    size_t k = idx - books.begin();
    size_t parent_k = (k - 1) / 2;
    return books.begin() + parent_k;
}

bool shelf::insert(book* b) {
    if(this->search(b->get_name()) != nullptr){
        deprint("Book already exists\n");
        return 0;
    }
    books.push_back(b);
    pos current = get_last();
    while (!is_root(current)) {
        pos parent = get_parent(current);
        if ((*current)->get_publication_date() < (*parent)->get_publication_date()) {
            swap(parent, current);
            current = parent;
        } else {
            break;
        }
    }
    return 1;
}

void shelf::pop() {
    if (books.empty()) return;
    if (books.size() == 1) {
        books.pop_back();
        return;
    }
    pos root = get_root();
    pos last = get_last();
    *root = *last;
    books.pop_back();
    pos current = root;
    pos end = books.end();
    while (true) {
        pos left_child = left(current);
        pos right_child = right(current);
        pos smallest = current;
        if (left_child != end && (*left_child)->get_publication_date() < (*smallest)->get_publication_date()) {
            smallest = left_child;
        }
        if (right_child != end && (*right_child)->get_publication_date() < (*smallest)->get_publication_date()) {
            smallest = right_child;
        }
        if (smallest != current) {
            swap(current, smallest);
            current = smallest;
        } else {
            break;
        }
    }
}

vector<PSI>* shelf::show_by_time() {
    // deprint("SHOWING BOOKS BY TIME\n");
    // deprint("%-30s %-5s\n","BOOK NAME","AVAILABLE COPIES");
    vector<PSI> *book_list = new vector<PSI>();
    vector<book*> temp = books;
    while (!temp.empty()) {
        book_list->push_back(PSI(temp[0]->get_name(), temp[0]->get_available_copies()));
        // deprint("%-30s %16d\n",temp[0]->get_name().c_str(),temp[0]->get_available_copies());
        temp[0] = temp.back();
        temp.pop_back();
        size_t current = 0;
        while (true) {
            size_t left_child = 2 * current + 1;
            size_t right_child = 2 * current + 2;
            size_t smallest = current;
            if (left_child < temp.size() && temp[left_child]->get_publication_date() < temp[smallest]->get_publication_date()) {
                smallest = left_child;
            }
            if (right_child < temp.size() && temp[right_child]->get_publication_date() < temp[smallest]->get_publication_date()) {
                smallest = right_child;
            }
            if (smallest != current) {
                book* swap_temp = temp[current];
                temp[current] = temp[smallest];
                temp[smallest] = swap_temp;
                current = smallest;
            } else {
                break;
            }
        }
    }
    return book_list;
}

book* shelf::search(string name) {
    for (auto b : books) {
        if (b->get_name() == name) {
            return b;
        }
    }
    return nullptr;
}

book* shelf::search_by_ISBN(string ISBN) {
    for (auto b : books) {
        if (b->get_ISBN() == ISBN) {
            return b;
        }
    }
    return nullptr;
}


vector<book*> shelf::get_all_books(){
    return this->books;
}