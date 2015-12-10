//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>
#include "AnimalCard.h"
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

#ifndef DECK_H
#define DECK_H


template <class T>

class Deck : public std::vector<std::shared_ptr<T>>{
	
public:
    inline std::shared_ptr<T> draw(){
        
        shared_ptr<T> temp;
        
        //get last element in deck
        temp = this->back();
        
        //remove last element from deck
        this->pop_back();
        
        return temp;
        
    }
    
    inline friend ostream & operator <<(ostream &out, Deck& deck){
        
        //write deck to file
        out << deck.size();
        
        std::shared_ptr<AnimalCard> card;
        for(int i = 0; i < deck.size(); i++){
            card = deck.draw();
            out << card->type;
            out << card;
        }
        
        return out;
        
    };
    
    inline friend istream & operator >>(istream &in, Deck& deck){
        
        //retrieve deck from file
        
        int numCards;
        in >> numCards;
        for(int i = 0; i<numCards; i++){
            
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
            deck.push_back(card);

        }
        
        return in;
        
    };

};

#endif
