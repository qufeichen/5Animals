// Allows for global access of variables
// creates the game
//

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
	Table *table;

public:
	Game(int);
	Player getPlayer(string);
};


#endif //INC_5ANIMALS_GAME_H