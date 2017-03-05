card: card.o deck.o main.o Node.h Stack.h
	c++ -o cardGames card.o deck.o main.o

card.o: card.h card.cpp
	c++ -c card.cpp

deck.o: deck.h deck.cpp
	c++ -c deck.cpp

main.o: main.cpp
	c++ -c main.cpp

clean:
	rm card.o main.o deck.o
