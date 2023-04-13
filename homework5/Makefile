homework5: driver.o iofunctions.o
	gcc -o homework5 driver.o iofunctions.o

driver.o: driver.c pokemon.h iofunctions.h
	gcc -ansi -pedantic-errors -Wall -c driver.c

iofunctions.o: iofunctions.c pokemon.h
	gcc -ansi -pedantic-errors -Wall -c iofunctions.c

clean:
	rm homework5 iofunctions.o driver.o
