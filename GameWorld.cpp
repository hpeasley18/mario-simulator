// Hunter Peasley and John Mulhern
// PA2 - Mario


#include "GameWorld.h"
#include <fstream>
#include <sstream>

GameWorld::GameWorld(){ //default constructor
    //variables if no input values are used
    m_levels = 1;
    m_size = 2;
    m_coinMod = 15;
    m_mushMod = 15;
    m_gMod = 50;
    m_kMod = 10;
    m_xMod = 10;
    worldArray = createWorld(m_levels, m_size);
}

GameWorld::~GameWorld(){ // destructor
}

char*** GameWorld::createWorld(int levels, int size){ // create world method with parameters: levels and array size
    m_levels = levels; // sets m_levels equal to levels
    m_size = size; // sets m_size equal to size
    char*** world = new char**[levels];
    for(int i = 0; i < levels; i++){ // for each row in levels
        world[i] = new char*[size]; // create new world array of row size length
        for(int j = 0; j < size; j++){ // for each column in levels
            world[i][j] = new char[size]; // create new world array with rows and columns
        }
    }
    worldArray = world; // set worldArray equal to the array: world
    return worldArray; //returns worldAwway of a certain square size
}

// createLevel method with parameters: lives, coinModifier, mushModifier, gModifier, kModifier, xModifier
void GameWorld::createLevel(int coinModifier, int mushModifier, int gModifier, int kModifier, int xModifier){
   
    srand(time(0)); // generates random number
    int randnum;
    m_coinMod = coinModifier; // sets m_coinMod equal to coin element percentage
    m_mushMod = mushModifier; // sets m_mushMod equal to mushroom element percentage
    m_gMod = gModifier; // sets m_gMod equal to Goomba element percentage
    m_kMod = kModifier; // sets m_kMod equal to Koopa element percentage
    m_xMod = xModifier; // sets m_xMod equal to 'empty' element percentage
   
   //boss and pipe position variables
    int bossXCheck;
    int bossYCheck;
    int pipeXCheck;
    int pipeYCheck;
    int heroXCheck;
    int heroYCheck;   

    for(int i = 0; i<m_levels; i++){ //increment through each level
        for(int j = 0; j<m_size;j++){ //increment each row 
            for(int k = 0; k<m_size;k++){ //increment through each column 
                randnum = rand() % 100;

                if(randnum<=m_coinMod){// if random number is less than or equal to coin percentage
                    worldArray[i][j][k] = 'c'; // put a 'c' at the specific level, row, and column position
                }else if(randnum<=(m_coinMod + m_mushMod)){  // if random number is less than or equal to coin percentage + mushroom percentage
                    worldArray[i][j][k] = 'm'; // put a 'm' at the specific level, row, and column position
                }else if(randnum<=(m_coinMod + m_mushMod + m_gMod)){ // if random number is less than or equal to coin percentage + mushroom percentage + goomba percentage
                    worldArray[i][j][k] = 'g'; // put a 'g' at the specific level, row, and column position
                }else if(randnum<=(m_coinMod + m_mushMod + m_gMod + m_kMod)){ // if random number is less than or equal to coin percentage + mushroom percentage + goomba percentage + koopa percentage
                    worldArray[i][j][k] = 'k'; // put a 'k' at the specific level, row, and column position
                }else{ //if it doesn't fulfill any of those statements
                    worldArray[i][j][k] = 'x'; // put a 'x' at the specific level, row, and column position
                }
            }
        }
    }

     //makes random numbers for the row and column positions of boss and pipe
    for(int i = 0; i<m_levels; i++){ //for each level
        bossXCheck = rand() % m_size; //boss put in a random row
        bossYCheck = rand() % m_size; //boss put in a random column
        pipeXCheck = rand() % m_size; //pipe put in a random row
        pipeYCheck = rand() % m_size; //pipe put in a random column
        worldArray[i][bossXCheck][bossYCheck] = 'B';
        if(pipeXCheck==bossXCheck && pipeYCheck==bossYCheck){ // put in while loop for confirmed different location
            worldArray[i][rand() % m_size][rand() % m_size] = 'P';
        }else{
            worldArray[i][pipeXCheck][pipeYCheck] = 'P';
        }
    }
}

