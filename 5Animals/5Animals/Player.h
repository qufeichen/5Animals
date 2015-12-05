//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include <string>
#include "Hand.h"

using namespace std;

#ifndef INC_5ANIMALS_PLAYER_H
#define INC_5ANIMALS_PLAYER_H

class Player {
    
private:
	string d_name;
	string d_secretAnimal;
	Hand playerHand;
    
public:
	Player(string, string);
    string swapSecretAnimal(string&);
	string getSecretAnimal();
	string getName();
	Hand getHand();
	void setHand(Hand);
    void swapHands(Player&);
	void print();
	friend ostream & operator <<(ostream &out, const Player&);
	void swapHands(Player*);

};


#endif //INC_5ANIMALS_PLAYER_H