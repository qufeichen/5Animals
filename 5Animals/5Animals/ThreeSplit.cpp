#include "ThreeSplit.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

//creation of classes supposed to be done in AnimalFactory
/*
ThreeSplit::ThreeSplit(int model){
	//20	
	//b d h m w
	if(model == 16){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'd';
		cardMatrix[1][1] = 'h';
	}else if(model == 17){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'd';
		cardMatrix[1][1] = 'm';
	}else if(model == 18){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'd';
		cardMatrix[1][1] = 'w';
	}else if(model== 19){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'h';
		cardMatrix[1][1] = 'm';
	}else if(model == 20){
		cardMatrix[0][0] = 'b';
		cardMatrix[0][1] = 'b';
		cardMatrix[1][0] = 'h';
		cardMatrix[1][1] = 'w';
	}else if(model == 21){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'd';
		cardMatrix[1][0] = 'b';
		cardMatrix[1][1] = 'h';
	}else if(model == 22){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'd';
		cardMatrix[1][0] = 'b';
		cardMatrix[1][1] = 'w';
	}else if(model == 23){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'd';
		cardMatrix[1][0] = 'b';
		cardMatrix[1][1] = 'n';
	}else if(model == 24){
		cardMatrix[0][0] = 'd';
		cardMatrix[0][1] = 'd';
		cardMatrix[1][0] = 'b';
		cardMatrix[1][1] = 'w';
	}else if(model == 25){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'h';
		cardMatrix[1][0] = 'b';
		cardMatrix[1][1] = 'm';
	}	if(model == 26){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'h';
		cardMatrix[1][0] = 'b';
		cardMatrix[1][1] = 'd';
	}else if(model == 27){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'd';
		cardMatrix[1][0] = 'b';
		cardMatrix[1][1] = 'w';
	}else if(model == 28){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'h';
		cardMatrix[1][0] = 'b';
		cardMatrix[1][1] = 'd';
	}else if(model== 29){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'h';
		cardMatrix[1][0] = 'b';
		cardMatrix[1][1] = 'm';
	}else if(model == 30){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'h';
		cardMatrix[1][0] = 'b';
		cardMatrix[1][1] = 'w';
	}else if(model == 31){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'h';
		cardMatrix[1][0] = 'd';
		cardMatrix[1][1] = 'm';
	}else if(model == 32){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'h';
		cardMatrix[1][0] = 'd';
		cardMatrix[1][1] = 'w';
	}else if(model == 33){
		cardMatrix[0][0] = 'h';
		cardMatrix[0][1] = 'h';
		cardMatrix[1][0] = 'm';
		cardMatrix[1][1] = 'w';
	}else if(model == 34){
		cardMatrix[0][0] = 'm';
		cardMatrix[0][1] = 'm';
		cardMatrix[1][0] = 'b';
		cardMatrix[1][1] = 'w';
	}else if(model == 35){
		cardMatrix[0][0] = 'm';
		cardMatrix[0][1] = 'm';
		cardMatrix[1][0] = 'd';
		cardMatrix[1][1] = 'w';
	}
		
}
 */

ThreeSplit::ThreeSplit(char a[2][2], Orientation o, EvenOdd e): orientation(o), evenOdd(e){
    for (int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cardMatrix[i][j] = a[i][j];
        }
    }
}


void ThreeSplit::setOrientation(Orientation o){
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

void ThreeSplit::printRow(ostream& out, EvenOdd eo){
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
//void ThreeSplit::printRow(EvenOdd eo){
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
//ostream &operator <<(ostream &out, const ThreeSplit& splitCard){
//	for(int i = 0; i < 2; i++){
//		for(int j = 0; j<2; j++){
//			out << splitCard.cardMatrix[i][j];
//			cout << "test!!";
//		}
//		cout << "\n";
//	}
//	return out;
//}
