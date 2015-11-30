#include <string>
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
#include "StartStack.h"
#include <deque>

StartStack::StartStack(){
	stack.push_back(start);
}

//StartStack& StartStack::operator+=(std::shared_ptr<ActionCard> card){
//	//top is back
//	stack.push_back(card);
//	//change animal behaviour
//
//}
//StartStack& StartStack::operator-=(std::shared_ptr<ActionCard> card){
//	//bottom is front
//	stack.push_front(card);
//	//change animal behaviours
//}
//std::shared_ptr<ActionCard> getStartCard(){
//	//which is start card
//}

void StartStack::setOrientation(Orientation o){
	orientation = o;
}

void StartStack::setRow(EvenOdd eo){
	evenOdd = eo;
	if(eo == EVEN){
		next = ODD;
	}else if(eo == ODD){
		next = EVEN;
	}else{
		next = DEFAULT;
	}
}

EvenOdd StartStack::getRow(){
	return next;
}
void StartStack::printRow(EvenOdd eo){
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