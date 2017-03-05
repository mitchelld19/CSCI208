#ifndef rock_cpp
#define rock_cpp

#include "rock.h"

Rock::Rock(){
  type = "Rock";
}

int Rock::fight(Tool* t){
    if(t->getType() == "Scissors")
       return 1;
    else if(t->getType() == "Paper")
        return 2;
    else if(t->getType() == "Rock")
        return 0;
}

#endif
