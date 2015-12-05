//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include <string>
#include "Hand.h"
#include "Player.h"
#include "Table.h"


using namespace std;

#ifndef INC_5ANIMALS_GAME_H
#define INC_5ANIMALS_GAME_H

class Game {
    
private:
	int d_numPlayers;

public:
	Game(int);
    Table *table;
    
};


#endif //INC_5ANIMALS_GAME_H