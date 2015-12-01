// prime header file
//
#include "AnimalCard.h"
#ifndef NOSPLIT_H
#define NOSPLIT_H
#include <string>
#include <cstdlib>
#include <iostream>

class NoSplit:public AnimalCard{
private:
	Orientation orientation;
	EvenOdd evenOdd;
	EvenOdd next;
	char cardMatrix[2][2];
public:
	NoSplit(char);
	NoSplit();
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	EvenOdd getRow();
	void printRow( ostream&, EvenOdd );
	//friend ostream & operator <<(ostream &out, const NoSplit&);

};

#endif