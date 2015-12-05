//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "Joker.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;
NoSplit::NoSplit(){

}

Joker::Joker(){
    
	for(int i = 0 ; i < 2; i++){
		for(int j = 0; j < 2; j++){
			cardMatrix[i][j] = 'c';
		}
	}
    
}

void Joker::setOrientation(Orientation o){

	orientation = o;
    
}

void Joker::setRow(EvenOdd eo){
    
	evenOdd = eo;
	if(eo == EVEN){
		next = ODD;
	}else if(eo == ODD){
		next = EVEN;
	}else{
		next = DEFAULT;
	}
    
}

EvenOdd Joker::getRow(){
    
	return next;
    
}

void Joker::printRow( EvenOdd eo){
    
	if(eo == EVEN){
		for(int i=0; i< 2; i++){

			cout << cardMatrix[0][i] << "first row" << endl;	
		}
	}
	else if(eo == ODD){
		for(int i=0; i< 2; i++){
			cout<< cardMatrix[1][i] << "second row"  << endl;	
		}
	}else{
		for(int i=0; i< 2; i++){
			cout<< cardMatrix[0][i] << "default" << endl;	

		}
	}

}
