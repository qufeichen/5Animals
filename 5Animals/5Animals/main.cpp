
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
	NoSplit test;
	cout << test;
	TwoSplit two;
	ThreeSplit three;
	FourSplit four;
	BearAction bear;
	DeerAction deer;
	MooseAction moose;
	Joker joker;
	Deck<MooseAction> deck;
	StartCard start;

	
	std::cin.get();
	return 0;
}