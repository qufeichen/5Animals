//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "AnimalCard.h"
#ifndef THREESPLIT_H
#define THREESPLIT_H
#include <string>
#include <cstdlib>
#include <iostream>


class ThreeSplit:public AnimalCard{
    
private:
	Orientation orientation;
	EvenOdd evenOdd;
	EvenOdd next;
	char cardMatrix[2][2];
    
public:
    ThreeSplit(char[2][2], Orientation o, EvenOdd e);
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	EvenOdd getRow();
	void printRow( ostream&, EvenOdd );
    char getAnimal(int, int);
	//friend ostream & operator <<(ostream &out, const ThreeSplit&);

};

#endif