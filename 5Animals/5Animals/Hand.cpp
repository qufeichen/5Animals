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
    
    out<<handGiven.numOfCards;
    list<shared_ptr<AnimalCard>>::const_iterator it;
    for(it = handGiven.cardsInHand.begin(); it != handGiven.cardsInHand.end(); it++){
        out<<(*it);
    }

	return out;

}

void Hand::print(){
    
    //print index
    for (int i = 0; i<numOfCards; i++){
        cout<<i<<"   ";
    }
    cout<<endl;
    
    //print cards in hand -> use an iterator
    list<shared_ptr<AnimalCard>>::iterator it;
    
    for(it=cardsInHand.begin(); it!=cardsInHand.end(); it++){
        (*it)->printRow(EvenOdd::EVEN);
        cout<<"  ";
    }
    cout<<endl;
    for(it=cardsInHand.begin(); it!=cardsInHand.end(); it++){
        (*it)->printRow(EvenOdd::ODD);
         cout<<"  ";
    }
    cout<<endl;
    
}
