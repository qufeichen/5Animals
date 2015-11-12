// prime header file
//
#include <string>
#ifndef STARTCARD_H
#define STARTCARD_H
#include <string>
#include <cstdlib>
#include <iostream>
#include "AnimalCard.h"


class StartCard:public AnimalCard{
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