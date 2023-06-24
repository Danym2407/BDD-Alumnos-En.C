principal.out: principal.o
	gcc -Wall -o principal.out principal.o `pkg-config --libs gtk+-2.0`

principal.o: principal.c
	gcc -c principal.c `pkg-config --cflags gtk+-2.0`
