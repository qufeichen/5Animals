#ifndef DECK_H
#define DECK_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "AnimalCard.h"
#include <memory>
using namespace std;

class Deck:public vector<shared_ptr<AnimalCard>>{
	
public:
	std::shared_ptr<AnimalCard> draw();


	//hard code cards in deck

};

#endif
