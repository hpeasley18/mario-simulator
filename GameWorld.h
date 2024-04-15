#ifndef GAME_WORLD_H
#define GAME_WORLD_H
#include "Mario.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

class GameWorld{
    public:
        GameWorld();
        virtual ~GameWorld();
        char*** createWorld(int numLevels, int size);
        void createLevel(int coinModifier, int mushModifier, int gModifier, int kModifier, int xModifier);
        void printWorld();
        void printLevel();
        void playGame(Mario mario, string output);

        int getMarioLevel();
        int getMarioRow();
        int getMarioColumn();

        void setMarioLevel(int level);
        void setMarioRow(int row);
        void setMarioCol(int column);

        int getSize();
        int getLevels();

        void changeMarioRow(int change);
        void changeMarioCol(int change);

        char*** getArray();
    private:
        int m_levels;
        int m_size;
        int m_lives;
        int m_coinMod;
        int m_mushMod;
        int m_gMod;
        int m_kMod;
        int m_xMod;

        int m_MarioLevel;
        int m_MarioRow;
        int m_MarioColumn;

        char*** worldArray;
};

#endif


