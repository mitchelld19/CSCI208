card: card.o deck.o main.o Node.h Stack.h LinkedList.h playingHand.o discardPile.o
	c++ -o cardGames card.o deck.o main.o playingHand.o discardPile.o

card.o: card.h card.cpp
	c++ -c card.cpp

deck.o: deck.h deck.cpp
	c++ -c deck.cpp
	
playingHand.o: playingHand.h playingHand.cpp
	c++ -c playingHand.cpp
	
discardPile.o: discardPile.h discardPile.cpp
	c++ -c discardPile.cpp

main.o: main.cpp
	c++ -c main.cpp

clean:
	rm card.o main.o deck.o playingHand.o discardPile.o
