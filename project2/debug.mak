# add -g flag after gcc for gdb

project_debug: user_interface.o llist.o
	g++ -std=c++98 -D debug -o project_debug user_interface.o llist.o

user_interface.o: user_interface.cpp record.h llist.h
	g++ -std=c++98 -D debug -ansi -pedantic-errors -Wall -c user_interface.cpp

llist.o: llist.cpp record.h
	g++ -std=c++98 -D debug -ansi -pedantic-errors -Wall -c llist.cpp
