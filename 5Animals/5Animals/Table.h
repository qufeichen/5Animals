//
// Created by Qufei Chen on 2015-11-24.
//
#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
class AnimalCard;
class ActionCard;
#include "StartCard.h"
#include "StartStack.h"
//#include "AnimalCard.h"
//#include "ActionCard.h"

#ifndef INC_5ANIMALS_TABLE_H
#define INC_5ANIMALS_TABLE_H

class Table{
    
private:
	//4 pointed graph
	std::shared_ptr<AnimalCard> tableArray[103][103] ;
	
	//stack in middle of graph
	std::shared_ptr<StartStack> stack;

	//Number of Each Animal card
	int bearCount;	
	int deerCount;
	int hareCount;
	int mooseCount;
	int wolfCount;

    //Create 4 players (or however many are playing)
    //players
    int d_numPlayers;
    vector<Player> players;
    static int currentNumPlayers;
    int *secretCardIndex;

public:
	Table(const int);
	int addAt(std::shared_ptr<AnimalCard>, int row, int col);
	Table& operator+=(std::shared_ptr<ActionCard>);
	Table& operator-=(std::shared_ptr<ActionCard>);
	std::shared_ptr<AnimalCard>pickAt(int row, int col);
	bool win(std::string& animal);
	friend ostream & operator <<(ostream& , const Table&);
	int getNumPlayers();
	Player *getPlayer(string); //gets player by name
	Player *getPlayer(int); //gets player by index (in array)
	string createPlayer(string); //creates player
	void animalCount(std::shared_ptr<AnimalCard>); //count number of animal and incremenents
    
};

#endif //INC_5ANIMALS_TABLE_H