
#include "Game.h"
#include "Player.h"
#include "Hand.h"
#include <string>

using namespace std;

Game::Game(int numPlayers): d_numPlayers(numPlayers){
    table = new Table(numPlayers);
}


