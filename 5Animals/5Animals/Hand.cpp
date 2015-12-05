//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include <memory>
#include <ostream>
#include "Hand.h"
#include <algorithm>
#include <vector>
using namespace std;

Hand::Hand(){
	numOfCards = 0;
}

Hand& Hand::operator+=(std::shared_ptr<AnimalCard> newCard){

	++numOfCards;
	cardsInHand.push_back(newCard);

	//call add
	return *this;
}


Hand& Hand::operator-=(std::shared_ptr<AnimalCard>newCard){
	try
    {
			--numOfCards;
			//remove if equal to newCard
			cardsInHand.remove(newCard);
	}
	catch (exception)
    {
		cout << "card does not exist" << "\n";
	}
	return *this;
}

std::shared_ptr<AnimalCard> Hand::operator[](int index){
	std::shared_ptr<AnimalCard> temp;
	try
    {
		if(index > numOfCards)
        {
            throw std::runtime_error("Missing Card");
		}
			--numOfCards;
			//get card if equal to index
			std::list<std::shared_ptr<AnimalCard>>::iterator it;
			std::advance(it, index);
			temp = *it;
	}
	catch (exception& e)
    {
		cout << "card does not exist in index" << "\n";
	}
	return temp;
	
}

int Hand::noCards(){
	return numOfCards;
}

ostream& operator <<(ostream &out, const Hand& handGiven){
    out << "Card in Hand" << endl;
    int count = 0;
    
	for(std::list<std::shared_ptr<AnimalCard>>::const_iterator i = handGiven.cardsInHand.begin(); i != handGiven.cardsInHand.end(); i++)
    {
		//prints number 
		
		//print Cards
		out<< *i;
	}

	return out;

}

