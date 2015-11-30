// prime header file
//
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
#include "AnimalCard.h"
#include <list>
#include <iostream>
#include <algorithm>

#ifndef HAND_H
#define HAND_H



class Hand{
private:
	int numOfCards;
	std::list<std::shared_ptr<AnimalCard>> cardsInHand;
public:
	Hand();
	Hand& operator+=(std::shared_ptr<AnimalCard>);
	Hand& operator-=(std::shared_ptr<AnimalCard>);
	std::shared_ptr<AnimalCard> operator[](int);
	int noCards();
	friend ostream & operator <<(ostream &out, const Hand&);


};

#endif