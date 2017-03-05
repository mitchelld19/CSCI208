#include "card.h"
#include "deck.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
/***************************
/* FILE NAME: Deck Program
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION: uses the deck class to create a deck of cards, prints them to the screen, 
/*              pulls a random card and sets it to null, prints deck to screen again to show card removed,
/*              runs test cases for card class and deck class
/***************************/
int main()
{	
	//Test Cases
	try{	
		//Test Card Class
		Card card1(1, HEARTS);
		cout << "Build a Card. Expected output is: Ace of Hearts" << endl;
		cout << card1.toString() << endl;

		Card card2;
		cout << "Build a default Card. Expected result is: Joker" << endl;
		cout << card2.toString() << endl;
		
		//Test Deck Class
		Deck deck1;
		int cardsChosen=0;
		char again;
		deck1.printDeck();
		
		do{
			cout << endl << "Random Card: " << deck1.randomCard(cardsChosen)->toString() << endl;
			cout << "Would you like to choose another card? Y/N" << endl;
			cin >> again;

		}while(again == 'y' || again == 'Y');
		
		cout << endl << (52-cardsChosen) << " Available Cards Left:" << endl;
		deck1.printDeck();
		
		
	}catch(int x){
		if(x==77)
			cout << "The number you chose is not a valid rank" << endl;
		else if(x==99)
			cout << "Your suit is not valid" << endl; 
		else if(x==11)
			cout << "There are no more cards in the deck" << endl;
	}


	return 0;
}
