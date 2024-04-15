// Hunter Peasley and John Mulhern
// PA2 - Mario

#include "Level.h"
#include <iostream>
using namespace std;

Level::Level(){ //default constructor
}


Level::~Level(){ //destructor
}

void Level::buildLevel(int size, int coinModifier, int mushModifier, int gModifier, int kModifier, int xModifier){ //buildLevel method
    
    srand(time(0));  //generates random number
    int lvlSize = size;  //size of the level
    int randnum; //random number
    int coinMod = coinModifier; //coins element
    int mushMod = mushModifier; //mushrooms elemenmt
    int gMod = gModifier; //goomba element
    int kMod = kModifier; //koopa element
    int xMod = xModifier; //empty element
    int bossXCheck; //check for boss' X position
    int bossYCheck; //check for boss' Y position
    int pipeXCheck; //check for pipe's X position
    int pipeYCheck; //check for pipe's Y position 
    int heroXCheck; //check for hero's X position
    int heroYCheck; //check for hero's Y position

    char level[lvlSize][lvlSize]; //level array
    for(int i = 0; i<lvlSize;i++){ //for each row in level
        for(int j = 0; j<lvlSize;j++){ //for each column in level
            randnum = rand() % 100; 

            //if random number <= the percentages the elements are in the level
            if(randnum<=coinMod){
                level[i][j] = 'c';
            }else if(randnum<=(coinMod + mushMod)){
                level[i][j] = 'm';
            }else if(randnum<=(coinMod + mushMod + gMod)){
                level[i][j] = 'g';
            }else if(randnum<=(coinMod + mushMod + gMod + kMod)){
                level[i][j] = 'k';
            }else{
                level[i][j] = 'x';
            }
        }
    }
    //sets the element's X and Y positions equal to random numbers modulo size of level
    bossXCheck = rand() % lvlSize;
    bossYCheck = rand() % lvlSize;
    pipeXCheck = rand() % lvlSize;
    pipeYCheck = rand() % lvlSize;
    heroXCheck = rand() % lvlSize;
    heroYCheck = rand() % lvlSize;

    //the boss's position in the level
    level[bossXCheck][bossYCheck] = 'B';
    //if pipe position equals boss position, 
    if(pipeXCheck==bossXCheck && pipeYCheck==bossYCheck){
        level[rand() % lvlSize][rand() % lvlSize] = 'P';
    }else{
        level[pipeXCheck][pipeYCheck] = 'P';
    }

    if(heroXCheck==bossXCheck && heroYCheck==bossYCheck){
        level[rand() % lvlSize][rand() % lvlSize] = 'H';
    }else if(heroXCheck==pipeXCheck && heroYCheck == pipeYCheck){
        level[rand() % lvlSize][rand() % lvlSize] = 'H';
    }else{
        level[heroXCheck][heroYCheck] = 'H';
    }

    //for loop that prints out the level array with it's elements
    for(int i = 0; i<lvlSize;i++){
        for(int j = 0; j<lvlSize;j++){
            cout << level[i][j];
        }
        cout << endl;
    }
}