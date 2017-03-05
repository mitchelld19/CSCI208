#include "card.h"
#include "deck.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	Deck randomDeck;
	Card* random1;
	Card* magicCard;
	
	random1 = randomDeck.randomCard();
	cout << random1->toString() << endl;
	
	magicCard = magicTrick(random1);
	cout << magicCard->toString() << endl;
	
	
	
	randomDeck.~Deck();

	return 0;
}

Card* magicTrick(Card* card){
	Card* changedCard;
	card->setRank(12);
	card->setCardSuit(HEARTS);	
	
	changedCard = card;
	return card;
}