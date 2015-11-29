// prime header file
//
#pragma once
#include <string>
#include <string>
#include <cstdlib>
#include <iostream>
#include "NoSplit.h"

#ifndef STARTCARD_H
#define STARTCARD_H


class StartCard:public NoSplit{
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