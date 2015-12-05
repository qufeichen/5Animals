//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "AnimalCard.h"
#include <string>
#include <cstdlib>
#include <iostream>

#ifndef FOURSPLIT_H
#define FOURSPLIT_H


class FourSplit:public AnimalCard{
    
private:
	Orientation orientation;
	EvenOdd evenOdd;
	EvenOdd next;
	char cardMatrix[2][2];

public:
    FourSplit( char[2][2], Orientation, EvenOdd);
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	EvenOdd getRow();
	void printRow(ostream&, EvenOdd );
	//friend ostream & operator <<(ostream &out, const FourSplit&);
    
};

#endif