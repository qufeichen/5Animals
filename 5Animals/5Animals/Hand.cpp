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
        
        std::shared_ptr<AnimalCard> card;
        
        if(typeOfCard == 0){
            Joker *c = new Joker();
            card.reset(c);
        } else if (typeOfCard == 1){
            NoSplit *c = new NoSplit('b', Orientation::UP, EvenOdd::EVEN);
            card.reset(c);
        } else if (typeOfCard == 2){
            char tws1[2][2] = { {'b','b'},{'d','d'} };
            TwoSplit *c = new TwoSplit(tws1, Orientation::UP, EvenOdd::EVEN);
            card.reset(c);
        } else if (typeOfCard == 3){
            char ths1[2][2] = { {'b','b'},{'d','h'} };
            ThreeSplit *c = new ThreeSplit(ths1, Orientation::UP, EvenOdd::EVEN);
            card.reset(c);
        } else if(typeOfCard == 4){
            char fs1[2][2] = { {'b','d'},{'h','m'} };
            FourSplit *c = new FourSplit(fs1, Orientation::UP, EvenOdd::EVEN);
            card.reset(c);
        } else if(typeOfCard == 5){
            BearAction *c = new BearAction();
            card.reset(c);
        } else if(typeOfCard == 6){
            DeerAction *c = new DeerAction();
            card.reset(c);
        } else if( typeOfCard == 7) {
            HareAction *c = new HareAction();
            card.reset(c);
        } else if( typeOfCard == 8){
            MooseAction *c = new MooseAction();
            card.reset(c);
        } else if (typeOfCard == 9){
            WolfAction *c = new WolfAction();
            card.reset(c);
        }
        in >> *card ;
        hand.operator+=(card);
    }
    
    return in;
    
}
