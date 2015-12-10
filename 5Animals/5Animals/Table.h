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
	//array of pointers to animal cards
    std::shared_ptr<AnimalCard> tableArray[103][103] ;
    //array that records which positions on table are occupied
    int occupied[103][103];
	
    //startstack
	std::shared_ptr<StartStack> stack;

	//Count of each animal card on table
	int bearCount;	
	int deerCount;
	int hareCount;
	int mooseCount;
	int wolfCount;

    //players
    int d_maxNumPlayers;
    vector<Player> players;
    int currentNumPlayers;
    
    //used to assign secret animals to players
    int *secretCardIndex;

    //variables to keep track of table size
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
    
    //player methods
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