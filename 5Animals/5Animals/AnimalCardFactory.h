//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Deck.h"
#include "NoSplit.h"
#include "TwoSplit.h"
#include "ThreeSplit.h"
#include "FourSplit.h"
#include "Joker.h"
#include <memory>

#ifndef AnimalCardFactory_H
#define AnimalCardFactory_H


class AnimalCardFactory{
    
private:
	Deck <AnimalCard> deck;

public:
	AnimalCardFactory();
    ~AnimalCardFactory();
    Deck<AnimalCard> createDeck();
    AnimalCardFactory* animalFactory;
	static AnimalCardFactory* getFactory();
	Deck<AnimalCard> &getDeck();
    //Deck<std::shared_ptr<AnimalCard> > getDeck();
    
};

#endif