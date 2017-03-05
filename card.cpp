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
				this->rankInt = 1;
				break;
		case 2: this->rankString = "Two";
				this->rankInt = 2;
				break;
		case 3: this->rankString = "Three";
				this->rankInt = 3;
				break;
		case 4: this->rankString = "Four";
				this->rankInt = 4;
				break;
		case 5: this->rankString = "Five";
				this->rankInt = 5;
				break;
		case 6: this->rankString = "Six";
				this->rankInt = 6;
				break;
		case 7: this->rankString = "Seven";
				this->rankInt = 7;
				break;
		case 8: this->rankString = "Eight";
				this->rankInt = 8;
				break;
		case 9: this->rankString = "Nine";
				this->rankInt = 9;
				break;
		case 10: this->rankString = "Ten";
				this->rankInt = 10;
				break;
		case 11: this->rankString = "Jack";
				this->rankInt = 11;
				break;
		case 12: this->rankString = "Queen";
				this->rankInt = 12;
				break;
		case 13: this->rankString = "King";
				this->rankInt = 13;
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
			this->suitInt = 1;
			break;
		case DIAMONDS: this->suitString = "Diamonds";
			this->suitInt = 2;
			break;
		case HEARTS: this->suitString = "Hearts";
			this->suitInt = 3;
			break;
		case SPADES: this->suitString = "Spades";
			this->suitInt = 4;
			break;
		default: this->suitString = "Joker";
	}
}




/********************************************
/* CLASS & METHOD NAMES: Card, getRankString
/*
/* DESCRIPTION: returns the rank string
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: rankString
/***********************************************/
string Card::getRankString(){
	return rankString;
}

/********************************************
/* CLASS & METHOD NAMES: Card, getRankInt
/*
/* DESCRIPTION: returns the rank integer
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: rankInt
/***********************************************/
int Card::getRankInt(){
	return rankInt;
}




/********************************************
/* CLASS & METHOD NAMES: Card, getSuitString
/*
/* DESCRIPTION: returns the card Suit string
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: suitString
/***********************************************/
string Card::getSuitString(){
	return suitString;
}


/********************************************
/* CLASS & METHOD NAMES: Card, getSuitInt
/*
/* DESCRIPTION: returns the card Suit integer
/*
/* PARAMETERS: none
/*
/* RETURN VALUES: suitInt
/***********************************************/
int Card::getSuitInt(){
	return suitInt;
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



bool operator<(Card& leftCard, Card& rightCard){
		if(leftCard.getRankInt() == rightCard.getRankInt())
		{
			if(leftCard.getSuitInt() < rightCard.getSuitInt()){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			if(leftCard.getRankInt() < rightCard.getRankInt()){
				return true;
			}
			else{
				return false;
			}
		}
}


bool operator>(Card& leftCard, Card& rightCard){
		
		if(leftCard.getRankInt() == rightCard.getRankInt())
		{
			if(leftCard.getSuitInt() > rightCard.getSuitInt()){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			if(leftCard.getRankInt() > rightCard.getRankInt()){
				return true;
			}
			else{
				return false;
			}
		}
}

ostream& operator<<(ostream& os, Card* card)
{
	os << card->getRankString() << " of " << card->getSuitString() << endl;
	
	return os;
}

#endif
