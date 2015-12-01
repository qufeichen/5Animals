// prime header file
//
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
public:
	TwoSplit(int);
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	EvenOdd getRow();
	void printRow(ostream&, EvenOdd );
	//friend ostream & operator <<(ostream &out, const TwoSplit&);

};

#endif