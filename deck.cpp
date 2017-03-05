#ifndef deck_cpp
#define deck_cpp
#include <string>
#include "deck.h"
#include <ctime>
#include <cstdlib>

//default constructor
Deck::Deck(){
	srand(time(0));
	int count = 0;
	
	for(int i=1; i<14; ++i)
	{	
		deckOfCards[count] = new Card(i, CLUBS);
		count++;
	}
	
	for(int j=1; j<14; j++)
	{
		deckOfCards[count] = new Card(j, DIAMONDS);
		count++;
	}
	
	for(int k=1; k<14; k++)
	{
		deckOfCards[count] = new Card(k, HEARTS);
		count++;
	}
	
	for(int l=1; l<14; l++)
	{
		deckOfCards[count] = new Card(l, SPADES);
		count++;
	}
}


/********************************************
/* CLASS & METHOD NAMES: Deck, randomCard
/*
/* DESCRIPTION: creates a random number, checks to see if that card in the deck is null,
/*              if null random number is + 1, card is then set to null and returns pointer to card
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: randomCard (pointer to card)
/***********************************************/
Card* Deck::randomCard(){
	Card* randomCard;
	int random_number;
	random_number = rand() % 52;
	
	if(this->numCardsChosen == 52)
	{
		throw 11;
	}
	else{
		if(deckOfCards[random_number] != NULL)
		{
			randomCard = deckOfCards[random_number];
			deckOfCards[random_number] = NULL;
			this->numCardsChosen++;
			return randomCard;
		}
		else{
			while(deckOfCards[random_number] == NULL){
				if(random_number < 51){
					random_number = random_number + 1;
				}
				else{
					random_number = 0;
				}
			}
			
			randomCard = deckOfCards[random_number];
			deckOfCards[random_number] = NULL;
			this->numCardsChosen++;
			return randomCard;
		}
	}
}


/********************************************
/* CLASS & METHOD NAMES: Deck, printDeck
/*
/* DESCRIPTION: prints the card deck
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: none
/***********************************************/
void Deck::printDeck(){
	for(int m=0; m<52; m++)
	{
		if(deckOfCards[m]!=NULL)
				cout << deckOfCards[m]->toString() << endl;
	}
}


Deck::~Deck(){
	for(int n=0; n<52; n++)
    {
        delete deckOfCards[n];
        deckOfCards[n] = NULL;
    }
}
#endif
