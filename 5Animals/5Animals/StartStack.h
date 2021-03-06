//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
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

	//values for card on top of stack
	Orientation orientation;
	EvenOdd evenOdd;
	EvenOdd next;
	char cardMatrix[2][2];
    char topAnimal;

public:
	StartStack();
	std::shared_ptr<StartCard> getStartCard();
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	EvenOdd getRow();
	void printRow( EvenOdd );
    char getAnimal(int, int);
    char getTopAnimal();
    void printRow( ostream &, EvenOdd );

    StartStack& operator+=(std::shared_ptr<ActionCard>);
    StartStack& operator-=(std::shared_ptr<ActionCard>);
    friend ostream & operator <<(ostream &out, const shared_ptr<StartStack>);
    friend istream & operator >>(istream &in, shared_ptr<StartStack>);
    
};

#endif