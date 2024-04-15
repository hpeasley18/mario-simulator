// Hunter Peasley and John Mulhern
// PA2- Mario
 
#ifndef MARIO_H
#define MARIO_H

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Mario {
public:
    Mario(); //default constructor
    Mario(int lives);
    
    void collectMushroom();
    
    void collectCoins();
    int getCoins();
    
    int checkLives();
    int getPowerLevel();
    int getEnemiesDefeated();
    
    bool fightGoomba();
    bool fightKoopa();
    bool fightBoss();

private:
    int power_level = 0;
    int m_enemies_defeated = 0;
    int m_coins = 0;
    int m_lives;
    int m_mushrooms;
    bool m_defeated = false;
};

#endif  // MARIO_H