//
// Created by Qufei Chen on 2015-11-24.
//

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