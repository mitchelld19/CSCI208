#ifndef discardPile_h
#define discardPile_h
#include <iostream>
#include "card.h"
#include "Stack.h"
using namespace std;


/********************************************
/* CLASS NAME: discardPile
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION OF FUNCTION: holds the discarded card's suit and rank
/***********************************************/

class discardPile: public Stack<Card>{
    private:
        Card crazyEightCard;
	public:
		discardPile(); //default constructor
		Card getCrazyEightCard();
		void setCrazyEightCard(Card);
};
#endif
