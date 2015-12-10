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

char StartStack::getAnimal(int x, int y){
    
    return topAnimal;
    
}

char StartStack::getTopAnimal(){
    
    return topAnimal;
    
}

StartStack& StartStack::operator+=(std::shared_ptr<ActionCard> card){
    
    //top of stack is back
    stack.push_back(card);
    return *this;
    
}

StartStack& StartStack::operator-=(std::shared_ptr<ActionCard> card){
    
    //bottom of stack is front
    stack.push_front(card);
    topAnimal = card->getAnimal();
    return *this;
    
}

ostream & operator <<(ostream &out, const shared_ptr<StartStack> stack){
    
    //writes stack to file
    //only need record the animal on top of the startstack
    out << stack->topAnimal;
    out << stack->cardMatrix[0][0];
    out << stack->cardMatrix[0][1];
    out << stack->cardMatrix[1][0];
    out << stack->cardMatrix[1][1];
    
    return out;
    
}

istream & operator >>(istream &in, shared_ptr<StartStack> stack){
    
    //retrieves startstack info from file
    in >> stack->topAnimal;
    in >> stack->cardMatrix[0][0];
    in >> stack->cardMatrix[0][1];
    in >> stack->cardMatrix[1][0];
    in >> stack->cardMatrix[1][1];
    
    return in;
    
}