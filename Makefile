all: main.out

clean:
	rm *.o
	rm *.out

main.out: main.o 
	g++ -o main.out main.o 

main.o: main.cpp
	g++ -c main.cpp