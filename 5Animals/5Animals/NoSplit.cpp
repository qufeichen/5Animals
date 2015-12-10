//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include "NoSplit.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;


NoSplit::NoSplit(char animal, Orientation o, EvenOdd e): type(1){
    
	for(int i = 0; i < 2; i++){
		for(int j = 0; j<2; j++){
			cardMatrix[i][j] = animal;
		}
	}
    
    setOrientation(o);
    setRow(e);
    
}


void NoSplit::setOrientation(Orientation o){
    
	orientation = o;
    
    //flip does not matter
    animal = cardMatrix[0][0];
    
}

void NoSplit::setRow(EvenOdd eo){
    
    //orientation does not matter for NoSplit cards
	evenOdd = eo;
    
}

EvenOdd NoSplit::getRow(){
    
    //all elements of cardMatrix are the same
	return next;
    
}

void NoSplit::printRow(ostream& out, EvenOdd eo){
    
    out << animal;
    out << animal;
    
}

void NoSplit::printRow(EvenOdd e){
    
    cout << animal;
    cout << animal;
    
}

char NoSplit::getAnimal(int row, int col){
    
    return cardMatrix[row][col];
    
}
