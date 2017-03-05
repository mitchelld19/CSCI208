#ifndef monte_h
#define monte_h
#include <iostream>
#include "monte.h"
using namespace std;

/********************************************
/* CLASS NAME: Monte
/*
/* AUTHOR: Beth Mitchell
/*
/* DESCRIPTION OF FUNCTION:
/***********************************************/

template <typename M>
class Monte{
	protected:
       M *thingArray;

	public:
        Monte();
        void setThing1(M thing1);
        void setThing2(M thing2);
        void setThing3(M thing3);

        void shuffle();
        M pick(int guess);
};

#include "monte.cpp"
#endif
