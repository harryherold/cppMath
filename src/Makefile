CPPU_TEST = $(HOME)/procs/cpputest

CC = clang
CPP = clang++

CFLAGS = -std=c++11 -Wall -c -g -O0

SOURCES = test_matrix.cpp

LIBS = -L$(CPPU_TEST)/lib -lCppUTest
INCLUDE = -I$(CPPU_TEST)/include -I./

OBJS = $(SOURCES:%.cpp=%.o)

BIN_DIR = $(PWD)/bin

test:$(OBJS)
	$(CPP) -o $@ $(OBJS) $(LIBS)
	mv test $(BIN_DIR)/test
	$(BIN_DIR)/test -v

%.o:%.cpp
	$(CPP) $(CFLAGS) $(INCLUDE) -o $@ $<

all : $(OBJS)

clean:
	rm -rf *~ \#_* *.o
