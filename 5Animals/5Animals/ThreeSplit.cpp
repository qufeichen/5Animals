#include "ThreeSplit.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

void ThreeSplit::setOrientation(Orientation o){
	orientation = o;
}
void ThreeSplit::setRow(EvenOdd eo){
	evenOdd = eo;
	if(eo == EVEN){
		next = ODD;
	}else if(eo == ODD){
		next = EVEN;
	}else{
		next = DEFAULT;
	}
}

EvenOdd ThreeSplit::getRow(){
	return next;
}
void ThreeSplit::printRow(EvenOdd eo){
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


ostream &operator <<(ostream &out, const ThreeSplit& splitCard){
	for(int i = 0; i < 2; i++){
		for(int j = 0; j<2; j++){
			out << splitCard.cardMatrix[i][j];
			cout << "test!!";
		}
		cout << "\n";
	}
	return out;
}