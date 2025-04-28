#include "common.h"
using namespace std;

class book{
    private:
        string name;
        string author;
        string publisher;
        string ISBN;
        string category;
        time_t publication_date;
        int copies;
        int available_copies;
    public:
        book(string name, string author, string publisher, string ISBN, time_t publication_date, int copies, int available_copies);
        string get_name();
        string get_author();
        string get_publisher();
        string get_ISBN();
        time_t get_publication_date();
        int get_copies();
        int get_available_copies();
        void modify_copies(int c); // check out(negetive) or return(positive)
        ~book();
};  