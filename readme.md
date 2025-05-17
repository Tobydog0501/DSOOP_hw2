# Library Management System

## Project Structor

```
../lib_cli
├── Makefile
├── database.txt
├── headers
│   ├── all.h
│   ├── book.h
│   ├── common.h
│   ├── debug.h
│   ├── processer.h
│   ├── shelf.h
│   ├── utils_cli.h
│   └── utils_common.h
├── main.cpp
├── readme.md
├── src
│   ├── book.cpp
│   ├── processer.cpp
│   ├── shelf.cpp
│   ├── utils_cli.cpp
│   └── utils_common.cpp
└── test.cpp
```

## Building up the project
### System requirements:
This project was built on WSL2 Ubuntu 22.04 but windows should be fine if the environment is well-configured.
```
sudo apt-get update
sudo apt-get install build-essential gdb
```

### Compile the code:

cd into the directory where the main.cpp lies, enter one of the below:

```shellscript
make all # if you want to run it in interative mode.
make test # if you want to run it in test mode, which just show all function it has.
```

### Execute the program:

This will create several .o files and a main file. Run

```shellscript
./main
```

After this, you will see:

```shellscript
tobydog@Ubuntu:~/cpp project/todolist$ ./main
COMMAND    OPERATIONS
0          Show books by time
1          Show book details
2          Borrow a book
3          Return a book
4          Root operations
-1         Exit
Enter command: 
```


## Executing all commands:
### Show books sorted by publish time
Simply type in 0, then it will show all books sorted by publish time.<br>
database.txt:
```
test\t\t\123\2006/04/01\3\3
test2\t\t\124\2006/06/01\3\3
test3\t\t\125\2001/05/01\3\3
```
Console output:
```
COMMAND    OPERATIONS
0          Show books by time
1          Show book details
2          Borrow a book
3          Return a book
4          Root operations
-1         Exit
Enter command: 0
BOOK NAME                      AVAILABLE COPIES
test3                                         3
test                                          3
test2                                         3
```

### Show book details
Simply type in 1, and it will ask you which method should be taken(name or ISBN). Then type in the name, and it will show all details.

```
COMMAND    OPERATIONS
0          Show books by time
1          Show book details
2          Borrow a book
3          Return a book
4          Root operations
-1         Exit
Enter command: 1
Enter 0 to search by name, 1 to search by ISBN: 0
Enter book name/ISBN: test
Book details:
Name:                                test
Author:                                 t
Publisher:                              t
ISBN:                                 123
Publication date:              2006/04/01
Copies available:                       3
Total copies:                           3
```

### Borrow a book
Type in 2, name, and then the amount copies of the book to be borrowed.
If the amount of the copies the user want to borrow is more than the available amount, it will output an error.
```
COMMAND    OPERATIONS
0          Show books by time
1          Show book details
2          Borrow a book
3          Return a book
4          Root operations
-1         Exit
Enter command: 2
Enter book name: test
Enter number of copies: 1
Borrowed 1 copies of test
```

### Return a book
Type in 3, name, and then the amount copies of the book to be returned.
If the amount of the copies the user want to return is more than the total copies, it will output an error.

```
COMMAND    OPERATIONS
0          Show books by time
1          Show book details
2          Borrow a book
3          Return a book
4          Root operations
-1         Exit
Enter command: 3
Enter book name: test
Enter number of copies: 1
Returned 1 copies of test
```

### Root Operations
#### Add a book
Type in 4, 0, and the details of the new book.
```
COMMAND    OPERATIONS
0          Show books by time
1          Show book details
2          Borrow a book
3          Return a book
4          Root operations
-1         Exit
Enter command: 4
COMMAND    OPERATIONS
0          Add book
1          Remove book
-1         Exit
0
Enter book name: testn
Enter author name: some body
Enter publisher name: some com
Enter ISBN: 123456789
Enter publication date (YYYY/MM/DD): 2011/01/01
Enter number of copies: 10
Book added successfully
```

#### Remove a book
Type in 4, 1, and the name of the deleted book.
```
COMMAND    OPERATIONS
0          Show books by time
1          Show book details
2          Borrow a book
3          Return a book
4          Root operations
-1         Exit
Enter command: 4
COMMAND    OPERATIONS
0          Add book
1          Remove book
-1         Exit
1
Enter book name: test2
Removed test2
```
### Saving data
Type in -1, then it will save all data to database.txt and exit the program.

## Database
There is a database.txt that will be generated after program exits. Then it will read the file once the main program is executed.