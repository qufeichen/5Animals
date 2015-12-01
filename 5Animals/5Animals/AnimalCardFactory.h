#ifndef AnimalCardFactory_H
#define AnimalCardFactory_H
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
#include "Deck.h"
#include "NoSplit.h"
#include "TwoSplit.h"
#include "ThreeSplit.h"
#include "FourSplit.h"
#include "Joker.h"
#include <memory>

class AnimalCardFactory{
private:
	//Create Deck
	Deck <std::shared_ptr<AnimalCard>> deck;
	// create deck of 50 animal cards plus joker all have to be different
	////5 no split
	//std::shared_ptr<NoSplit> card1;
	//NoSplit card2;
	//NoSplit card3;
	//NoSplit card4;
	//NoSplit card5;
	////10 split2
	//TwoSplit card6;
	//TwoSplit card7;
	//TwoSplit card8;
	//TwoSplit card9;
	//TwoSplit card10;
	//TwoSplit card11;
	//TwoSplit card12;
	//TwoSplit card13;
	//TwoSplit card14;
	//TwoSplit card15;
	////20 split3
	//ThreeSplit card16;
	//ThreeSplit card17;
	//ThreeSplit card18;
	//ThreeSplit card19;
	//ThreeSplit card20;
	//ThreeSplit card21;
	//ThreeSplit card22;
	//ThreeSplit card23;
	//ThreeSplit card24;
	//ThreeSplit card25;
	//ThreeSplit card26;
	//ThreeSplit card27;
	//ThreeSplit card28;
	//ThreeSplit card29;
	//ThreeSplit card30;
	//ThreeSplit card31;
	//ThreeSplit card32;
	//ThreeSplit card33;
	//ThreeSplit card34;
	//ThreeSplit card35;



	////15 split4
	//FourSplit card36;
	//FourSplit card37;
	//FourSplit card38;
	//FourSplit card39;
	//FourSplit card40;
	//FourSplit card41;
	//FourSplit card42;
	//FourSplit card43;
	//FourSplit card44;
	//FourSplit card45;
	//FourSplit card46;
	//FourSplit card47;
	//FourSplit card48;
	//FourSplit card49;
	//FourSplit card50;

	//Joker
	Joker joker;

public:
	AnimalCardFactory();
	static AnimalCardFactory* getFactory();
	Deck<std::shared_ptr<AnimalCard>> getDeck();
	static AnimalCardFactory* s_factory;
};

#endif