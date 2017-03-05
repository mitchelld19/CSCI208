#ifndef card_h
#define card_h

#include <iostream>
#include <string>
using namespace std;

enum CARD_SUITS{ 
	JOKER,
	CLUBS,
	DIAMONDS,
	HEARTS,
	SPADES
};


/********************************************
/* CLASS NAME: Card
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION OF FUNCTION: creates a card that has a suit and rank
/***********************************************/

class Card{
	private:
		CARD_SUITS cardSuit;
		string suitString, rankString, cardString;
		void setRank(int rank);
		void setCardSuit(CARD_SUITS suit);	
	public:
		//Constructor
		Card(); //default 
		Card(int rank, CARD_SUITS suit);
		
		string getRank();
		string getCardSuit();	
		string toString();
};
#endif
