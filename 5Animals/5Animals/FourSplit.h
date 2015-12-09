//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include "AnimalCard.h"
#include <string>
#include <cstdlib>
#include <iostream>

#ifndef FOURSPLIT_H
#define FOURSPLIT_H


class FourSplit:public AnimalCard{
    
private:
	Orientation orientation;
	EvenOdd evenOdd;
	EvenOdd next;
	char cardMatrix[2][2];
    char topLeft, topRight, bottomLeft, bottomRight;

public:
    int type;
    FourSplit( char[2][2], Orientation, EvenOdd);
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	EvenOdd getRow();
	void printRow( ostream&, EvenOdd );
    void printRow( EvenOdd);
    char getAnimal(int, int);
    
};

#endif