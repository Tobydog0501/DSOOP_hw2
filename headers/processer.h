#ifndef CLI_H
#define CLI_H
#include "common.h"
#include "shelf.h"
using namespace std;

void execute_cmd(int command, shelf* s);
void root_operations(shelf* s);
void read_database(shelf* s);
void write_database(shelf* s);
// void 
#endif