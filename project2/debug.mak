# add -g flag after gcc for gdb

project_debug: user_interface.o llist.o
	g++ -o project_debug user_interface.o llist.o

user_interface.o: user_interface.cpp record.h llist.h
	g++ -DDEBUG -ansi -pedantic-errors -Wall -c user_interface.cpp

llist.o: llist.cpp record.h
	g++ -DDEBUG -ansi -pedantic-errors -Wall -c llist.cpp
