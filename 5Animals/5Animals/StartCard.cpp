//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include "StartCard.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

StartCard::StartCard(){
    
	for(int i = 0 ; i < 2; i++){
		for(int j = 0; j < 2; j++){

			cardMatrix[i][j] = 'c';
		}
	}
    
}

void StartCard::setOrientation(Orientation o){
    
	orientation = o;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j<2; j++){
			cardMatrix[i][j] = 'c';
		}
	}
    
}

void StartCard::setRow(EvenOdd eo){
    
	evenOdd = eo;
	if(eo == EVEN){
		next = ODD;
	}else if(eo == ODD){
		next = EVEN;
	}else{
		next = DEFAULT;
	}
    
}

EvenOdd StartCard::getRow(){
    
	return next;
    
}

void StartCard::printRow(EvenOdd eo){
    
    cout << cardMatrix[0][0];
    cout << cardMatrix[0][1];
    
}