libhomework10.so: homework10.c homework10.java
	gcc -I/usr/java/latest -I/user/java/latest/include -shared -o libhomework10.so homework10.c

homework10.h: homework10.class
	javah homework10.class

homework10.class: homework10.java
	javac homework10.java

run:
	java –Djava.library.path=. homework10