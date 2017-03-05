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
	int calculatePoints(Card* card);
	//Test Cases
	try{	
		//Test Card Class
		/*Card card1(1, HEARTS);
		cout << "Build a Card. Expected output is: Ace of Hearts" << endl;
		cout << card1.toString() << endl;

		Card card2;
		cout << "Build a default Card. Expected result is: Joker" << endl;
		cout << card2.toString() << endl;*/
		
		//Test Deck Class
		/*Deck deck1;
		Card* random1;
		Card* random2;
		int cardsChosen=0;
		char again;*/
		//deck1.printDeck();
		
		/*random1 = deck1.randomCard(cardsChosen);
		random2 = deck1.randomCard(cardsChosen);
		cout << random2;*/
		
		/*cout << endl <<  "Random Card 1: " << random1->toString() << endl;
		cout <<  "Random Card 2: " << random2->toString()  << endl  << endl;
		cout << "Random1 Rank: " << random1->getRankInt() << " Suit: " << random1->getSuitInt() <<endl;
		cout << "Random2 Rank: " << random2->getRankInt() << " Suit: " << random2->getSuitInt() <<endl <<endl;
		*/

		
	/*	if (random1<random2)
		{	
			cout << "True. Random1 is less than Random2" << endl;
		}
		else
			cout << "False. Random1 is greater than Random2" << endl;
		
		if (random1>random2)
		{	
			cout << "True. Random1 is greater than Random2" << endl;
		}
		else
			cout << "False. Random1 is less than Random2" << endl;
		*/

		/*do{
			cout << endl << "Random Card: " << deck1.randomCard()->toString() << endl;
			cout << "Would you like to choose another card? Y/N" << endl;
			cin >> again;

		}while(again == 'y' || again == 'Y');
		
		cout << endl << (52-cardsChosen) << " Available Cards Left:" << endl;
		deck1.printDeck();*/
		
		
		
		Deck blackjackDeck;
		Card* playerCard1 = blackjackDeck.randomCard();
		Card* playerCard2 = blackjackDeck.randomCard();
		Card* houseCard1 = blackjackDeck.randomCard();
		Card* houseCard2 = blackjackDeck.randomCard();
		int playerTotal = 0, houseTotal = 0, count=1;
		char anotherCard;
		Card* anotherPlayerCard;
		Card* anotherHouseCard;
		cout << "House Cards: " << endl
		<< "1: " << houseCard1
		<< "2: " << houseCard2;
		
		houseTotal = calculatePoints(houseCard1) + calculatePoints(houseCard2);
		cout << "House Total: " << houseTotal << endl << endl;
		
		cout << "Player Cards: " << endl
		<< "1: " << playerCard1
		<< "2: " << playerCard2;
		
		playerTotal = calculatePoints(playerCard1) + calculatePoints(playerCard2);
		cout << "House Total: " << playerTotal << endl << endl;
		
		cout << "Player would you like another card? [Y/N]" << endl;
		cin >> anotherCard;
		
		while(anotherCard == 'Y' || anotherCard == 'y'){
			
			anotherPlayerCard = blackjackDeck.randomCard();
			cout << endl << "Card: " << anotherPlayerCard;
	
			playerTotal += calculatePoints(anotherPlayerCard);
			cout<< "Player Total: " << playerTotal << endl << endl;
			
			cout << "Player would you like another card? [Y/N]" << endl;
			cin >> anotherCard;
		}
		
		while((houseTotal < playerTotal)&&((houseTotal<21)&&(playerTotal<21)))
		{
			anotherHouseCard = blackjackDeck.randomCard();
			cout << endl << "Card: " << anotherHouseCard;
	
			houseTotal += calculatePoints(anotherHouseCard);
			cout << "House Total: " << houseTotal << endl << endl;
		}	
		
		cout << endl << "Total Scores: " << endl
		<< "House: " << houseTotal << endl
		<< "Player: " << playerTotal << endl << endl;
		
		
		if(playerTotal == 21)
			cout << "Player wins!" << endl;
		else if((playerTotal < 21)&&(houseTotal > 21))
			cout << "Player wins!" << endl;
		else if((playerTotal < 21)&&(houseTotal < 21)&&(playerTotal>houseTotal))
			cout << "Player wins!" << endl;
		else
			cout << "House wins!" << endl;
		
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

int calculatePoints(Card* card)
{
	if(card->getRankInt() <= 10)
		return card->getRankInt();
	else
		return 10;
}