#ifndef marble_h
#define marble_h
#include <iostream>
#include "marble.h"
using namespace std;


/********************************************
/* CLASS NAME: Marble
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION OF FUNCTION:
/***********************************************/

class Marble{
	private:
        string color;

	public:
        Marble();
        Marble(string color);

        void setColor(string color);
        string getColor();
};
#endif
