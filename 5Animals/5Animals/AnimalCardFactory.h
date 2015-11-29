#ifndef AnimalCardFactory_H
#define AnimalCardFactory_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Deck.h"
#include <memory>

class AnimalCardFactory{


	static AnimalCardFactory* getFactory();
	Deck<std::shared_ptr<AnimalCard>> getDeck();

};

#endif