homework9: main.o pokemon.o psyduck.o raichu.o weedle.o
	g++ -o homework9 main.o pokemon.o psyduck.o raichu.o weedle.o

main.o: main.cpp pokemon.h psyduck.h
	g++ -ansi -pedantic-errors -Wall -c main.cpp

pokemon.o: pokemon.cpp pokemon.h
	g++ -ansi -pedantic-errors -Wall -c pokemon.cpp

psyduck.o: psyduck.cpp psyduck.h pokemon.h
	g++ -ansi -pedantic-errors -Wall -c psyduck.cpp

raichu.o: raichu.cpp raichu.h pokemon.h
	g++ -ansi -pedantic-errors -Wall -c raichu.cpp

weedle.o: weedle.cpp weedle.h pokemon.h
	g++ -ansi -pedantic-errors -Wall -c weedle.cpp

clean:
	rm -v homework9 main.o pokemon.o psyduck.o raichu.o weedle.o
