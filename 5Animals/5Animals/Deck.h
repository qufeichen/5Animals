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
#include <memory>
#include "AnimalCard.h"

#ifndef DECK_H
#define DECK_H


template <class T>

class Deck : public std::vector<std::shared_ptr<T>>{
	
public:
	std::shared_ptr<T> draw();

};

#endif
