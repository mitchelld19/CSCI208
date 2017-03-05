#ifndef discardPile_cpp
#define discardPile_cpp

#include "card.h"
#include "Stack.h"
#include "discardPile.h"


discardPile::discardPile(){}

Card discardPile::getCrazyEightCard(){
    return crazyEightCard;
}

void discardPile::setCrazyEightCard(Card discardCard){
    this->crazyEightCard = discardCard;
}

#endif
