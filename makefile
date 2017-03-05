card: card.o deck.o tool.o rock.o paper.o scissors.o monte.o marble.o menu.o Node.h Stack.h LinkedList.h playingHand.o discardPile.o
	c++ -o cardGames card.o deck.o menu.o playingHand.o discardPile.o tool.o rock.o paper.o scissors.o monte.o marble.o

card.o: card.h card.cpp
	c++ -c card.cpp

deck.o: deck.h deck.cpp
	c++ -c deck.cpp
	
playingHand.o: playingHand.h playingHand.cpp
	c++ -c playingHand.cpp
	
discardPile.o: discardPile.h discardPile.cpp
	c++ -c discardPile.cpp

tool.o: tool.h tool.cpp
	c++ -c tool.cpp

rock.o: rock.h rock.cpp
	c++ -c rock.cpp

paper.o: paper.h paper.cpp
	c++ -c paper.cpp

scissors.o: scissors.h scissors.cpp
	c++ -c scissors.cpp

monte.o: monte.h monte.cpp
	c++ -c monte.cpp

marble.o: marble.h marble.cpp
	c++ -c marble.cpp

menu.o: menu.cpp
	c++ -c menu.cpp

clean:
	rm card.o menu.o deck.o tool.o rock.o paper.o scissors.o monte.o marble.o playingHand.o discardPile.o
