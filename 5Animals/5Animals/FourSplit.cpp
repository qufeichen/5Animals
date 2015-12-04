#include "FourSplit.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

//creation of cards is supposed to be done in AnimalFactory
/*
FourSplit::FourSplit(int model){
	//15
if(model == 136){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'd';
		cardMatrix[1][0] = 'h';
		cardMatrix[1][1] = 'm';
	}else if(model == 37){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'd';
		cardMatrix[1][0] = 'm';
		cardMatrix[1][1] = 'w';
	}else if(model == 38){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'd';
		cardMatrix[1][0] = 'h';
		cardMatrix[1][1] = 'w';
	}else if(model== 39){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'h';
		cardMatrix[1][0] = 'm';
		cardMatrix[1][1] = 'w';
	}else if(model == 40){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'h';
		cardMatrix[1][1] = 'w';
	}else if(model == 41){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'h';
		cardMatrix[1][0] = 'm';
		cardMatrix[1][1] = 'w';
	}else if(model == 42){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'm';
		cardMatrix[1][1] = 'w';
	}else if(model == 43){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'm';
		cardMatrix[1][1] = 'w';
	}else if(model == 44){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'h';
		cardMatrix[1][1] = 'w';
	}else if(model == 45){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'h';
		cardMatrix[1][1] = 'm';
	}	if(model == 46){
		//b d h m w
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'd';
		cardMatrix[1][1] = 'm';
	}else if(model == 47){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'd';
		cardMatrix[1][1] = 'w';
	}else if(model == 48){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'm';
		cardMatrix[1][1] = 'w';
	}else if(model== 49){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'd';
		cardMatrix[1][0] = 'm';
		cardMatrix[1][1] = 'w';
		//b d h m w
	}else if(model == 50){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'd';
		cardMatrix[1][1] = 'w';
	}
		
}
 */


FourSplit::FourSplit(char a[2][2], Orientation o, EvenOdd e): orientation(o), evenOdd(e) {
    
    for (int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cardMatrix[i][j] = a[i][j];
        }
    }
    
}



void FourSplit::setOrientation(Orientation o){
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

void FourSplit::setRow(EvenOdd eo){
	evenOdd = eo;
	if(eo == EVEN){
		next = ODD;
	}else if(eo == ODD){
		next = EVEN;
	}else{
		next = DEFAULT;
	}
}

EvenOdd FourSplit::getRow(){
	return next;
}
//void FourSplit::printRow(EvenOdd eo){
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
//ostream &operator <<(ostream &out, const FourSplit& splitCard){
//	for(int i = 0; i < 2; i++){
//		for(int j = 0; j<2; j++){
//			out << splitCard.cardMatrix[i][j];
//			cout << "test!!";
//		}
//		cout << "\n";
//	}
//	return out;
//}

void FourSplit::printRow(ostream& out, EvenOdd eo){
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