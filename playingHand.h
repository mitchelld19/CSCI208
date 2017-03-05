#ifndef playingHand_h
#define playingHand_h
#include <iostream>
#include "card.h"
#include "deck.h"
#include "LinkedList.h"
using namespace std;


/********************************************
/* CLASS NAME: playingHand
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION OF FUNCTION: creates a hand of cards to play the crazy eight game
/***********************************************/

class playingHand: public LinkedList<Card>{
	private:
	    //LinkedList hand;

	public:
	    playingHand();//default constructor
		playingHand(Deck&);
		void printCards();
		int findRankPos(Card);
                int findSuitPos(Card);

};
#endif
