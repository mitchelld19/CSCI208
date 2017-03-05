#ifndef card_cpp
#define card_cpp

#include "card.h"
#include <string>

//default constructor
//sets rank to 0 and suit to joker
Card::Card(){
	Card::setRank(0);
	Card::setCardSuit(JOKER);
}


//contructor takes in rank and suit sets the values to the appropriate variables
Card::Card(int rank, CARD_SUITS suit){
	Card::setRank(rank);
	Card::setCardSuit(suit);
	

	//if not a valid rank
	if(rank > 13 || rank < 0)
	{
		throw 77; 
	}

	//if not a valid suit
	else if((suit != JOKER) && (suit != CLUBS) && (suit != DIAMONDS) && (suit != HEARTS) && (suit != SPADES))
	{
		throw 99;
	}
}





/********************************************
/* CLASS & METHOD NAMES: Card, setRank
/*
/* DESCRIPTION: takes the int passed in and sets rankString to the appropriate string form of the int
/*
/* PARAMETERS: int rank
/*
/* RETURN VALUES: none
/***********************************************/
void Card::setRank(int rank){
	switch(rank)
	{
		case 1: this->rankString = "Aces";
				break;
		case 2: this->rankString = "Two";
				break;
		case 3: this->rankString = "Three";
				break;
		case 4: this->rankString = "Four";
				break;
		case 5: this->rankString = "Five";
				break;
		case 6: this->rankString = "Six";
				break;
		case 7: this->rankString = "Seven";
				break;
		case 8: this->rankString = "Eight";
				break;
		case 9: this->rankString = "Nine";
				break;
		case 10: this->rankString = "Ten";
				break;
		case 11: this->rankString = "Jack";
				break;
		case 12: this->rankString = "Queen";
				break;
		case 13: this->rankString = "King";
				break;
		default: this->rankString = "Joker";
	}
}



/********************************************
/* CLASS & METHOD NAMES: Card, setCardSuit
/*
/* DESCRIPTION: takes the CARD_SUITS passed in and sets suitString to the appropriate string form of the suit
/*
/* PARAMETERS: CARD_SUITS suit
/*
/* RETURN VALUES: none
/***********************************************/
void Card::setCardSuit(CARD_SUITS suit){
	switch(suit)
	{
		case CLUBS: this->suitString = "Clubs";
			break;
		case DIAMONDS: this->suitString = "Diamonds";
			break;
		case HEARTS: this->suitString = "Hearts";
			break;
		case SPADES: this->suitString = "Spades";
			break;
		default: this->suitString = "Joker";
	}
}




/********************************************
/* CLASS & METHOD NAMES: Card, getRank
/*
/* DESCRIPTION: returns the rank
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: rankString
/***********************************************/
string Card::getRank(){
	return rankString;
}


/********************************************
/* CLASS & METHOD NAMES: Card, getCardSuit
/*
/* DESCRIPTION: returns the card Suit
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: cardSuitString
/***********************************************/
string Card::getCardSuit(){
	return suitString;
}




/********************************************
/* CLASS & METHOD NAMES: Card, toString
/*
/* DESCRIPTION: combines the rank and suit into one string
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: cardString
/***********************************************/
string Card::toString(){
	if(suitString == "Joker")
		this->cardString = suitString;
	else
		this->cardString = rankString + " of " + suitString;
	return cardString;
}

#endif
