#include "TwoSplit.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

//creation of cards supposed to be done in AnimalFactor
/*
TwoSplit::TwoSplit(int model){
	//10
	//b d h m w
	if(model == 6){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'd';
		cardMatrix[1][1] = 'd';
	}else if(model == 7){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'd';
		cardMatrix[1][1] = 'd';
	}else if(model == 8){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'h';
		cardMatrix[1][1] = 'h';
	}else if(model== 9){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'm';
		cardMatrix[1][1] = 'm';
	}else if(model == 10){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'w';
		cardMatrix[1][1] = 'w';
	}else if(model == 11){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'h';
		cardMatrix[1][0] = 'm';
		cardMatrix[1][1] = 'm';
	}else if(model == 12){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'd';
		cardMatrix[1][0] = 'h';
		cardMatrix[1][1] = 'h';
	}else if(model == 13){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'd';
		cardMatrix[1][0] = 'm';
		cardMatrix[1][1] = 'm';
	}else if(model == 14){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'd';
		cardMatrix[1][0] = 'w';
		cardMatrix[1][1] = 'w';
	}else if(model == 15){
		cardMatrix[0][0] = 'm';
		cardMatrix[0][1] = 'm';
		cardMatrix[1][0] = 'w';
		cardMatrix[1][1] = 'w';
	}

}
 */

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
//}
//
//
//ostream &operator <<(ostream &out, const TwoSplit& splitCard){
//	for(int i = 0; i < 2; i++){
//		for(int j = 0; j<2; j++){
//			out << splitCard.cardMatrix[i][j];
//			cout << "test!!";
//		}
//		cout << "\n";
//	}
//	return out;
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