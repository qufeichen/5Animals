//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
#include "StartCard.h"
#include "StartStack.h"
#include "Player.h"

class AnimalCard;
class ActionCard;

#ifndef INC_5ANIMALS_TABLE_H
#define INC_5ANIMALS_TABLE_H


class Table{
    
private:
	//array of pointers to animal cards, and array to track which positions are taken
	std::shared_ptr<AnimalCard> tableArray[103][103] ;
    int occupied[103][103];
	
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
    int d_maxNumPlayers;
    vector<Player> players;
    int currentNumPlayers;
    int *secretCardIndex;
//    //TODO:for printing table (keep track of size of table)
    int upperLeftRow;
    int upperLeftCol;
    int lowerRightRow;
    int lowerRightCol;
    
    //methods to update animal count
    void addToAnimalCount(std::shared_ptr<AnimalCard>);
    void removeFromAnimalCount(std::shared_ptr<AnimalCard>);

public:
	Table(int);
    
	int addAt(std::shared_ptr<AnimalCard>, int, int);
    int checkNeighbours(shared_ptr<AnimalCard>, int, int);
    std::shared_ptr<AnimalCard>pickAt(int, int );
    bool win(std::string& animal);
    
	int getNumPlayers();
	Player *getPlayer(string); //gets player by name
	Player *getPlayer(int); //gets player by index (in array)
	string createPlayer(string); //creates player
    void print();

    Table& operator+=(std::shared_ptr<ActionCard>);
    Table& operator-=(std::shared_ptr<ActionCard>);
    friend ostream & operator <<(ostream& , const Table&);
    friend istream & operator >>(istream& , Table&);
    
};

#endif