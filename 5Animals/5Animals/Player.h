//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include <string>
#include "Hand.h"

#ifndef INC_5ANIMALS_PLAYER_H
#define INC_5ANIMALS_PLAYER_H

using namespace std;


class Player {
    
private:
	string d_name;
	string d_secretAnimal;
    int d_id;
	Hand *playerHand;

    
public:
	Player(string, string, int);
    string swapSecretAnimal(string&);
	string getSecretAnimal();
	string getName();
	Hand* getHand();
	void setHand(Hand*);
    void swapHands(Player&);
	void print();
	friend ostream & operator <<(ostream &out, const Player&);
    friend istream & operator >>(istream &in, Player&);
	void swapHands(Player*);

};


#endif