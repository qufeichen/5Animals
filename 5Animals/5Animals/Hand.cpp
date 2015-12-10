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
#include "Joker.h"
#include "AnimalCard.h"
#include "BearAction.h"
#include "DeerAction.h"
#include "HareAction.h"
#include "MooseAction.h"
#include "WolfAction.h"
#include "TwoSplit.h"
#include "ThreeSplit.h"
#include "FourSplit.h"

using namespace std;

Hand::Hand():numOfCards(0){
    
}

std::shared_ptr<AnimalCard> Hand::operator[](int index){
    
	std::shared_ptr<AnimalCard> temp;
    
    if((index < numOfCards) && (index>=0)){
        temp = cardsInHand[index];
    }

	return temp;
	
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
    
    //print first row of hand
    for(int i = 0; i<numOfCards; i++){
        cardsInHand[i]->printRow(EvenOdd::EVEN);
        cout<<"  ";
    }
    cout<<endl;
    
    //print second row of hand
    for(int i = 0; i<numOfCards; i++){
        cardsInHand[i]->printRow(EvenOdd::ODD);
         cout<<"  ";
    }
    cout<<endl;
    
}

Hand& Hand::operator+=(std::shared_ptr<AnimalCard> newCard){
    
    //add card to hand
    
    numOfCards = numOfCards+1;
    cardsInHand.push_back(newCard);
    
    return *this;
    
    
}


Hand& Hand::operator-=(std::shared_ptr<AnimalCard>newCard){
    
    //remove card from hand
    
    //find card in hand
    if( find(cardsInHand.begin(), cardsInHand.end(), newCard) != cardsInHand.end() ){
        cardsInHand.erase(find(cardsInHand.begin(), cardsInHand.end(), newCard));
    }
    
    //update count
    numOfCards--;
    
    return *this;
    
}

ostream& operator <<(ostream &out, const Hand& handGiven){
    
    //write hand to file
    
    out<<handGiven.numOfCards;
    
    list<shared_ptr<AnimalCard>>::const_iterator it;
    for(int i = 0; i<handGiven.numOfCards; i++){
        
        //type used to identify what kind of card is being saved
        //used when retriving hand from file
        out << handGiven.cardsInHand[i]->type;
        out << handGiven.cardsInHand[i];
        
     }
    
    return out;
    
}

istream & operator >>(istream &in, Hand& hand){
    
    //retrieve hand from file
    
    in >> hand.numOfCards;
    for(int i = 0; i<hand.numOfCards; i++){
        
        //typeOfCard used to determine what type of card was saved
        int typeOfCard;
        in >> typeOfCard;
        
        if(typeOfCard == 0){
            std::shared_ptr<AnimalCard>joker(new Joker());
            in >> joker;
            hand.operator+=(joker);
        } else if (typeOfCard == 1){
            std::shared_ptr<AnimalCard> nos1( new NoSplit('b', Orientation::UP, EvenOdd::EVEN) );
            in>> nos1;
            hand.operator+=(nos1);
        } else if (typeOfCard == 2){
            char tws1[2][2] = { {'b','b'},{'d','d'} };
            std::shared_ptr<AnimalCard> twos1( new TwoSplit(tws1, Orientation::UP, EvenOdd::EVEN) );
            in >> twos1;
            hand.operator+=(twos1);
        } else if (typeOfCard == 3){
            char ths1[2][2] = { {'b','b'},{'d','h'} };
            std::shared_ptr<AnimalCard> threes1( new ThreeSplit(ths1, Orientation::UP, EvenOdd::EVEN) );
            in >> threes1;
            hand.operator+=(threes1);
        } else if (typeOfCard == 4){
            char fs1[2][2] = { {'b','d'},{'h','m'} };
            std::shared_ptr<AnimalCard> fours1( new FourSplit(fs1, Orientation::UP, EvenOdd::EVEN) );
            in>> fours1;
            hand.operator+=(fours1);
        } else if(typeOfCard == 5){
            std::shared_ptr<ActionCard> ba1( new BearAction() );
            in>>ba1;
            hand.operator+=(ba1);
        } else if(typeOfCard == 6){
            std::shared_ptr<ActionCard> da1( new DeerAction() );
            in>>da1;
            hand.operator+=(da1);
        } else if( typeOfCard == 7) {
            std::shared_ptr<ActionCard> ha1( new HareAction() );
            in>>ha1;
            hand.operator+=(ha1);
        } else if( typeOfCard == 8){
            std::shared_ptr<ActionCard> ma1( new MooseAction() );
            in>>ma1;
            hand.operator+=(ma1);
        } else if (typeOfCard == 9){
            std::shared_ptr<ActionCard> wa3( new WolfAction() );
            hand.operator+=(wa3);
        }
    }
    
    return in;
    
}
