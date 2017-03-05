#include "LinkedList.h"
#include "deck.h"
#include "card.h"
#include "Stack.h"
#include "Node.h"
#include "playingHand.h"
#include "discardPile.h"
#include<iostream>
using namespace std;

int main(){

    static const int playerCheating = 8003;

    Deck stockPile;
    discardPile discardPile;
    stockPile.shuffleDeck();
    Card retrievedCard;
    bool found, invalidChoice;
    int answerRank, answerSuit, playerChoice, index, round=1;

    playingHand compHand(stockPile);
    playingHand playerHand(stockPile);

    discardPile.push(stockPile.pop());

	cout << endl;

   do{
	cout << "-------------------------------------------------------------" << endl;
	cout << "Round " << round << endl;


	//Comp
   	answerRank = compHand.findRankPos(discardPile.peek());
	if(answerRank == 60)
	{
		answerSuit = compHand.findSuitPos(discardPile.peek());
		if(answerSuit == 60)
		{
			compHand.insertFront(stockPile.pop());
		}
		else
		{
			retrievedCard = compHand.retrieveAtPos(answerSuit);
			discardPile.push(retrievedCard);
			cout << endl<< "Computer played: " << discardPile.peek();
		}
	}
    	else
	{
		retrievedCard = compHand.retrieveAtPos(answerRank);
		discardPile.push(retrievedCard);
	}



	//Player
		do{
			cout << endl << "Top card in discard pile: " << discardPile.peek();

			playerHand.printCards();


			cout << "Which card would you like to play? To draw a card press 99. ";
			cin >> playerChoice;

			index = playerChoice-1;
			if(playerChoice != 99){
				try{
					retrievedCard = playerHand.retrieveAtPos(index);
				}catch(int){
					if(8001)
					{
						cout << "ERROR: Card not found! Exiting Program. " << endl;
						exit(0);
					}
				}

				if((retrievedCard.getRankString() == discardPile.peek().getRankString())||(retrievedCard.getSuitString() == discardPile.peek().getSuitString()))
				{
					discardPile.push(retrievedCard);
					cout << "You played: " << discardPile.peek();
					invalidChoice = false;
				}
				else
				{
					cout << "You chose an invalid card! Please choose again. " << endl;
					invalidChoice = true;
				}
			}
			else if(playerChoice == 99){
				cout << "You drew " << stockPile.peek();
				playerHand.insertFront(stockPile.pop());

			}
			round++;
		}while(invalidChoice == true);

		if(playerHand.isEmpty())
        cout << "Player Wins" << endl;
       else if(compHand.isEmpty())
        cout << "Computer Wins" << endl;
       else if(stockPile.isEmpty())
        cout << "Deck Empty" << endl;


   }while((playerHand.isEmpty()==false)||(compHand.isEmpty()==false)||(stockPile.isEmpty()==false));


   return 0;
}

