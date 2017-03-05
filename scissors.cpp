#ifndef scissors_cpp
#define scissors_cpp

#include "scissors.h"

Scissors::Scissors(){
  type = "Scissors";
}

int Scissors::fight(Tool* t){
            if(t->getType() == "Paper")
               return 1;
            else if(t->getType() == "Rock")
                return 2;
            else if(t->getType() == "Scissors")
                return 0;
        }

#endif
