//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include "Player.h"
#include "Hand.h"
#include <string>

using namespace std;

Player::Player(string name, string s_Animal, int id): d_name(name), playerHand(new Hand()), d_id(id){
    
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

void Player::setHand(Hand *h){
    
    playerHand=h;
    
}

Hand* Player::getHand(){
    
	return playerHand;
    
}

void Player::print(){
    
	//prints secret animal of player
	cout<<"The secret animal is: " << d_secretAnimal << endl;
    
}

ostream &operator <<(ostream &out, const Player& player){
    
    //writes player to file
    out << player.d_name;
    out << player.d_secretAnimal;
    out << player.d_id;
    out << player.playerHand;
    
    return out;
    
}

istream & operator >>(istream &in, Player& player){
    
    //retrieves player info from file
    in >> player.d_name;
    in >> player.d_secretAnimal;
    in >> player.d_id;
    in >> *player.playerHand;
    
    return in;
    
}

void Player::swapHands(Player &player){
    
    Hand *temp = player.playerHand;
    player.playerHand = playerHand;
    playerHand = temp;
    
}