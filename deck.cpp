#ifndef deck_cpp
#define deck_cpp
#include <string>
#include "deck.h"
#include <ctime>
#include <cstdlib>

//default constructor
Deck::Deck(){
	srand(time(0));

	for(int i=1; i<14; ++i)
	{
	    Card card1(i, CLUBS);
		//deckOfCards.push(card1);
		this->push(card1);
	}

	for(int j=1; j<14; j++)
	{
	    Card card2(j, DIAMONDS);
		//deckOfCards.push(card2);
		this->push(card2);
	}

	for(int k=1; k<14; k++)
	{
	    Card card3(k, HEARTS);
		//deckOfCards.push(card3);
		this->push(card3);
	}

	for(int l=1; l<14; l++)
	{
	    Card card4(l, SPADES);
		//deckOfCards.push(card4);
		this->push(card4);
	}
}


/********************************************
/* CLASS & METHOD NAMES: Deck, randomCard
/*
/* DESCRIPTION: returns the top card on the deck
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: randomCard
/***********************************************/
Card Deck::randomCard(){
	Card randomCard;
    //randomCard = deckOfCards.pop();
    randomCard = this->pop();
    return randomCard;

}

/********************************************
/* CLASS & METHOD NAMES: Deck, shuffleDeck
/*
/* DESCRIPTION: runs the splitDeck function and combineDeck function 10X
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: none
/***********************************************/
void Deck::shuffleDeck(){
    for(int p=0; p<10; p++)
    {
        splitDeck();
        combineDeck();
    }
}


/********************************************
/* CLASS & METHOD NAMES: Deck, splitDeck
/*
/* DESCRIPTION: splits the deck into two separate temporary stacks
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: none
/***********************************************/
void Deck::splitDeck(){
    int random_number;
    random_number = rand() % 8;
    stack1Rand = 22 + random_number;
    stack2Rand = 22 + (8 - random_number);
    int count1=0, count2=0;

    for(int i=0; i<stack1Rand; i++)
    {
        Card temp1;
        //temp1 = deckOfCards.pop();
        temp1 = this->pop();
        tempStack1.push(temp1);
        count1++;
    }

    for(int i=0; i<stack2Rand; i++)
    {
        Card temp2;
        //temp2 = deckOfCards.pop();
        temp2 = this->pop();
        tempStack2.push(temp2);
        count2++;
    }
}

/********************************************
/* CLASS & METHOD NAMES: Deck, combineDeck
/*
/* DESCRIPTION: combines the two temporary stacks into one, alternating taking
/*              one card from each stack.  When one stack runs out it puts the
/*              rest of the cards from the other stack onto the main stack
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: none
/***********************************************/
void Deck::combineDeck(){
    int lowest;
    Card stack1;
    Card stack2;
    Card leftOverCard;
    if(stack1Rand<stack2Rand)
        lowest = stack1Rand;
    else
        lowest = stack2Rand;

    for(int i=0; i<lowest; i++)
    {
        stack1 = tempStack1.pop();
        //deckOfCards.push(stack1);
        this->push(stack1);
        stack2 = tempStack2.pop();
        //deckOfCards.push(stack2);
        this->push(stack2);
    }

    if(tempStack1.isEmpty())
    {
        int leftOver1;
        leftOver1 = stack2Rand - lowest;
        for(int k=0; k<leftOver1; k++)
        {
            leftOverCard = tempStack2.pop();
            //deckOfCards.push(leftOverCard);
            this->push(leftOverCard);
        }
    }
    else
    {
        int leftOver2;
        leftOver2 = stack1Rand - lowest;
        for(int l=0; l<leftOver2; l++)
        {
            leftOverCard = tempStack1.pop();
            //deckOfCards.push(leftOverCard);
            this->push(leftOverCard);
        }
    }
}

#endif
