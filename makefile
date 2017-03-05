card: card.o deck.o menu.o
	c++ -o cardGames card.o deck.o menu.o

card.o: card.h card.cpp
	c++ -c card.cpp

deck.o: deck.h deck.cpp
	c++ -c deck.cpp
	
menu.o: menu.cpp
	c++ -c menu.cpp

clean:
	rm card.o menu.o deck.o
