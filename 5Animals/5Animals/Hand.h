// prime header file
//
#include <string>
#ifndef HAND_H
#define HAND_H
#include <string>
#include <cstdlib>
#include <iostream>



class Hand{
private:

public:
	Hand& operator+=(std::shared_ptr<AnimalCard>);
	Hand& operator-=(std::shared_ptr<AnimalCard>);
	std::shared_ptr<AnimalCard> operator[](int);
	int noCards()
		//virtual friend Idiom<<(obj const& lhs, obj const& rhs);

};

#endif