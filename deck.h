#ifndef deck_h
#define deck_h
#include <iostream>
#include "card.h"
using namespace std;


/********************************************
/* CLASS NAME: Deck
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION OF FUNCTION: creates a deck of 52 cards has a randomCard method and a printDeck Method
/***********************************************/

class Deck{
	private:
		Card* deckOfCards[52];
		int numCardsChosen;
	
	public:
		Deck(); //default constructor	
		Card* randomCard();
		void printDeck();
		~Deck();//Destructor
};
#endif
