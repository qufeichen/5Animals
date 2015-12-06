//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "TwoSplit.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

TwoSplit::TwoSplit(char a[2][2], Orientation o, EvenOdd e): orientation(o), evenOdd(e){
    
    for (int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cardMatrix[i][j] = a[i][j];
        }
    }
    
}


void TwoSplit::setOrientation(Orientation o){
    
	orientation = o;
	//Temp variables
	char topLeft, topRight, bottomLeft, bottomRight;
	topLeft = cardMatrix[0][0];
	topRight = cardMatrix[0][1];
	bottomLeft = cardMatrix[1][0];
	bottomRight = cardMatrix[1][1];
	//Flip orientation
	cardMatrix[0][0] = bottomRight;
	cardMatrix[0][1] = bottomLeft;
	cardMatrix[1][0] = topRight;
	cardMatrix[1][1] = topLeft;
    
}

void TwoSplit::setRow(EvenOdd eo){
    
	evenOdd = eo;
	if(eo == EVEN){
		next = ODD;
	}else if(eo == ODD){
		next = EVEN;
	}else{
		next = DEFAULT;
	}
    
}

EvenOdd TwoSplit::getRow(){
    
	return next;
    
}

//void TwoSplit::printRow(EvenOdd eo){
//
//	if(eo == EVEN){
//		for(int i=0; i< 2; i++){
//
//			cout << cardMatrix[0][i] << "first row" << endl;	
//		}
//	}
//	else if(eo == ODD){
//		for(int i=0; i< 2; i++){
//			cout<< cardMatrix[1][i] << "second row"  << endl;	
//		}
//	}else{
//		for(int i=0; i< 2; i++){
//			cout<< cardMatrix[0][i] << "default" << endl;	
//
//		}
//	}
//
//}
//
//
//ostream &operator <<(ostream &out, const TwoSplit& splitCard){
//
//	for(int i = 0; i < 2; i++){
//		for(int j = 0; j<2; j++){
//			out << splitCard.cardMatrix[i][j];
//			cout << "test!!";
//		}
//		cout << "\n";
//	}
//	return out;
//
//}

void TwoSplit::printRow(ostream& out, EvenOdd eo){
    
	if(eo == EVEN){
		for(int i=0; i< 2; i++){	
			out << cardMatrix[0][i] << "first row";	
		}
	}
	else if(eo == ODD){
		for(int i=0; i< 2; i++){	
			out << cardMatrix[1][i] << "second row";	
		}
	}else{
		for(int i=0; i< 2; i++){	
			out<< cardMatrix[0][i] << "default";
		}
	}
	cout <<"\n";
    
}

char TwoSplit::getAnimal(int row, int col){
    
    return cardMatrix[row][col];
    
}
