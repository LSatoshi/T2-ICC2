all: T2-ICC2

T2-ICC2: main.o trees.o nodes.o
	gcc -o T2-ICC2 main.o trees.o nodes.o -lm

nodes.o: src/nodes.c
	gcc -o nodes.o -c src/nodes.c -g -Wall

trees.o: src/trees.c
	gcc -o trees.o -c src/trees.c -g -Wall

main.o: src/main.c src/trees.h src/nodes.h
	gcc -o main.o -c src/main.c -g -Wall

clean:
	rm -f *.o T2-ICC2
