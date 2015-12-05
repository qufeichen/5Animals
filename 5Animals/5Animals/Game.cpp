//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "Game.h"
#include "Player.h"
#include "Hand.h"
#include <string>

using namespace std;

Game::Game(int numPlayers): d_numPlayers(numPlayers){
    table = new Table(numPlayers);
}


