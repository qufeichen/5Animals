// prime header file
//
#include "AnimalCard.h"
#ifndef JOKER_H
#define JOKER_H
#include <string>
#include <cstdlib>
#include <iostream>

class Joker:public AnimalCard{
private:
	Orientation orientation;
	EvenOdd evenOdd;
public:
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	int show();
	EvenOdd getRow();
	void printRow( EvenOdd );
	//virtual friend Idiom<<(obj const& lhs, obj const& rhs);

};

#endif