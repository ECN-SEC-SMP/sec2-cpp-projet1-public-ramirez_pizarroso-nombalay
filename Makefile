all: main.out

clean:
	rm *.o
	rm *.out

main.out: main.o parcelle.o
	g++ -o main.out main.o parcelle.o

main.o: main.cpp polygone.hpp point2D.hpp
	g++ -c main.cpp

parcelle.o: parcelle.cpp parcelle.hpp
	g++ -c parcelle.cpp
