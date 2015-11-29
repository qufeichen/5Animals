
#include <memory>
#include <ostream>
#include "Hand.h"

using namespace std;

Hand::Hand(){
	numOfCards = 0;
}

//Hand& Hand::operator+=(std::shared_ptr<AnimalCard>){
//
//	++numOfCards;
//	
//
//}
//
//
//Hand& Hand::operator-=(std::shared_ptr<AnimalCard>){
//	--numOfCards;
//	try{
//	}
//	catch (shared_ptr<AnimalCard>){
//		cout << "card does not exist" << "\n";
//	}
//}

//std::shared_ptr<AnimalCard> operator[](int index){

//}

int Hand::noCards(){
	return numOfCards;
}

//virtual friend Idiom<<(obj const& lhs, obj const& rhs){
//}



void Hand::print(){

}

