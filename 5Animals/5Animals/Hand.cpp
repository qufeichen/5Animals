//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include <memory>
#include <ostream>
#include <algorithm>
#include <vector>
#include "Hand.h"

using namespace std;

Hand::Hand():numOfCards(0){
    
}

Hand& Hand::operator+=(std::shared_ptr<AnimalCard> newCard){

    numOfCards = numOfCards+1;
	cardsInHand.push_back(newCard);
	return *this;
    

}


Hand& Hand::operator-=(std::shared_ptr<AnimalCard>newCard){
    
    if( find(cardsInHand.begin(), cardsInHand.end(), newCard) != cardsInHand.end() ){
        cardsInHand.erase(find(cardsInHand.begin(), cardsInHand.end(), newCard));
    }
    
    numOfCards--;
    return *this;
    
}

std::shared_ptr<AnimalCard> Hand::operator[](int index){
    
	std::shared_ptr<AnimalCard> temp;
    
    if((index < numOfCards) && (index>=0)){
        temp = cardsInHand[index];
    }
    
	return temp;
    //returns null if index is out of scope
	
}

int Hand::noCards(){
    
	return numOfCards;
    
}

void Hand::print(){
    
    //print index
    for (int i = 0; i<numOfCards; i++){
        cout<<i<<"   ";
    }
    cout<<endl;
    
    for(int i = 0; i<numOfCards; i++){
        cardsInHand[i]->printRow(EvenOdd::EVEN);
        cout<<"  ";
    }
    cout<<endl;
    for(int i = 0; i<numOfCards; i++){
        cardsInHand[i]->printRow(EvenOdd::ODD);
         cout<<"  ";
    }
    cout<<endl;
    
}

ostream& operator <<(ostream &out, const Hand& handGiven){
    
    out<<handGiven.numOfCards;
    list<shared_ptr<AnimalCard>>::const_iterator it;
    for(int i = 0; i<handGiven.numOfCards; i++){
        out<<handGiven.cardsInHand[i];
    }
    
    return out;
    
}

istream & operator >>(istream &in, Hand& hand){
    //TODO: implement
    
//    in >> hand.numOfCards;
//    for(int i = 0; i<hand.numOfCards; i++){
//        std::shared_ptr<AnimalCard> nos1( new AnimalCard() );
//
////        cin >> card;
////        
//    
//    }
    return in;
    
}
