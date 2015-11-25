// prime header file
//
#include "NoSplit.h"
#ifndef JOKER_H
#define JOKER_H
#include <string>
#include <cstdlib>
#include <iostream>

class Joker:public NoSplit{
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
	//virtual friend Idiom<<(obj const& lhs, obj const& rhs);

};

#endif