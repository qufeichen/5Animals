// prime header file
//
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
	//friend ostream & operator <<(ostream &out, const ThreeSplit&);

};

#endif