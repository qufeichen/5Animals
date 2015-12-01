
#include <iostream>
#include <string>

#include "NoSplit.h"
#include "TwoSplit.h"
#include "FourSplit.h"
#include "ThreeSplit.h"
#include "BearAction.h"
#include "DeerAction.h"
#include "MooseAction.h"
#include "Joker.h"
#include "Deck.h"
int main()
{
	NoSplit no('c');
	EvenOdd even = EVEN;
	no.printRow(cout, even);
	TwoSplit two(2);
	ThreeSplit three(25);
	FourSplit four(51);
	BearAction bear;
	DeerAction deer;
	MooseAction moose;
	Joker joker;
	Deck<MooseAction> deck;
	StartCard start;


	std::cin.get();
	return 0;
}