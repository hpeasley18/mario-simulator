#include "GameWorld.h"
#include "fstream"
#include <string>
using namespace std;

int main(int argc, char** argv){
    int numLevels, levelSize, numLives, pCoins, pMush, pGoomba, pKoopa, pEmpty;
    ifstream text(argv[1]);
    string content;
    for(int i = 0; i<8; i++){ // takes the information from the input file and assigns it with the proper variable in an integer format
        getline(text, content);
        switch(i){
            case 0:
                numLevels = stoi(content);
            case 1:
                levelSize = stoi(content);
            case 2:
                numLives = stoi(content);
            case 3:
                pCoins = stoi(content);
            case 4:
                pMush = stoi(content);
            case 5:
                pGoomba = stoi(content);
            case 6:
                pKoopa = stoi(content);
            case 7:
                pEmpty = stoi(content);
        }
    }
    GameWorld world; // creates the world object
    Mario mario(numLives); // creates the Mario object to be used inside the playGame class
    world.createWorld(numLevels, levelSize); // creates the World based off of the number of levels and the size of the Levels
    world.createLevel(pCoins, pMush, pGoomba, pKoopa, pEmpty); // creates the levels based off of file input
    world.playGame(mario, argv[2]); // Plays the game with the mario object and outputs the information to an output file
}

// you've reached the end, have a good day!