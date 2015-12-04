#ifndef DECK_H
#define DECK_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "AnimalCard.h"
#include <memory>

template <class T>

class Deck : public std::vector<std::shared_ptr<T>>{
	
public:
	std::shared_ptr<T> draw();

};

#endif
