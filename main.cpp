#include "card.h"
#include "deck.h"
#include "Stack.h"
#include "Node.h"
#include <iostream>
using namespace std;

int main(){
    Deck deck1;
    Card card1;
    deck1.shuffleDeck();
    card1 = deck1.randomCard();
    cout << card1.toString() << endl;

    return 0;
}
