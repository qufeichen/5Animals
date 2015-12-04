//
// Created by Qufei Chen on 2015-11-24.
//

#include "Player.h"
#include "Hand.h"
#include <string>

using namespace std;

Player::Player(string name, string s_Animal): d_name(name), playerHand(){
	d_secretAnimal = s_Animal;
}

string Player::swapSecretAnimal(string& newAnimal){
	string oldAnimal = d_secretAnimal;
	d_secretAnimal = newAnimal;
	return oldAnimal;
}

string Player::getSecretAnimal(){
	return d_secretAnimal;
}

string Player::getName(){
	return d_name;
}

void Player::setHand(Hand h){
	playerHand = h;
}

Hand Player::getHand(){
	return playerHand;
}

void Player::print(){
	//call print function of hand
	cout<<"The secret animal is: " << d_secretAnimal << endl;
}

ostream &operator <<(ostream &out, const Player& player){
	//cout << "Secret Animal" << player.d_secretAnimal << "Player Hand" << player.playerHand;
	return out;
}

void Player::swapHands(Player &player){
 Hand temp = player.playerHand;
 player.playerHand = playerHand;
 playerHand = temp;
}