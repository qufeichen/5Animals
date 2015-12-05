//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "Deck.h"
#include <string>
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>

template<class T> std::shared_ptr<T> Deck<T>::draw(){
    
    shared_ptr<T> temp;
    //pop last element and return it
    temp = this->back();
    //remove last element from deck
    this->pop_back();
    return temp;

}