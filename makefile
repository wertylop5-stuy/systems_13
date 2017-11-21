pipes: main.o
	gcc -o pipes main.o
	make clean

main.o: main.c
	gcc -c main.c

clean:
	rm *.o

run:
	./pipes

