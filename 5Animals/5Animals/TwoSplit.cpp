//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include "TwoSplit.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

TwoSplit::TwoSplit(char a[2][2], Orientation o, EvenOdd e): type(2){
    
    for (int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cardMatrix[i][j] = a[i][j];
        }
    }
    
    setOrientation(o);
    setRow(e);
    
}


void TwoSplit::setOrientation(Orientation o){
    
    orientation = o;
    
    if (o == UP){
        topLeft = cardMatrix[0][0];
        topRight = cardMatrix[0][1];
        bottomLeft = cardMatrix[1][0];
        bottomRight = cardMatrix[1][1];
        setRow(EvenOdd::EVEN);
    } else {
        bottomRight = cardMatrix[0][0];
        bottomLeft = cardMatrix[0][1];
        topRight = cardMatrix[1][0];
        topLeft = cardMatrix[1][1];
        setRow(EvenOdd::ODD);
    }
    
}

void TwoSplit::setRow(EvenOdd eo){
    
	evenOdd = eo;
    
	if(eo == EVEN){
		next = ODD;
	} else if (eo == ODD){
		next = EVEN;
	} else {
		next = DEFAULT;
	}
    
}

EvenOdd TwoSplit::getRow(){
    
	return next;
    
}

void TwoSplit::printRow(ostream& out, EvenOdd eo){
    
    if (eo == EVEN){
        cout << topLeft;
        cout << topRight;
    } else if (eo == ODD){
        cout << bottomLeft;
        cout << bottomRight;
    }
    
}

void TwoSplit::printRow(EvenOdd e){
    
    if(e == EVEN){
        cout << topLeft;
        cout << topRight;
    } else if (e == ODD){
        cout << bottomLeft;
        cout << bottomRight;
    }
    
}

char TwoSplit::getAnimal(int row, int col){
    
    return cardMatrix[row][col];
    
}
