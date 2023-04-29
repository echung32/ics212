# add -g flag after gcc for gdb

homework9: main.o pokemon.o psyduck.o
	g++ -o homework9 main.o pokemon.o psyduck.o

main.o: main.cpp pokemon.h psyduck.h
	g++ -ansi -pedantic-errors -Wall -c main.cpp

pokemon.o: pokemon.cpp pokemon.h
	g++ -ansi -pedantic-errors -Wall -c pokemon.cpp

psyduck.o: psyduck.cpp psyduck.h pokemon.h
	g++ -ansi -pedantic-errors -Wall -c psyduck.cpp

clean:
	rm -v homework9 main.o pokemon.o psyduck.o
