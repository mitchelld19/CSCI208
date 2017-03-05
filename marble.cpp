#ifndef marble_cpp
#define marble_cpp
#include <string>
#include "marble.h"

Marble::Marble(){
    this->color = "blue";
}

Marble::Marble(string color){
  this->color = color;
}

void Marble::setColor(string color){
    this->color = color;
}

string Marble::getColor(){
    return color;
}


#endif
