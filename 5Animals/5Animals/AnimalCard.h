// prime header file
//
#include <string>
#include <string>
#include <cstdlib>
#include <iostream>
#ifndef ANIMALCARD_H
#define ANIMALCARD_H
using namespace std;

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
	virtual EvenOdd getRow() = 0;
	virtual void printRow( EvenOdd ) = 0;
	//virtual friend ostream & operator <<(ostream &out, const AnimalCard&) = 0;

};

#endif