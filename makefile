card: card.o deck.o tool.o rock.o paper.o scissors.o menu.o
	c++ -o cardGames card.o deck.o tool.o rock.o paper.o scissors.o menu.o

card.o: card.h card.cpp
	c++ -c card.cpp

deck.o: deck.h deck.cpp
	c++ -c deck.cpp

tool.o: tool.h tool.cpp
	c++ -c tool.cpp

rock.o: rock.h rock.cpp
	c++ -c rock.cpp

paper.o: paper.h paper.cpp
	c++ -c paper.cpp

scissors.o: scissors.h scissors.cpp
	c++ -c scissors.cpp

menu.o: menu.cpp
	c++ -c menu.cpp

clean:
	rm card.o menu.o deck.o tool.o rock.o paper.o scissors.o
