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
	Player(string, string); //does constructor assign secret animal to player?
	string swapSecretAnimal(string&);
	string getSecretAnimal();
	friend ostream & operator <<(ostream &out, const Player&);

};


#endif //INC_5ANIMALS_PLAYER_H