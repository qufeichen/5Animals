#ifndef AnimalCardFactory_H
#define AnimalCardFactory_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Deck.h"
#include <memory>

class AnimalCardFactory{
private:
	// create deck of 50 animal cards plus joker all have to be differen
	//5 no split
	//10 split2
	//20 split3

public:
	static AnimalCardFactory* getFactory();
	Deck<std::shared_ptr<AnimalCard>> getDeck();

};

#endif