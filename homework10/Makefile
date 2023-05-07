# JNI=/usr/java/latest/include
# JNIOSX=/usr/java/latest/include/linux

libhomework10.so: homework10.c homework10.h
	gcc -I/usr/java/latest/include -I/usr/java/latest/include/linux -shared -o libhomework10.so homework10.c

homework10.h: homework10.class
	javah homework10

homework10.class: homework10.java
	javac homework10.java

run:
	java -Djava.library.path=. homework10

clean:
	rm -v libhomework10.so homework10.h homework10.class

