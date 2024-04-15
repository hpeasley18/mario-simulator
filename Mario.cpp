// Hunter Peasley and John Mulhern
// PA2 - Mario

#include "Mario.h"




Mario::Mario(){} //default constructor

Mario::Mario(int lives){ //overloaded constructor
    m_lives = lives; //sets m_lives equal to lives
}

void Mario::collectMushroom(){  //collect mushrooms method
  
    if (power_level < 2){  //if power level less than PL_2
        power_level++; //increase power level
    }
}


int Mario::checkLives(){ //method that checks Mario's lives
    return m_lives; //returns Mario's current lives
}


int Mario::getPowerLevel(){ //method that gets Mario's Power Level
    return power_level; //returns Mario's power level
}

void Mario::collectCoins(){ //method to see how many coins Mario collected

    m_coins++; // increase coins Mario has
    if (m_coins % 20 == 0) { //if Mario gains 20 coins
        m_lives++; //he gains an extra life
    }
}

int Mario::getCoins(){  //method that gets amount of coins
    return m_coins; //returns Mario's current amount of coins 
}

int Mario::getEnemiesDefeated(){  //method that gets the number of enemies Mario defeats
    return m_enemies_defeated; // returns m_enemies_defeated
}

bool Mario::fightGoomba(){ //method where Mario fights a Goomba
    
    srand(time(0)); //generates random number
    m_defeated = (rand() % 100 > 80); // 80% chance of defeating Goomba 

    if (m_defeated == true){ //Mario loses the fight
        if (power_level == 0){ //and if his power level is PL_0
            m_lives--; //decrease his number of lives by one
        }
        else{ //if his power level is not PL_0
            power_level--; //decrease his power level by one
        }
    }
    else{ //Mario wins the fight
        m_enemies_defeated++; //add number of enemies defeated by one
        if ((m_enemies_defeated % 7) == 0){ //if Mario defeats 7 enemies in one life
            m_lives++; //increase his number of lives by one
        }
    }  
    return m_defeated; //return boolean m_defeated
}

bool Mario::fightKoopa(){  //method where Mario fights a Koopa

    srand(time(0)); //generates random number
    m_defeated = (rand() % 100 > 65); // 65% chance of defeating Koopa 
    
    if (m_defeated == true){   // Mario loses the fight
        if (power_level == 0){ // and if his power level is PL_0
            m_lives--; // decrease his number of lives by one
        }
        else{ //if his power level is not PL_0
            power_level--; //decrease his power level by one
        }
    } 
    else{ //Mario wins the fight
        m_enemies_defeated++; //add number of enemies defeated by one
        if ((m_enemies_defeated % 7) == 0){ //if Mario defeats 7 enemies in one life
            m_lives++; //increase his number of lives by one
        }
    }
    return m_defeated; //return boolean m_defeated
}

bool Mario::fightBoss(){ //method where Mario fights a Boss
   
    srand(time(0)); //generates random number
    m_defeated = (rand() % 100 > 50); // 50% chance of defeating Boss 
    
    if (m_defeated == true){ //Mario loses the fight
        if (power_level == 0){ //and if his power level is PL_0
            m_lives -= 2; //decrease his number of lives by two
        }
        else{ //if his power level is not PL_0
            power_level--; //decrease his power level by one
        }
    } 
    else{//Mario wins the fight
        m_enemies_defeated++;//add number of enemies defeated by one
        if ((m_enemies_defeated % 7) == 0){//if Mario defeats 7 enemies in one life
            m_lives++;//increase his number of lives by one
        }
    }
    return m_defeated;//return boolean m_defeated
}
