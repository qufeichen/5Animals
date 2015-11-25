// prime header file
//
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
#include "AnimalCard.h"

#ifndef HAND_H
#define HAND_H



class Hand{
private:

public:
	Hand& operator+=(std::shared_ptr<AnimalCard>);
	Hand& operator-=(std::shared_ptr<AnimalCard>);
	std::shared_ptr<AnimalCard> operator[](int);
	int noCards();
		//virtual friend Idiom<<(obj const& lhs, obj const& rhs);
	void print();

};

#endif