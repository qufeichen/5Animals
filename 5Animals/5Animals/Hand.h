//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <list>
#include <iostream>
#include <algorithm>
#include <vector>
#include "AnimalCard.h"

#ifndef HAND_H
#define HAND_H


class Hand{
    
private:
	int numOfCards;
	std::vector<std::shared_ptr<AnimalCard>> cardsInHand;
    
public:
	Hand();
	std::shared_ptr<AnimalCard> operator[](int);
	int noCards();
    void print();
    
    Hand& operator+=(std::shared_ptr<AnimalCard>);
    Hand& operator-=(std::shared_ptr<AnimalCard>);
	friend ostream & operator <<(ostream &out, const Hand&);
    friend istream & operator >>(istream &in, Hand&);

};

#endif