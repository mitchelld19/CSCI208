#ifndef playingHand_cpp
#define playingHand_cpp

#include "card.h"
#include "deck.h"
#include "playingHand.h"

playingHand::playingHand(){};

playingHand::playingHand(Deck& d){
    for(int i=0; i<7; i++)
    {
        this->insertFront(d.pop());
    }
};

void playingHand::printCards(){
    Node<Card> * tempPtr = headNodePtr;
	int count1=1;
	if(isEmpty())
		cout << "Nothing here" << endl;
	else{

		while (tempPtr->getNext() != NULL)
		{
			cout << count1 << ": " << tempPtr->getItem();
			tempPtr = tempPtr->getNext();
			count1++;
		}
			cout << count1 << ": " << tempPtr->getItem() << endl;
	}
}

int playingHand::findRankPos(Card card1){
	int x = 0;
	Node<Card> * tempPtr;
	tempPtr = headNodePtr;
	if (isEmpty())
		cout << "Empty" << endl;
	else{
		while ((tempPtr->getNext() != NULL) && (tempPtr->getItem().getRankInt() != card1.getRankInt()))
		{
			tempPtr = tempPtr->getNext();
			x++;
		}
		
		if(tempPtr->getNext() == NULL)
			x = 60;
	}
	return x;
}

int playingHand::findSuitPos(Card card1){

	int x = 0;
	Node<Card> * tempPtr;
	tempPtr = headNodePtr;
	if (isEmpty())
		cout << "Empty" << endl;
	else{
		while ((tempPtr->getNext() != NULL) && (tempPtr->getItem().getSuitInt() != card1.getSuitInt()))
		{
			tempPtr = tempPtr->getNext();
			x++;
		}
		
		if(tempPtr->getNext() == NULL)
			x = 60;

	}
	return x;

}

#endif
