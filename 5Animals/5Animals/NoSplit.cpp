//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "NoSplit.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;


NoSplit::NoSplit(char animal, Orientation o, EvenOdd e): orientation(o), evenOdd(e), split(1){
    
	for(int i = 0; i < 2; i++){
		for(int j = 0; j<2; j++){
			cardMatrix[i][j] = animal;
		}
	}
    
}


void NoSplit::setOrientation(Orientation o){
    
	orientation = o;
	//flip does not matter
    
}

void NoSplit::setRow(EvenOdd eo){
    
	evenOdd = eo;
	if(eo == EVEN){
		next = ODD;
	}else if(eo == ODD){
		next = EVEN;
	}else{
		next = DEFAULT;
	}
    
}

EvenOdd NoSplit::getRow(){
    
	return next;
    
}

//void NoSplit::printRow( EvenOdd eo){
//	if(eo == EVEN){
//		for(int i=0; i< 2; i++){
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
//}

void NoSplit::printRow(ostream& out, EvenOdd eo){
    
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

char NoSplit::getAnimal(int row, int col){
    
    return cardMatrix[row][col];
    
}

int NoSplit::getSplit(){
    
    return split;
    
}

//ostream &operator <<(ostream &out, const NoSplit& noSplitCard){
//	for(int i = 0; i < 2; i++){
//		for(int j = 0; j<2; j++){
//			out << noSplitCard.cardMatrix[i][j];
//			cout << "test!!";
//		}
//		cout << "\n";
//	}
//	return out;
//}