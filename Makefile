CC=g++
MAIN=main.o
TEST=test.o
SHELL = /bin/bash
FLAGS=
GUIFLAGS = -DGUI
DEBUGFLAGS = -DDEBUG -g
EXE=main
SOURCEDIR=src
SRCFILES=$(wildcard $(SOURCEDIR)/*.cpp)
SRCOBJS=$(patsubst %.cpp,%.o,$(SRCFILES))
DBGOBJS=$(patsubst %.cpp,%.dbg,$(SRCFILES))
# OBJ=$(addprefix $(SOURCEDIR)/, )

all: $(MAIN) $(SRCOBJS)
	$(CC) $(MAIN) $(SRCOBJS) -o $(EXE) -lm


debug: FLAGS=$(DEBUGFLAGS)
debug: main.dbg $(DBGOBJS)
	$(CC) $(DEBUGFLAGS) $< $(DBGOBJS) -o $(EXE)

gui: FLAGS=$(GUIFLAGS)
gui: $(MAIN) $(SRCOBJS)
	$(CC) $(FLAGS) $(MAIN) $(SRCOBJS) -o $(EXE) -lm

dgui: FLAGS=$(GUIFLAGS) $(DEBUGFLAGS)
dgui: main.dbg $(DBGOBJS)
	$(CC) $(FLAGS) $< $(DBGOBJS) -o $(EXE)

test: $(TEST) $(SRCOBJS)
	$(CC) $(TEST) $(SRCOBJS) -o $(EXE) -lm
.PHONY: test

dtest: FLAGS=$(DEBUGFLAGS)
dtest: test.dbg $(DBGOBJS)
	$(CC) $(FLAGS) $< $(DBGOBJS) -o $(EXE)
# .PHONY: dtest

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@
	
%.dbg: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

.PHONY: debug

clean:
	-rm -f $(SOURCEDIR)/*.o $(SOURCEDIR)/*.dbg $(EXE) *.o *.dbg

.PHONY: clean