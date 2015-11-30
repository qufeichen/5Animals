#include "Deck.h"
#include <string>
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>

std::shared_ptr<AnimalCard> Deck<AnimalCard>::draw(){
	 shared_ptr<AnimalCard> temp;
	 //pop last element and return it
		temp = this->back();
		return temp;

}