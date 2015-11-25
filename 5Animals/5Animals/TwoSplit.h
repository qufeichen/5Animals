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

public:
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	int show();
	EvenOdd getRow();
	void printRow( EvenOdd );
	//virtual friend Idiom<<(obj const& lhs, obj const& rhs);

};

#endif