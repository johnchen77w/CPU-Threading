all: simple_thread 

part1: simple_thread.c
	gcc -pthread -o simple_thread.out simple_thread.c

clean:
	-rm *.out
