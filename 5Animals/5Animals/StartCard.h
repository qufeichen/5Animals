//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#pragma once
#include <string>
#include <string>
#include <cstdlib>
#include <iostream>
#include "NoSplit.h"
#include "AnimalCard.h"

#ifndef STARTCARD_H
#define STARTCARD_H


class StartCard:public NoSplit{
    
private:
	Orientation orientation;
	EvenOdd evenOdd;
	EvenOdd next;
	char cardMatrix[2][2];
    
public:
	StartCard();
	void setOrientation(Orientation);
	void setRow(EvenOdd);
	EvenOdd getRow();
	void printRow( EvenOdd );

};

#endif