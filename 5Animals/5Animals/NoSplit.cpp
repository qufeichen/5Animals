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


NoSplit::NoSplit(char animal, Orientation o, EvenOdd e){
    
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
    animal = cardMatrix[0][0];
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

void NoSplit::printRow(EvenOdd e){
    
        cout << animal;
        cout << animal;
    
}

char NoSplit::getAnimal(int row, int col){
    
    return cardMatrix[row][col];
    
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