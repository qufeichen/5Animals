#include "Joker.h"
#include <string>
#include <cstdlib>
#include <iostream>



void Joker::setOrientation(Orientation o){
	if(o == DOWN){
		orientation = DOWN;
	}
	else{
		orientation = UP;
	}
}
void Joker::setRow(EvenOdd eo){
	evenOdd = eo;
}
int Joker::show(){

	return 1;
}
EvenOdd Joker::getRow(){
}
void Joker::printRow( EvenOdd eo){
}
