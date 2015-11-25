// prime header file
//
#include <string>
#include <cstdlib>
#include <iostream>
#ifndef ANIMALCARD_H
#define ANIMALCARD_H

	enum EvenOdd
	{EVEN, ODD, DEFAULT

	};

	enum Orientation{
		UP,DOWN
	};


class AnimalCard{
private:

public:
	virtual void setOrientation(Orientation) = 0;
	virtual void setRow(EvenOdd) = 0;
	virtual int show() = 0;
	virtual EvenOdd getRow() = 0;
	virtual void printRow( EvenOdd );
	//virtual friend Idiom<<(obj const& lhs, obj const& rhs);

};

#endif