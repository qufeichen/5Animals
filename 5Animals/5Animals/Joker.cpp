//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
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
			cardMatrix[i][j] = 'j';
		}
	}
    
    j='j';
    setOrientation(Orientation::UP);
    setRow(EvenOdd::EVEN);
    
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

void Joker::printRow(EvenOdd e){
    
    if(e == EVEN){
        cout << j;
        cout << j;
    }
    else if(e == ODD){
        cout<< j;
        cout<< j;
    }
    
}