void GameWorld::printWorld(){ // printWorld method where it prints the array and it's elements
    for(int i = 0; i<m_levels;++i){ // for each level
        for(int j = 0; j<m_size;++j){ // for each row in level
            for(int k = 0; k<m_size;++k){ // for each column in level
                cout << worldArray[i][j][k] << " "; // print the world array and each of it's elements
            }
            cout << endl; // print new line
        }
        cout << endl; // print new line
    }
}

void GameWorld::playGame(Mario mario, string output){ // this function runs the game based off of Mario's lives given from main, and outputs it all to a file. 
    ofstream outputFile;
    outputFile.open(output);
    outputFile << "GAME START!" << endl;
    outputFile << "Levels: " << m_levels << endl;
    outputFile << "Dimension: " << m_size << " by " << m_size << endl;
    outputFile << endl;
    outputFile << endl;
    for(int i = 0; i<m_levels;i++){ // loops through the levels and executes the while loop listed below for each level
        bool pipeFound = false;
        bool victory = false;
        m_MarioLevel = i;
        m_MarioRow = rand() % m_size-1;
        m_MarioColumn = rand() % m_size-1;
        worldArray[i][m_MarioRow][m_MarioColumn] = 'H';
        int newMarioRow = 0;
        int newMarioColumn = 0;
        srand(time(0));
        while((mario.checkLives() != 0) && (pipeFound == false)){ // essentially, this while loop executes the game. It creates a random number, moves mario in that random direction 
            int direction = rand() % 4; // while checking what is there, and executing the proper response to be printed to the output file 
            switch(direction){ // generates the random direction
                case 0:
                    newMarioRow = m_MarioRow -1;
                    newMarioColumn = m_MarioColumn;
                    if(newMarioRow < 0){
                        newMarioRow = m_size-1;
                    }
                    break;
                case 1:
                    newMarioColumn = m_MarioColumn +1;
                    newMarioRow = m_MarioRow;
                    if(newMarioColumn == m_size){
                        newMarioColumn = 0;
                    }
                    break;
                case 2:
                    newMarioRow = m_MarioRow +1;
                    newMarioColumn = m_MarioColumn;
                    if(newMarioRow == m_size){
                        newMarioRow = 0;
                    }
                    break;
                case 3:
                    newMarioColumn = m_MarioColumn -1;
                    newMarioRow = m_MarioRow;
                    if(newMarioColumn < 0){
                        newMarioColumn = m_size-1;
                    }
                    break;
            }
            char t = worldArray[i][newMarioRow][newMarioColumn];
            switch(t){ // checks what is at the grid space that Mario wants to move to, and generates the proper response to the output file
                case 'c': // response for a coin
                    outputFile << "Mario found a coin!" << endl;
                    mario.collectCoins();
                    worldArray[i][newMarioRow][newMarioColumn] = 'H';
                    worldArray[i][m_MarioRow][m_MarioColumn] = 'x';
                    m_MarioColumn = newMarioColumn;
                    m_MarioRow = newMarioRow;
                    break;
                case 'm': // response for a mushroom
                    outputFile << "Mario found a mushroom!" << endl;
                    mario.collectMushroom();
                    worldArray[i][newMarioRow][newMarioColumn] = 'H';
                    worldArray[i][m_MarioRow][m_MarioColumn] = 'x';
                    m_MarioColumn = newMarioColumn;
                    m_MarioRow = newMarioRow;
                    break;
                case 'g': // response for a Goomba
                    victory = false;
                    outputFile << "Mario found a Goomba!" << endl;
                    while(victory == false){
                        if(mario.fightGoomba() == false){
                            victory = true;
                            outputFile << "Mario Won!" << endl;
                        }else{
                            outputFile << "Mario lost and will try again." << endl << endl;
                            if(mario.checkLives() == 0){
                                break;
                            }
                        }
                    }
                    worldArray[i][newMarioRow][newMarioColumn] = 'H';
                    worldArray[i][m_MarioRow][m_MarioColumn] = 'x';
                    m_MarioColumn = newMarioColumn;
                    m_MarioRow = newMarioRow;
                    break;
                case 'k': //response for a Koopa
                    victory = false;
                    outputFile << "Mario found a Koopa!" << endl;
                    while(victory == false){
                        if(mario.fightKoopa() == false){
                            victory = true;
                            outputFile << "Mario Won!" << endl;
                        }else{
                            outputFile << "Mario lost and will try again." << endl << endl;
                            if(mario.checkLives() == 0){
                                break;
                            }
                        }
                    }
                    worldArray[i][newMarioRow][newMarioColumn] = 'H';
                    worldArray[i][m_MarioRow][m_MarioColumn] = 'x';
                    m_MarioColumn = newMarioColumn;
                    m_MarioRow = newMarioRow;
                    break;
                case 'x': // response for nothing
                    outputFile << "Mario didn't find anything." << endl;
                    worldArray[i][newMarioRow][newMarioColumn] = 'H';
                    worldArray[i][m_MarioRow][m_MarioColumn] = 'x';
                    m_MarioColumn = newMarioColumn;
                    m_MarioRow = newMarioRow;
                    break;
                case 'B': // response for a Boss
                    victory = false;
                    outputFile << "Mario found the Level Boss!" << endl;
                    while(victory == false){
                        if(mario.fightBoss() == false){
                            victory = true;
                            outputFile << "Mario Won!" << endl;
                        }else{
                            outputFile << "Mario lost and will try again." << endl << endl;
                            if(mario.checkLives() == 0){
                                break;
                            }
                        }
                    }
                    worldArray[i][newMarioRow][newMarioColumn] = 'H';
                    worldArray[i][m_MarioRow][m_MarioColumn] = 'x';
                    m_MarioColumn = newMarioColumn;
                    m_MarioRow = newMarioRow;
                    break;
                case 'P': // response for the Warp Pipe
                    outputFile << "Mario found the Warp Portal! Moving to next Level: " << endl << endl;
                    outputFile << "-----------------------------------------------------------" << endl;
                    pipeFound = true;
                    break;
            }
            for(int i = m_MarioLevel; i<m_MarioLevel + 1;i++){ // prints the updated grid to the output file
                for(int j = 0; j<m_size;j++){
                    for(int k = 0; k<m_size; k++){
                        outputFile << worldArray[i][j][k] << " ";
                    }
                outputFile << endl;
            }
            outputFile << endl; // outputs after the grid the amount of coins collected, Mario's power level, the total enemies defeated, and Mario's # of lives
            outputFile << "Coins Collected: " << mario.getCoins()<< endl;
            outputFile << "Mario's Power Level: " << mario.getPowerLevel() << endl;
            outputFile << "Enemies Defeated: " << mario.getEnemiesDefeated() << endl;
            outputFile << "Mario's Lives: " << mario.checkLives() << endl << endl;
            }
        }
    }
    if(mario.checkLives() == 0){ // checks to see if Mario died or if he won on each file rotation
        outputFile << "Mario has died! Restart the game to try again." << endl;
    }else{
        outputFile << "Mario has defeated the end boss! You've Won!" << endl;
    }
}

