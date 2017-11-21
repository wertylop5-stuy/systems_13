pipes: main.o pipes.o
	gcc -o pipes main.o pipes.o
	make clean

main.o: main.c include/pipes.h
	gcc -c main.c include/pipes.h

pipes.o: pipes.c include/pipes.h
	gcc -c pipes.c include/pipes.h

clean:
	rm *.o

run:
	./pipes

