#include "../headers/all.h"
using namespace std;

void execute_cmd(int command, shelf* s){
    
    switch(command){
        case 0:
            #ifndef GUI
            int type;
            cout << "Enter 0 to show by name, 1 to show by time: ";
            cin >> type;
            if(type == 0)
                show_book_by_name(s);
            else if(type == 1)
                show_book_by_time(s);
            #else
            // show book in gui
            #endif
            break;
        case 1:
            // show detail
            #ifndef GUI
            show_details(s);
            #else
            // show book in gui
            #endif
            break;

        case 2:
            #ifndef GUI
            borrow_book(s);
            #else
            // show book in gui
            #endif
            break;
        case 3:
            #ifndef GUI
            c_return_book(s);
            #else
            // show book in gui
            #endif
            break;

        case 4:
            #ifndef GUI
            root_operations(s);
            #else
            // show book in gui
            #endif
            break;

        default:
            #ifndef GUI
            cout << "Invalid command" << endl;
            cin.ignore();
            #else
            // show book in gui
            #endif
            break;

    }
}

void root_operations(shelf* s){
    int command;
    string inp;
    #ifndef GUI
    printf("%-10s %s","COMMAND","OPERATIONS\n");
    printf("%-10d %s",0,"Add book\n");
    printf("%-10d %s",1,"Remove book\n");
    printf("%-10d %s",-1,"Exit\n");
    cin >> inp;
    try{
        command = stoi(inp);
    }catch(exception e){
        cout << "Invalid command" << endl;
        return;
    }
    #else

    #endif
    switch(command){
        case 0:
            #ifndef GUI
            add_book(s);
            #else
            // show book in gui
            #endif
            break;
        case 1:
            #ifndef GUI
            remove_book(s);
            #else
            // show book in gui
            #endif
            break;
            
        default:
            cout << "Invalid command" << endl;
            break;
            
    }
}

void read_database(shelf* s){
    // read from file
    ifstream file("database.txt");
    if (!file.is_open()) {
        deprint("Error opening file\n");
        return;
    }
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string name, author, publisher, ISBN;
        string date_str;
        string tp;
        time_t publication_date;
        int copies,avail;
        getline(ss, name, '\\');
        getline(ss, author, '\\');
        getline(ss, publisher, '\\');
        getline(ss, ISBN, '\\');
        getline(ss, date_str, '\\');
        struct tm tm = {};
        strptime(date_str.c_str(), "%Y/%m/%d", &tm);
        publication_date = mktime(&tm);
        getline(ss, tp, '\\');
        copies = stoi(tp);
        ss >> avail;
        ss.ignore();
        create_book(s, name, author, publisher, ISBN, publication_date, copies,avail);
    }
    file.close();
}

void write_database(shelf* s){
    ofstream file("database.txt");
    if (!file.is_open()) {
        std::cout << "Error opening file" << std::endl;
        return;
    }

    for (const auto& b : s->get_all_books()) {
        time_t pub_date = b->get_publication_date();
        struct tm* tm_ptr = localtime(&pub_date);
        char date_str[11]; // "YYYY/MM/DD" + null terminator
        strftime(date_str, sizeof(date_str), "%Y/%m/%d", tm_ptr);

        file << b->get_name() << "\\"
             << b->get_author() << "\\"
             << b->get_publisher() << "\\"
             << b->get_ISBN() << "\\"
             << date_str << "\\"
             << b->get_copies() << "\\"
             << b->get_available_copies() << "\n";
    }
    
}