#ifndef monte_cpp
#define monte_cpp
#include <string>
#include "card.h"
#include "monte.h"
#include <cstdlib>
#include <ctime>

template <typename M>
Monte<M>::Monte(){
    thingArray = new M[3];
}


template <typename M>
void Monte<M>::setThing1(M thing1){
    this->thingArray[0] = thing1;
}

template <typename M>
void Monte<M>::setThing2(M thing2){
    this->thingArray[1] = thing2;
}

template <typename M>
void Monte<M>::setThing3(M thing3){
    this->thingArray[2] = thing3;
}

template <typename M>
void Monte<M>::shuffle(){
    srand(time(0));

    for (int i=0; i<3; i++) {
        int r = rand() % 3;
        M temp = thingArray[i];
        thingArray[i] = thingArray[r];
        thingArray[r] = temp;
    }
}

template <typename M>
M Monte<M>::pick(int guess){
    int index = guess-1;
    return thingArray[index];
}

#endif
