// prime header file
//
#include "AnimalCard.h"
#ifndef FOURSPLIT_H
#define FOURSPLIT_H
#include <string>
#include <cstdlib>
#include <iostream>

class FourSplit:public AnimalCard{
    
private:
	Orientation orientation;
	EvenOdd evenOdd;
	EvenOdd next;
	char cardMatrix[2][2];

public:
	//FourSplit(int);
    FourSplit( char[2][2], Orientation, EvenOdd);
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	EvenOdd getRow();
	void printRow(ostream&, EvenOdd );
	//friend ostream & operator <<(ostream &out, const FourSplit&);

    
    
};

#endif