all: main.out

clean:
	rm *.o
	rm *.out

main.out: main.o parcelle.o carte.o ZN.o ZA.o ZAU.o ZU.o constructible.o
	g++ -o main.out main.o parcelle.o carte.o ZN.o ZA.o ZAU.o ZU.o constructible.o

main.o: main.cpp polygone.hpp point2D.hpp 
	g++ -c main.cpp

parcelle.o: parcelle.cpp parcelle.hpp
	g++ -c parcelle.cpp

carte.o: carte.cpp carte.hpp
	g++ -c carte.cpp

ZN.o: ZN.cpp ZN.hpp
	g++ -c ZN.cpp

ZA.o: ZA.cpp ZA.hpp
	g++ -c ZA.cpp

ZAU.o: ZAU.cpp ZAU.hpp
	g++ -c ZAU.cpp

ZU.o: ZU.cpp ZU.hpp
	g++ -c ZU.cpp

constructible.o: constructible.cpp constructible.hpp
	g++ -c constructible.cpp
