//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include <string>
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <deque>
#include "StartStack.h"
#include "StartCard.h"

StartStack::StartStack(){
    
    std::shared_ptr<StartCard> newStart( new StartCard() );
    this->start = newStart;
    stack.push_back(start);
    topAnimal = 'c';

}

StartStack& StartStack::operator+=(std::shared_ptr<ActionCard> card){
    
    stack.push_back(card);
	return *this;
    //execute action elsewhere
    //no access to table
    
}

StartStack& StartStack::operator-=(std::shared_ptr<ActionCard> card){
    
	//bottom is front
	stack.push_front(card);
    topAnimal = card->getAnimal();
	return *this;
    //execute action elsewhere
    //no access to table
    
}

std::shared_ptr<StartCard> StartStack::getStartCard(){
    
	return start;
    
}

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
    
    stack.back()->printRow( eo );
    
}

void StartStack::printRow( ostream &, EvenOdd eo ){
    
     stack.back()->printRow( eo );
    
}

char StartStack::getAnimal(int, int){
    
    return topAnimal;
    
}

char StartStack::getTopAnimal(){
    
    return topAnimal;
    
}