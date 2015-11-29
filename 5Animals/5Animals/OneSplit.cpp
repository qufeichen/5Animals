#include "OneSplit.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

void OneSplit::setOrientation(Orientation o){
	orientation = o;
}
void OneSplit::setRow(EvenOdd eo){
	evenOdd = eo;
	if(eo == EVEN){
		next = ODD;
	}else if(eo == ODD){
		next = EVEN;
	}else{
		next = DEFAULT;
	}
}

EvenOdd OneSplit::getRow(){
	return next;
}
void OneSplit::printRow(EvenOdd eo){
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

ostream &operator <<(ostream &out, const NoSplit& noSplitCard){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j<2; j++){
			out << noSplitCard.cardMatrix[i][j];
			cout << "test!!";
		}
		cout << "\n";
	}
	return out;
}