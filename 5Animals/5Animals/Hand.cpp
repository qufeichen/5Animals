
#include <memory>
#include <ostream>
#include "Hand.h"
#include <algorithm>
#include <vector>
using namespace std;

Hand::Hand(){
	numOfCards = 0;
}

//Hand& Hand::operator+=(std::shared_ptr<AnimalCard> newCard){
//
//	++numOfCards;
//	cardsInHand.push_back(newCard);
//
//}
//
//
//Hand& Hand::operator-=(std::shared_ptr<AnimalCard>newCard){
//	try{
//			--numOfCards;
//			//remove if equal to newCard
//			cardsInHand.remove(newCard);
//	}
//	catch (shared_ptr<AnimalCard>){
//		cout << "card does not exist" << "\n";
//	}
//}
//
//std::shared_ptr<AnimalCard> Hand::operator[](int index){
//		try{
//			--numOfCards;
//			//remove if equal to index
//			std::list<std::shared_ptr<AnimalCard>>::iterator it;
//			for(int i = 0; i<index; i++){
//				it++;
//			}
//			
//			cardsInHand.erase(it);
//	}
//	catch (shared_ptr<AnimalCard>){
//		cout << "card does not exist in index" << "\n";
//	}
//}

int Hand::noCards(){
	return numOfCards;
}

//ostream& operator <<(ostream &out, const Hand& handGiven){
//		
//	for( int i = 0; i<handGiven.numOfCards; i++){
//		cout<<
//	}
//
//
//	std::for_each(handGiven.cardsInHand.begin(),handGiven.cardsInHand.end());
//		//number
//
//		
//	}
//
//
//
//}

