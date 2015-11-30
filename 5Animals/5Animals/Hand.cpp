
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
	return *this;
}


Hand& Hand::operator-=(std::shared_ptr<AnimalCard>newCard){
	try{
			--numOfCards;
			//remove if equal to newCard
			cardsInHand.remove(newCard);
	}
	catch (exception){
		cout << "card does not exist" << "\n";
	}
	return *this;
}

std::shared_ptr<AnimalCard> Hand::operator[](int index){
	std::shared_ptr<AnimalCard> temp;
	try{
			--numOfCards;
			//get card if equal to index
			std::list<std::shared_ptr<AnimalCard>>::iterator it;
			std::advance(it, index);
			temp = *it;
	}
	catch (exception){
		cout << "card does not exist in index" << "\n";
	}
	return temp;
	
}

int Hand::noCards(){
	return numOfCards;
}

ostream& operator <<(ostream &out, const Hand& handGiven){
		
	for( int i = 0; i<handGiven.numOfCards; i++){
		//cout<<
	}


	//std::for_each(handGiven.cardsInHand.begin(),handGiven.cardsInHand.end());
		//number
	return out;

}

