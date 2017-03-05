#ifndef rock_h
#define rock_h
#include <iostream>
#include "tool.h"
#include "rock.h"
using namespace std;

/********************************************
/* CLASS NAME: Rock
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION OF FUNCTION: Creates a Rock Tool
/***********************************************/

class Rock:public Tool{
    public:
        Rock();

        virtual int fight(Tool* t);
};
#endif
