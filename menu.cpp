// menu example
#include "card.h"
#include "deck.h"
#include "tool.h"
#include "rock.h"
#include "paper.h"
#include "scissors.h"
#include "marble.h"
#include "monte.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Node.h"
#include "playingHand.h"
#include "discardPile.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>



using namespace std;
// Function Prototypes
void showMenu();
void doRandomCard(); // build to make switch statement easier to read
void doWar();
void doBlackjack();
void doMagicTrick();
void doRPS();
void doMarbleMonte();
void doCardMonte();
void doCrazy8();
void invalidInputReset();  // resets console after invalid input
int calculatePoints(Card); //Calculates Points for blackjack card


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
        case 4 : // Magic Trick
			doMagicTrick();
			break;
        case 5 : // Rock Paper Scissors Game
			doRPS();
			break;
        case 6:
            doMarbleMonte();
            break;
        case 7:
            doCardMonte();
            break;
        case 8:
            doCrazy8();
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
     cout<<"4  Play Magic Trick"<<endl;
     cout<<"5  Play Rock Paper Scissors"<<endl;
     cout<<"6  Play Marble Monte"<<endl;
     cout<<"7  Play Card Monte"<<endl;
     cout<<"8  Play Crazy 8"<<endl;
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
		Card random1;

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
		Card p1Card;
		Card p2Card;
		int round = 1, player1 = 0, player2 = 0;
		char anotherRound;

		do{
			p1Card = warDeck.randomCard();
			p2Card = warDeck.randomCard();

			if(p1Card > p2Card)
			{
				player1++;
				cout << endl << "Round " << round << ": " << endl
				<< "Player 1: " << p1Card << endl
				<< "Player 2: " << p2Card << endl
				<< "Winner is Player 1"<< endl << endl;

				round++;
			}
			else if(p1Card < p2Card)
			{
				player2++;
				cout << endl << "Round " << round << ": " << endl
				<< "Player 1: " << p1Card << endl
				<< "Player 2: " << p2Card << endl
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
		Card playerCard1 = blackjackDeck.randomCard();
		Card playerCard2 = blackjackDeck.randomCard();
		Card houseCard1 = blackjackDeck.randomCard();
		Card houseCard2 = blackjackDeck.randomCard();
		int playerTotal = 0, houseTotal = 0, count=1;
		char anotherCard;
		Card anotherPlayerCard;
		Card anotherHouseCard;

		cout << "House Cards: " << endl
		<< "1: " << houseCard1 << endl
		<< "2: " << houseCard2;

		houseTotal = calculatePoints(houseCard1) + calculatePoints(houseCard2);
		cout << endl << "House Total: " << houseTotal << endl << endl;

		cout << "Player Cards: " << endl
		<< "1: " << playerCard1 << endl
		<< "2: " << playerCard2;

		playerTotal = calculatePoints(playerCard1) + calculatePoints(playerCard2);
		cout << endl <<  "Player Total: " << playerTotal << endl << endl;

		cout << "Player would you like another card? [Y/N]" << endl;
		cin >> anotherCard;

		while(anotherCard == 'Y' || anotherCard == 'y'){

			anotherPlayerCard = blackjackDeck.randomCard();
			cout << endl << "Another Player Card: " << anotherPlayerCard << endl;

			playerTotal += calculatePoints(anotherPlayerCard);
			cout<< "Player Total: " << playerTotal << endl << endl;

			cout << "Player would you like another card? [Y/N]" << endl;
			cin >> anotherCard;
		}

		while((houseTotal < playerTotal)&&((houseTotal<21)&&(playerTotal<21)))
		{
			anotherHouseCard = blackjackDeck.randomCard();
			cout << endl << "Another House Card: " << anotherHouseCard << endl;

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
// Function : calculatePoints
// Input: card pointer
// output: int rank
// Description: This function calculates the points for a card based on the rank
//*****************************************
int calculatePoints(Card card)
{
	if(card.getRankInt() <= 10)
		return card.getRankInt();
	else
		return 10;
}




//***************************************
// Function : doMagicTrick
// Input: none
// output: none
// Description: This function picks a random card and changes it to Queen of Hearts
//*****************************************
	void doMagicTrick()
	{
		cout << endl << "Play Magic Trick" << endl << endl;

		Deck magicDeck;
        Card random;
        Card magicCard;

        random = magicDeck.randomCard();
        cout << random << endl;

        cout << "ABRA KADABRA ALAKAZAM!" << endl;

        magicCard = magicTrick(random);
        cout << magicCard << endl;

        magicDeck.~Deck();
	}

//***************************************
// Function : magicTrick
// Input: Card pointer
// output: card pointer
// Description: This function changes the passed in card to Queen of Hearts
//*****************************************
Card magicTrick(Card card){
	Card changedCard;
	card.setRank(12);
	card.setCardSuit(HEARTS);

	changedCard = card;
	return card;
}



//***************************************
// Function : doRPS
// Input: none
// output: none
// Description: This function does everything needed to play Rock, Paper, Scissors
//*****************************************
	void doRPS()
	{
        srand(time(0));
        /*Rock r1;
        Rock r2;
        Scissors s1;
        Scissors s2;
        Paper p1;
        Paper p2;*/
        Tool *player;
        Tool *computer;
        int result, p1Points=0, compPoints=0, computerTool, round=1;
        char playerTool, invalidTool;

        cout << "This game is the best out of 3!" << endl << endl;

        while(round <= 3){
            cout << "Round " << round << endl;

            do{
                invalidTool = 'N';
                cout << "Please choose r for Rock, p for Paper, s for Scissors: ";
                cin >> playerTool;

                if ((playerTool == 'r')||(playerTool == 'R'))
                    player = new Rock();
                else if ((playerTool == 'p')||(playerTool == 'P'))
                    player = new Paper();
                else if ((playerTool == 's')||(playerTool == 'S'))
                    player = new Scissors();
                else
                {
                    cout << "You selected an invalid response, Please try again: ";
                    invalidTool = 'Y';
                }
            }while(invalidTool == 'Y');

            cout << endl << "Player: " << player->getType() << endl;

            computerTool = rand() % 3;
            if (computerTool == 0)
                computer = new Rock();
            else if (computerTool == 1)
                computer = new Paper();
            else if (computerTool = 2)
                computer = new Scissors();

            cout << "Computer: " << computer->getType() << endl << endl;

            result = computer->fight(player);
            if(result == 1)
            {
                compPoints+=1;
                cout << "Computer wins round " << round << endl;
            }
            else if(result == 2)
            {
                p1Points+=1;
                cout << "Player wins round " << round << endl;
            }
            else
                cout << "It was a tie!" << endl;

            cout << endl << "Round " << round << " Points" << endl;
            cout << "Computer: " << compPoints << endl;
            cout << "Player: " << p1Points << endl << endl;

            round++;

            delete player;
            player = NULL;

            delete computer;
            computer = NULL;
        }

        if(compPoints>p1Points)
            cout << "Computer Wins!" << endl << endl;
        else if(p1Points>compPoints)
            cout << "Player Wins!" << endl << endl;
        else
            cout << "It was a tie!" << endl << endl;
	}



//***************************************
// Function : doMarbleMonte
// Input: none
// output: none
// Description: This function does everything needed to play Marble Monte
//*****************************************
	void doMarbleMonte()
	{
	    Marble marble1("Yellow");
        Marble marble2("Yellow");
        Marble marble3("Red");

        int marbleMonteGuess;
        Monte<Marble> marbleMonte;
        marbleMonte.setThing1(marble1);
        marbleMonte.setThing2(marble2);
        marbleMonte.setThing3(marble3);

        do{
            cout << "Which is the Red Marble?"<<endl;

            cout << "Which one do you choose? 1, 2, or 3? ";
            cin >> marbleMonteGuess;

            if((marbleMonteGuess > 3)||(marbleMonteGuess < 1)){
                cout << "You chose an invalid number.  Please try again." << endl;
            }
        }while((marbleMonteGuess > 3)||(marbleMonteGuess < 1));

        marbleMonte.shuffle();

        cout << "You chose " << marbleMonte.pick(marbleMonteGuess).getColor() << endl;

        if(marbleMonte.pick(marbleMonteGuess).getColor()=="Red")
            cout << "You win!" << endl;
        else
            cout << "You lose" << endl;


	}



//***************************************
// Function : doCardMonte
// Input: none
// output: none
// Description: This function does everything needed to play Card Monte
//*****************************************
	void doCardMonte()
	{
        Card card1(12, HEARTS);
        Card card2(10, SPADES);
        Card card3(4, DIAMONDS);

        Monte<Card> cardMonte;
        cardMonte.setThing1(card1);
        cardMonte.setThing2(card2);
        cardMonte.setThing3(card3);

        int cardMonteGuess;
        do{
            cout << "Which is the queen of hearts?"<<endl;

            cout << "Which one do you choose? 1, 2, or 3? ";
            cin >> cardMonteGuess;

            if((cardMonteGuess > 3)||(cardMonteGuess < 1)){
                cout << "You chose an invalid number.  Please try again." << endl;
            }
        }while((cardMonteGuess > 3)||(cardMonteGuess < 1));

        cardMonte.shuffle();

        cout << "You chose " << cardMonte.pick(cardMonteGuess).toString() << endl;

        if(cardMonte.pick(cardMonteGuess).toString() == "Queen of Hearts")
            cout << "You Win!" << endl;
        else
            cout << "You Lose" << endl;
	}


//***************************************
// Function : doCrazy8
// Input: none
// output: none
// Description: This function does everything needed to play Crazy 8
//*****************************************
void doCrazy8(){
    try{
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
	if(answerRank == 60){
		answerSuit = compHand.findSuitPos(discardPile.peek());
		if(answerSuit == 60){
			compHand.insertFront(stockPile.pop());
		}
		else{
			retrievedCard = compHand.retrieveAtPos(answerSuit);
			discardPile.push(retrievedCard);
			cout << endl<< "Computer played: " << discardPile.peek();
		}
	}
    else{
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
   }while((playerHand.isEmpty()==false)||(compHand.isEmpty()==false)||(stockPile.isEmpty()==false));

    if(playerHand.isEmpty())
        cout << "Player Wins" << endl;
    else if(compHand.isEmpty())
        cout << "Computer Wins" << endl;
    else if(stockPile.isEmpty())
        cout << "Deck Empty" << endl;
    }catch(int){
        if(99){
            cout << "Deck is Empty. Exiting Program.";
	    exit(0);
        }
    }
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
