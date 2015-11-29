//
// Created by Qufei Chen on 2015-11-24.
//
#pragma once
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
class AnimalCard;
class ActionCard;
//#include "AnimalCard.h"
//#include "ActionCard.h"

#ifndef INC_5ANIMALS_TABLE_H
#define INC_5ANIMALS_TABLE_H

class Table{
private:
	std::shared_ptr<AnimalCard> tableArray[103][103];
	//4 pointed graph
	StartCard firstCard;

public:
	Table();
	int addAt(std::shared_ptr<AnimalCard>, int row, int col);
	Table& operator+=(std::shared_ptr<ActionCard>);
	Table& operator-=(std::shared_ptr<ActionCard>);
	std::shared_ptr<AnimalCard>pickAt(int row, int col);
	bool win(std::string& animal);




};

#endif //INC_5ANIMALS_TABLE_H