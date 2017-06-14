PROG = ../bin/cache

CC = g++

CPPFLAGS = -O0 -g -W -Wall -pedantic -std=c++11

OBJS = main.o cache.o file_io.o funcionalidades.o

$(PROG) : $(OBJS)
	$(CC)  -o $(PROG) $(OBJS)

main.o :
	$(CC) $(CPPFLAGS) -c main.cpp

cache.o : cache.cpp
	$(CC) $(CPPFLAGS) -c cache.cpp

file_io.o : file_io.cpp
	$(CC) $(CPPFLAGS) -c file_io.cpp

funcionalidades.o : funcionalidades.cpp
	$(CC) $(CPPFLAGS) -c funcionalidades.cpp

clean:
	rm -f *.o
