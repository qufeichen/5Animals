//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include <string>
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <deque>
#include "ActionCard.h"
#ifndef STARTSTACK_H
#define STARTSTACK_H


class StartStack:public AnimalCard{
    
private:
	std::deque<shared_ptr<StartCard>> stack;
    std::shared_ptr<StartCard> start;

	//values for the card on top
	Orientation orientation;
	EvenOdd evenOdd;
	EvenOdd next;
	char cardMatrix[2][2];

public:
	StartStack();
	StartStack& operator+=(std::shared_ptr<ActionCard>);
	StartStack& operator-=(std::shared_ptr<ActionCard>);
	std::shared_ptr<StartCard> getStartCard();
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	EvenOdd getRow();
	void printRow( EvenOdd );

	//Need to print object???
    
};

#endif