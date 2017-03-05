#include "card.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
/***************************
/* FILE NAME: Card Class
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION: creates a deck of cards, prints them to the screen, runs test cases, and prints a random card from the deck
/***************************/
int main()
{
int const SIZE = 52;

//array of card objects 
Card cardDeck[SIZE] = {
		Card(1, CLUBS), Card(2, CLUBS), Card(3, CLUBS), Card(4, CLUBS), Card(5, CLUBS), Card(6, CLUBS), Card(7, CLUBS), Card(8, CLUBS), Card(9, CLUBS), Card(10, CLUBS), Card(11, CLUBS), Card(12, CLUBS), Card(13, CLUBS),
		Card(1, DIAMONDS), Card(2, DIAMONDS), Card(3, DIAMONDS), Card(4, DIAMONDS), Card(5, DIAMONDS), Card(6, DIAMONDS), Card(7, DIAMONDS), Card(8, DIAMONDS), Card(9, DIAMONDS), Card(10, DIAMONDS), Card(11, DIAMONDS), Card(12, DIAMONDS), Card(13, DIAMONDS),
		Card(1, HEARTS), Card(2, HEARTS), Card(3, HEARTS), Card(4, HEARTS), Card(5, HEARTS), Card(6, HEARTS), Card(7, HEARTS), Card(8, HEARTS), Card(9, HEARTS), Card(10, HEARTS), Card(11, HEARTS), Card(12, HEARTS), Card(13, HEARTS),
		Card(1, SPADES), Card(2, SPADES), Card(3, SPADES), Card(4, SPADES), Card(5, SPADES), Card(6, SPADES), Card(7, SPADES), Card(8, SPADES), Card(9, SPADES), Card(10, SPADES), Card(11, SPADES), Card(12, SPADES), Card(13, SPADES)
	};

	//Print every card in the deck
	for (int i=0; i<SIZE; i++)
	{
		cout << cardDeck[i].toString() << endl;
	}

	//Test Cases
	try{	
		Card card1(1, HEARTS);
		cout << "Build a Card. Expected output is: Ace of Hearts" << endl;
		cout << card1.toString() << endl;

		Card card2;
		cout << "Build a default Card. Expected result is: Joker" << endl;
		cout << card2.toString() << endl;
	}catch(int x){
		if(x==77)
			cout << "The number you chose is not a valid rank";
		else if(x==99)
			cout << "Your suit is not valid"; 
	}

	//Random Card from Deck
	int random_number;
	srand(time(0));
	random_number = (rand () % 51) + 1;

	cout << "Random Card: " << cardDeck[random_number].toString() << endl;

	return 0;
}
