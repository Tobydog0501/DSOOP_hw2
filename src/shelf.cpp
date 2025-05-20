#include "../headers/all.h"
using namespace std;

shelf::shelf() {}

shelf::~shelf() {
    // Assuming book pointers are managed elsewhere
}

pos shelf::get_last(vector<book*>& vec) {
    if (vec.empty()) {
        return vec.end();
    }
    return vec.end() - 1;
}

pos shelf::get_root(vector<book*>& vec) {
    return vec.begin();
}

void shelf::swap(vector<book*>& vec, pos p1, pos p2) {
    book* temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

bool shelf::is_root(vector<book*>& vec, pos& idx) {
    return idx == vec.begin();
}

pos shelf::left(vector<book*>& vec, pos& idx) {
    size_t k = idx - vec.begin();
    size_t left_k = 2 * k + 1;
    if (left_k < vec.size()) {
        return vec.begin() + left_k;
    }
    return vec.end();
}

pos shelf::right(vector<book*>& vec, pos& idx) {
    size_t k = idx - vec.begin();
    size_t right_k = 2 * k + 2;
    if (right_k < vec.size()) {
        return vec.begin() + right_k;
    }
    return vec.end();
}

pos shelf::get_parent(vector<book*>& vec, pos& idx) {
    if (idx == vec.begin()) {
        return vec.end(); // Root has no parent
    }
    size_t k = idx - vec.begin();
    size_t parent_k = (k - 1) / 2;
    return vec.begin() + parent_k;
}

bool shelf::compare_by_date(book* b1, book* b2) {
    return b1->get_publication_date() < b2->get_publication_date();
}

bool shelf::compare_by_name(book* b1, book* b2) {
    return b1->get_name() < b2->get_name();
}

void shelf::insert_into_heap(vector<book*>& vec, book* b, bool (*compare)(book*, book*)) {
    vec.push_back(b);
    pos current = get_last(vec);
    while (!is_root(vec, current)) {
        pos parent = get_parent(vec, current);
        if (compare(*current, *parent)) {
            swap(vec, parent, current);
            current = parent;
        } else {
            break;
        }
    }
}

bool shelf::insert(book* b) {
    if (this->search(b->get_name()) != nullptr) {
        deprint("Book already exists\n");
        return 0;
    }
    insert_into_heap(books, b, &shelf::compare_by_date);
    insert_into_heap(books_Name, b, &shelf::compare_by_name);
    return 1;
}

void shelf::pop() {
    if (books.empty()) return;
    if (books.size() == 1) {
        books.pop_back();
        return;
    }
    pos root = get_root(books);
    pos last = get_last(books);
    *root = *last;
    books.pop_back();
    pos current = root;
    pos end = books.end();
    while (true) {
        pos left_child = left(books, current);
        pos right_child = right(books, current);
        pos smallest = current;
        if (left_child != end && compare_by_date(*left_child, *smallest)) {
            smallest = left_child;
        }
        if (right_child != end && compare_by_date(*right_child, *smallest)) {
            smallest = right_child;
        }
        if (smallest != current) {
            swap(books, current, smallest);
            current = smallest;
        } else {
            break;
        }
    }
}

vector<PSI>* shelf::show_by_time() {
    vector<PSI> *book_list = new vector<PSI>();
    vector<book*> temp = books;
    while (!temp.empty()) {
        book_list->push_back(PSI(temp[0]->get_name(), temp[0]->get_available_copies()));
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

vector<book*> shelf::get_all_books() {
    return this->books;
}

vector<book*> shelf::search_by_year(int year) {
    vector<book*> result;
    vector<book*> temp = books_Name;

    while (!temp.empty()) {
        book* b = temp[0];
        time_t pub_date = b->get_publication_date();
        struct tm* tm = localtime(&pub_date);
        if (tm && (tm->tm_year + 1900) == year || year == 0) {
            result.push_back(b);
        }
        if (temp.size() > 1) {
            temp[0] = temp.back();  
            temp.pop_back();        
            size_t current = 0;     

            while (true) {
                size_t left_child = 2 * current + 1;
                size_t right_child = 2 * current + 2;
                size_t smallest = current;
                
                if (left_child < temp.size() && 
                    temp[left_child]->get_name() < temp[smallest]->get_name()) {
                    smallest = left_child;
                }
                if (right_child < temp.size() && 
                    temp[right_child]->get_name() < temp[smallest]->get_name()) {
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
        } else {
            temp.pop_back();
        }
    }

    return result;
}