// menu example
#include "card.h"
#include "deck.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>



using namespace std;
// Function Prototypes
void showMenu();
void doRandomCard(); // build to make switch statement easier to read
void doWar();
void doBlackjack();
void invalidInputReset();  // resets console after invalid input
int calculatePoints(Card*); //Calculates Points for blackjack card

// Start of main routine
int main()
{
 system("clear");  // clear the screen
int choice=0; // init to ensure while executes once

while (choice!=99){
	showMenu();
	cin >> choice;
		if (cin.fail())  // Input validation error
		{   choice = 0; // reset choice to indicate invalid choice
			invalidInputReset(); // reset cin to valid state
		}
	switch (choice) {
		// Pick a random Card
		case 1 :
		   doRandomCard(); 
		   break;
		case 2 : // play a game of War
			doWar();
			break;
		case 3 : // play a game of blackjack
			doBlackjack();
			break;
		case 99 :  // end game	
			cout << "Thanks for playing " << endl << endl;
			break;
		default :  // not a valid choice
			cout << "Error: not a valid selection " << endl;
			break;

		} // end of switch statement

} // end of while loop

return 0;
}

//***************************************
// Function : showMenu
// Input: none
// output: none
// Description: This function presents the menu
//    options on the screen.
//*****************************************
void showMenu()
{
     cout<<endl << endl << endl << endl;
	 cout << "****  GAME MENU   ******" << endl << endl;
	 cout<<"Please type a choice"<<endl;
     cout<<"1  Pick a random card"<<endl;
     cout<<"2  Play War"<<endl;
     cout<<"3  Play Blackjack"<<endl;
     cout<<"99  Exit the program"<<endl;
    }

//***************************************
// Function : doRandomCard
// Input: none
// output: none
// Description: This function does everything needed to pick a random card
//*****************************************	
	void doRandomCard()  
	{ 
		cout << endl << "Play random card" << endl << endl; 
		
		Deck randomDeck;
		Card* random1;
		
		random1 = randomDeck.randomCard();
		cout << random1 << endl;
		
		randomDeck.~Deck();
	}
	
//***************************************
// Function : doWar
// Input: none
// output: none
// Description: This function does everything needed to play war
//*****************************************
void doWar()  
	{ 
		cout << endl << "Play War" << endl; 
		
		Deck warDeck;
		Card* p1Card;
		Card* p2Card;
		int round = 1, player1 = 0, player2 = 0;
		char anotherRound;
		
		do{
			p1Card = warDeck.randomCard();
			p2Card = warDeck.randomCard();
			
			if(p1Card > p2Card)
			{
				player1++;
				cout << endl << "Round " << round << ": " << endl
				<< "Player 1: " << p1Card 
				<< "Player 2: " << p2Card 
				<< "Winner is Player 1"<< endl << endl;
				
				round++;
			}
			else if(p1Card < p2Card)
			{
				player2++;
				cout << endl << "Round " << round << ": " << endl
				<< "Player 1: " << p1Card 
				<< "Player 2: " << p2Card 
				<< "Winner is Player 2"<< endl << endl;
				
				round++;
			}
			
			cout << "Would you like to play another Round? [Y/N](You can play up to 10 Rounds) " << endl;
			cin >> anotherRound;
		}while((round<=10)&&((anotherRound == 'Y') || (anotherRound == 'y')));
		
		cout << endl << "Score: " << endl
			<< "Player1 - " << player1 << endl
			<< "Player2 - " << player2 << endl << endl;
			
		if(player1>player2)
			cout << "The overall winner is Player 1" << endl;
		else if(player1<player2)
			cout << "The overall winner is Player 2" << endl;
		else
			cout << "It was a tie!\n";
		
		warDeck.~Deck();
			
	}
	
//***************************************
// Function : doBlackjack
// Input: none
// output: none
// Description: This function does everything needed to play blackjack
//*****************************************
void doBlackjack() 
	{ 
		cout << endl << "Play Blackjack" << endl; 
		
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
		cout << "Player Total: " << playerTotal << endl << endl;
		
		cout << "Player would you like another card? [Y/N]" << endl;
		cin >> anotherCard;
		
		while(anotherCard == 'Y' || anotherCard == 'y'){
			
			anotherPlayerCard = blackjackDeck.randomCard();
			cout << endl << "Another Player Card: " << anotherPlayerCard;
	
			playerTotal += calculatePoints(anotherPlayerCard);
			cout<< "Player Total: " << playerTotal << endl << endl;
			
			cout << "Player would you like another card? [Y/N]" << endl;
			cin >> anotherCard;
		}
		
		while((houseTotal < playerTotal)&&((houseTotal<21)&&(playerTotal<21)))
		{
			anotherHouseCard = blackjackDeck.randomCard();
			cout << endl << "Another House Card: " << anotherHouseCard;
	
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
	}
	
//***************************************
// Function : invalidInputReset
// Input: none
// output: none
// Description: This function resets the cin stream object
//      after in invalid input is detected. It clears the error flags
//      and reads any other 'garbage' on the input line past the last '\n'
//*****************************************
void invalidInputReset()
{
	cin.clear(); // clear the error flags
	cin.ignore(); // skip anything else on the line
}
	
	
	
int calculatePoints(Card* card)
{
	if(card->getRankInt() <= 10)
		return card->getRankInt();
	else
		return 10;
}