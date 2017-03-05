card: card.o main.o
	c++ -o cardMain card.o main.o

card.o: card.h card.cpp
	c++ -c card.cpp

main.o: main.cpp
	c++ -c main.cpp

clean:
	rm card.o main.o
