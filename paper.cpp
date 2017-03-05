#ifndef paper_cpp
#define paper_cpp

#include "paper.h"

Paper::Paper(){
  type = "Paper";
};

int Paper::fight(Tool* t){
    if(t->getType() == "Rock")
       return 1;
    else if(t->getType() == "Scissors")
        return 2;
    else if(t->getType() == "Paper")
        return 0;
}

#endif
