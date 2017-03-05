#ifndef deck_h
#define deck_h
#include <iostream>
#include "card.h"
#include "Stack.h"
using namespace std;


/********************************************
/* CLASS NAME: Deck
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION OF FUNCTION: creates a deck of 52 cards, shuffles the deck
/***********************************************/

class Deck: public Stack<Card>{
	private:
		Stack<Card> deckOfCards;
		Stack<Card> tempStack1;
		Stack<Card> tempStack2;
		int stack1Rand;
		int stack2Rand;
		int numCardsChosen;

	public:
		Deck(); //default constructor
		Card randomCard();
		void splitDeck();
		void combineDeck();
		void shuffleDeck();
};
#endif
