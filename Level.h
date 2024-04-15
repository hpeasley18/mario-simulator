// Hunter Peasley and John Mulhern
// PA2 - Mario

#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <iostream>
#include <cstdlib>
using namespace std; //importing standard library

class Level{
    public:
        Level(); //default constructor
        virtual ~Level(); //destructor
        void buildLevel(int size, int coinModifier, int mushModifier, int gModifier, int kModifier, int xModifier); // buildLevel method
};

#endif