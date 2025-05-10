#include "headers/all.h"
using namespace std;

int main() {
    deprint("DEBUG MODE IS ON\n");
    shelf* s = new shelf();
    read_database(s);
    #ifndef GUI
    deprint("CLI mode\n");
    while(1){
        printf("%-10s %s","COMMAND","OPERATIONS\n");
        printf("%-10d %s",0,"Show books by time\n");
        printf("%-10d %s",1,"Show book details\n");
        printf("%-10d %s",2,"Borrow a book\n");
        printf("%-10d %s",3,"Return a book\n");
        printf("%-10d %s",4,"Root operations\n");
        printf("%-10d %s",-1,"Exit\n");
        printf("Enter command: ");
        string command;
        cin >> command;
        if (command == "-1") {
            break;
        }
        if(command[0]-'0' < 0 || command[0]-'0' > 4){
            cout << "Invalid command" << endl;
            continue;
        }
        execute_cmd(command[0]-'0', s);
    }
    #else
    cout << "GUI mode" << endl;
    #endif
    write_database(s);
    return 0;
}
