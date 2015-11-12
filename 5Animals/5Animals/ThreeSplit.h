// prime header file
//
#include "AnimalCard.h"
#ifndef THREESPLIT_H
#define THREESPLIT_H
#include <string>
#include <cstdlib>
#include <iostream>

class ThreeSpilt:public AnimalCard{
private:

public:
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	int show();
	EvenOdd getRow();
	void printRow( EvenOdd );
	//virtual friend Idiom<<(obj const& lhs, obj const& rhs);

};

#endif