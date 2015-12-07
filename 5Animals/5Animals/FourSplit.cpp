//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "FourSplit.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

FourSplit::FourSplit(char a[2][2], Orientation o, EvenOdd e){
    
    for (int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            cardMatrix[i][j] = a[i][j];
        }
    }
 
    setOrientation(o);
    setRow(e);
}

void FourSplit::setOrientation(Orientation o){
    
    orientation = o;
    if(o == UP){
        topLeft = cardMatrix[0][0];
        topRight = cardMatrix[0][1];
        bottomLeft = cardMatrix[1][0];
        bottomRight = cardMatrix[1][1];
        setRow(EvenOdd::EVEN);
    }
    //Flip orientation
    else {
        bottomRight = cardMatrix[0][0];
        bottomLeft = cardMatrix[0][1];
        topRight = cardMatrix[1][0];
        topLeft = cardMatrix[1][1];
        setRow(EvenOdd::ODD);
    }
    
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
//
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
//
//}
//
//ostream &operator <<(ostream &out, const FourSplit& splitCard){
//
//	for(int i = 0; i < 2; i++){
//		for(int j = 0; j<2; j++){
//			out << splitCard.cardMatrix[i][j];
//			cout << "test!!";
//		}
//		cout << "\n";
//	}
//	return out;
//
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

void FourSplit::printRow(EvenOdd e){
    
    if(e == EVEN){
        cout << topLeft;
        cout << topRight;
    }
    else if(e == ODD){
        cout << bottomLeft;
        cout << bottomRight;
    }
    
}

char FourSplit::getAnimal(int row, int col){
    
    return cardMatrix[row][col];
    
}
