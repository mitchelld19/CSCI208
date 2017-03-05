#ifndef paper_h
#define paper_h
#include <iostream>
#include "tool.h"
#include "paper.h"
using namespace std;

/********************************************
/* CLASS NAME: Paper
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION OF FUNCTION: Creates a Paper Tool
/***********************************************/

class Paper:public Tool{
    public:
        Paper();

        virtual int fight(Tool* t);
};
#endif
