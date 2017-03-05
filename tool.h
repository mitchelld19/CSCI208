#ifndef tool_h
#define tool_h
#include <iostream>
#include <string>
#include "tool.h"
using namespace std;

/********************************************
/* CLASS NAME: Tool
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION OF FUNCTION: Creates a Tool with a type and a fight function
/***********************************************/

class Tool{
    protected:
        string type;

    public:
        Tool();
        string getType();
        virtual int fight(Tool *)=0;
};
#endif