void GameWorld::printLevel(){ // printLevel method where it prints the array and it's elements
    for(int i = m_MarioLevel; i<m_MarioLevel+1;i++){ // for each level for Mario
        for(int j = 0; j<m_size;j++){ // for each row in level for Mario
            for(int k = 0; k<m_size; k++){// for each column in level for Mario
                cout << worldArray[i][j][k] << " "; // print the world array and each of it's elements for Mario
            }
            cout << endl; // print new line
        }
        cout << endl; // print new line
    }
}

char*** GameWorld::getArray(){ // get worldArray
    return worldArray; // returns worldArray
}

int GameWorld::getSize(){  // get size of array
    return m_size;  // returns m_size
}

int GameWorld::getLevels(){  // get levels
    return m_levels;  // returns m_levels
}

int GameWorld::getMarioLevel(){  // get Mario levels
    return m_MarioLevel;  // returns m_Mariolevel
}

int GameWorld::getMarioRow(){ // get Mario rows
    return m_MarioRow; // returns m_MarioRow
}

int GameWorld::getMarioColumn(){// get Mario columns
    return m_MarioColumn; // returns m_MarioColumn
}

void GameWorld::setMarioLevel(int level){ // setMarioLevel method with level param
    m_MarioLevel = level; // sets m_MarioLevel equal to level
}

void GameWorld::setMarioRow(int row){ // setMarioRow method with row param
    m_MarioRow = row; // sets m_MarioRow equal to row
}

void GameWorld::setMarioCol(int col){ // setMarioCol method with column param
    m_MarioColumn = col; // sets m_MarioColumn equal to col
}

void GameWorld::changeMarioRow(int change){
    m_MarioRow += change;
}

void GameWorld::changeMarioCol(int change){
    m_MarioColumn += change;
}


