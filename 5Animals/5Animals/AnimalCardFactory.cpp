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
#include "AnimalCard.h"
#include "AnimalCardFactory.h"
#include "NoSplit.h"
#include "TwoSplit.h"
#include "ThreeSplit.h"
#include "FourSplit.h"
#include "Joker.h"

AnimalCardFactory::AnimalCardFactory(){
    
    //create cards
    
    //no splits
    std::shared_ptr<AnimalCard> nos1( new NoSplit('b', Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(nos1);
    std::shared_ptr<AnimalCard> nos2( new NoSplit('d', Orientation::UP, EvenOdd::EVEN) );;
    deck.push_back(nos2);
    std::shared_ptr<AnimalCard> nos3( new NoSplit('h', Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(nos3);
    std::shared_ptr<AnimalCard> nos4( new NoSplit('m', Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(nos4);
    std::shared_ptr<AnimalCard> nos5( new NoSplit('w', Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(nos5);
    //two splits
    char tws1[2][2] = { {'b','b'},{'d','d'} };
    std::shared_ptr<AnimalCard> twos1( new TwoSplit(tws1, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(twos1);
    char tws2[2][2] = { {'b','b'},{'h','h'} };
    std::shared_ptr<AnimalCard> twos2( new TwoSplit(tws2, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(twos2);
    char tws3[2][2] = { {'b','b'},{'m','m'} };
    std::shared_ptr<AnimalCard> twos3( new TwoSplit(tws3, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(twos3);
    char tws4[2][2] = { {'b','b'},{'w','w'} };
    std::shared_ptr<AnimalCard> twos4( new TwoSplit(tws4, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(twos4);
    char tws5[2][2] = { {'b','b'},{'d','d'} };
    std::shared_ptr<AnimalCard> twos5( new TwoSplit(tws5, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(twos5);
    char tws6[2][2] = { {'h','h'},{'m','m'} };
    std::shared_ptr<AnimalCard> twos6( new TwoSplit(tws6, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(twos6);
    char tws7[2][2] = { {'d','d'},{'h','h'} };
    std::shared_ptr<AnimalCard> twos7( new TwoSplit(tws7, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(twos7);
    char tws8[2][2] = { {'d','d'},{'m','m'} };
    std::shared_ptr<AnimalCard> twos8( new TwoSplit(tws8, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(twos8);
    char tws9[2][2] = { {'d','d'},{'w','w'} };
    std::shared_ptr<AnimalCard> twos9( new TwoSplit(tws9, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(twos9);
    char tws10[2][2] = { {'m','m'},{'w','w'} };
    std::shared_ptr<AnimalCard> twos10( new TwoSplit(tws10, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(twos10);
    //three splits
    char ths1[2][2] = { {'b','b'},{'d','h'} };
    std::shared_ptr<AnimalCard> threes1( new ThreeSplit(ths1, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes1);
    char ths2[2][2] = { {'b','b'},{'d','m'} };
    std::shared_ptr<AnimalCard> threes2( new ThreeSplit(ths2, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes2);
    char ths3[2][2] = { {'b','b'},{'d','w'} };
    std::shared_ptr<AnimalCard> threes3( new ThreeSplit(ths3, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes3);
    char ths4[2][2] = { {'b','b'},{'h','m'} };
    std::shared_ptr<AnimalCard> threes4( new ThreeSplit(ths4, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes4);
    char ths5[2][2] = { {'b','b'},{'h','w'} };
    std::shared_ptr<AnimalCard> threes5( new ThreeSplit(ths5, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes5);
    char ths6[2][2] = { {'d','d'},{'h','b'} };
    std::shared_ptr<AnimalCard> threes6( new ThreeSplit(ths6, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes6);
    char ths7[2][2] = { {'d','d'},{'b','w'} };
    std::shared_ptr<AnimalCard> threes7( new ThreeSplit(ths7, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes7);
    char ths8[2][2] = { {'d','d'},{'b','m'} };
    std::shared_ptr<AnimalCard> threes8( new ThreeSplit(ths8, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes8);
    char ths9[2][2] = { {'d','d'},{'m','w'} };
    std::shared_ptr<AnimalCard> threes9( new ThreeSplit(ths9, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes9);
    char ths10[2][2] = { {'m','m'},{'w','b'} };
    std::shared_ptr<AnimalCard> threes10( new ThreeSplit(ths10, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes10);
    char ths11[2][2] = { {'m','m'},{'d','w'} };
    std::shared_ptr<AnimalCard> threes11( new ThreeSplit(ths11, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes11);
    char ths12[2][2] = { {'m','m'},{'b','d'} };
    std::shared_ptr<AnimalCard> threes12( new ThreeSplit(ths12, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes12);
    char ths13[2][2] = { {'m','m'},{'h','b'} };
    std::shared_ptr<AnimalCard> threes13( new ThreeSplit(ths13, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes13);
    char ths14[2][2] = { {'h','h'},{'w','d'} };
    std::shared_ptr<AnimalCard> threes14( new ThreeSplit(ths14, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes14);
    char ths15[2][2] = { {'h','h'},{'m','w'} };
    std::shared_ptr<AnimalCard> threes15( new ThreeSplit(ths15, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes15);
    char ths16[2][2] = { {'h','h'},{'b','d'} };
    std::shared_ptr<AnimalCard> threes16( new ThreeSplit(ths16, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes16);
    char ths17[2][2] = { {'h','h'},{'d','m'} };
    std::shared_ptr<AnimalCard> threes17( new ThreeSplit(ths17, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes17);
    char ths18[2][2] = { {'w','w'},{'m','d'} };
    std::shared_ptr<AnimalCard> threes18( new ThreeSplit(ths18, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes18);
    char ths19[2][2] = { {'w','w'},{'b','m'} };
    std::shared_ptr<AnimalCard> threes19( new ThreeSplit(ths19, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes19);
    char ths20[2][2] = { {'w','w'},{'d','b'} };
    std::shared_ptr<AnimalCard> threes20( new ThreeSplit(ths20, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(threes20);
    //four split
    char fs1[2][2] = { {'b','d'},{'h','m'} };
    std::shared_ptr<AnimalCard> fours1( new FourSplit(fs1, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours1);
    char fs2[2][2] = { {'b','d'},{'h','w'} };
    std::shared_ptr<AnimalCard> fours2( new FourSplit(fs2, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours2);
    char fs3[2][2] = { {'b','d'},{'m','w'} };
    std::shared_ptr<AnimalCard> fours3( new FourSplit(fs3, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours3);
    char fs4[2][2] = { {'b','h'},{'m','w'} };
    std::shared_ptr<AnimalCard> fours4( new FourSplit(fs4, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours4);
    char fs5[2][2] = { {'d','b'},{'h','w'} };
    std::shared_ptr<AnimalCard> fours5( new FourSplit(fs5, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours5);
    char fs6[2][2] = { {'d','h'},{'m','w'} };
    std::shared_ptr<AnimalCard> fours6( new FourSplit(fs6, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours6);
    char fs7[2][2] = { {'d','b'},{'m','w'} };
    std::shared_ptr<AnimalCard> fours7( new FourSplit(fs7, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours7);
    char fs8[2][2] = { {'d','w'},{'h','b'} };
    std::shared_ptr<AnimalCard> fours8( new FourSplit(fs8, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours8);
    char fs9[2][2] = { {'d','h'},{'w','m'} };
    std::shared_ptr<AnimalCard> fours9( new FourSplit(fs9, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours9);
    char fs10[2][2] = { {'d','m'},{'b','b'} };
    std::shared_ptr<AnimalCard> fours10( new FourSplit(fs10, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours10);
    char fs11[2][2] = { {'m','w'},{'d','b'} };
    std::shared_ptr<AnimalCard> fours11( new FourSplit(fs11, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours11);
    char fs12[2][2] = { {'m','d'},{'h','b'} };
    std::shared_ptr<AnimalCard> fours12( new FourSplit(fs12, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours12);
    char fs13[2][2] = { {'m','d'},{'w','h'} };
    std::shared_ptr<AnimalCard> fours13( new FourSplit(fs13, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours13);
    char fs14[2][2] = { {'h','w'},{'d','m'} };
    std::shared_ptr<AnimalCard> fours14( new FourSplit(fs14, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours14);
    char fs15[2][2] = { {'h','m'},{'w','b'} };
    std::shared_ptr<AnimalCard> fours15( new FourSplit(fs15, Orientation::UP, EvenOdd::EVEN) );
    deck.push_back(fours15);
    //joker
    std::shared_ptr<AnimalCard>joker(new Joker());
    deck.push_back(joker);
    
    //TODO: shuffle cards here? or in Table? 
    
}

Deck<AnimalCard> &AnimalCardFactory::getDeck(){
    return deck;
    
}

AnimalCardFactory::~AnimalCardFactory(){
    delete animalFactory;
}

AnimalCardFactory* AnimalCardFactory::getFactory(){
    static AnimalCardFactory animalFactory;
    return &animalFactory;
    
}

//
//Deck<std::shared_ptr<AnimalCard> > AnimalCardFactory::getDeck(){
//
//}


