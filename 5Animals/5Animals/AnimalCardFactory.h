#ifndef AnimalCardFactory_H
#define AnimalCardFactory_H
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