// prime header file
//
#include "AnimalCard.h"
#ifndef ONESPLIT_H
#define ONESPLIT_H
#include <string>
#include <cstdlib>
#include <iostream>

class OneSplit:public AnimalCard{
private:
	Orientation orientation;
	EvenOdd evenOdd;
	EvenOdd next;
	char cardMatrix[2][2];
public:
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	int show();
	EvenOdd getRow();
	void printRow( EvenOdd );
	friend ostream & operator <<(ostream &out, const OneSplit&);

};

#endif