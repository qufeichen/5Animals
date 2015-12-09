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

#ifndef DECK_H
#define DECK_H


template <class T>

class Deck : public std::vector<std::shared_ptr<T>>{
	
public:
    inline std::shared_ptr<T> draw(){
        shared_ptr<T> temp;
        //pop last element and return it
        temp = this->back();
        //remove last element from deck
        this->pop_back();
        
        return temp;
    }

};
#include "Deck.cpp"
#endif
