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