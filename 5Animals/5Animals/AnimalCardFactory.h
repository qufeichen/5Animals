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
	static AnimalCardFactory* getFactory();
	Deck<std::shared_ptr<AnimalCard>> getDeck();
	static AnimalCardFactory* s_factory;
};

#endif