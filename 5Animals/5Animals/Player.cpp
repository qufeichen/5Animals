//
// Created by Qufei Chen on 2015-11-24.
//

#include "Player.h"
#include <string>

using namespace std;

Player::Player(string name, string s_Animal): d_name(name){
//do we assign secret animal here?
	d_secretAnimal = s_Animal;
}

string Player:: swapSecretAnimal(string& newAnimal){
	string oldAnimal = d_secretAnimal;
	d_secretAnimal = newAnimal;
	return oldAnimal;
}

string Player::getSecretAnimal(){
	return d_secretAnimal;
}

ostream &operator <<(ostream &out, const Player& player){
	out << "Secret Animal" << player.d_secretAnimal << "Player Hand" << player.playerHand;
	return out;
}