#ifndef scissors_h
#define scissors_h
#include <iostream>
#include "tool.h"
#include "scissors.h"
using namespace std;

/********************************************
/* CLASS NAME: Scissors
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION OF FUNCTION: Creates a Scissors Tool
/***********************************************/

class Scissors:public Tool{
    public:
        Scissors();

        virtual int fight(Tool* t);
};
#endif
