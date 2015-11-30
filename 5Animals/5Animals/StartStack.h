//
// 
//

#include <string>
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <deque>
#include "ActionCard.h"
#ifndef STARTSTACK_H
#define STARTSTACK_H
class StartStack:AnimalCard{
public:
	std::deque<shared_ptr<StartCard>> stack;
	std::shared_ptr<StartCard> start;

	//values for the card on top
	Orientation orientation;
	EvenOdd evenOdd;
	EvenOdd next;
	char cardMatrix[2][2];
private:
	StartStack();
	StartStack& operator+=(std::shared_ptr<ActionCard>);
	StartStack& operator-=(std::shared_ptr<ActionCard>);
	std::shared_ptr<ActionCard> getStartCard();
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	EvenOdd getRow();
	void printRow( EvenOdd );

	//Need to print object???
};

#endif