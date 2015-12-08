//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "AnimalCard.h"
#ifndef TWOSPLIT_H
#define TWOSPLIT_H
#include <string>
#include <cstdlib>
#include <iostream>


class TwoSplit:public AnimalCard{
    
private:
	Orientation orientation;
	EvenOdd evenOdd;
	EvenOdd next;
	char cardMatrix[2][2];
    char topLeft, topRight, bottomLeft, bottomRight;
    
public:
    TwoSplit(char[2][2], Orientation o, EvenOdd e);
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	EvenOdd getRow();
	void printRow(ostream&, EvenOdd);
    void printRow( EvenOdd);
    char getAnimal(int, int);
};

#endif