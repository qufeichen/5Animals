#include "NoSplit.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

NoSplit::NoSplit(){
	//instantiate card
	for(int i = 0; i < 2; i++){
		for(int j = 0; j<2; j++){
			cardMatrix[i][j] = 'c';
		}

	}

}
void NoSplit::setOrientation(Orientation o){
	orientation = o;
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
void NoSplit::printRow(EvenOdd eo){
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