//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
///Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

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
    char j;
    
public:
    int type;
	Joker();
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	int show();
	EvenOdd getRow();
	void printRow( EvenOdd );

};

#endif