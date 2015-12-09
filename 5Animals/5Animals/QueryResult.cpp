//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include "QueryResult.h"
#include <iostream>
#include <string>

using namespace std;

QueryResult::QueryResult(string playerName, int arrayLength): d_playerName(playerName), d_arrayLength(arrayLength) {
    
	index = 0;
	if(arrayLength !=0){
		d_cardLocation = new int[arrayLength];
	}
    
}

void QueryResult::addToArray(int pos){
    
	d_cardLocation[index] = pos;
	index++;
    
}

string QueryResult::getPlayerName(){
    
	return d_playerName;
    
}

int QueryResult::getPosition(int pos){
    
	if (d_arrayLength == 0)
		return NULL;

	return d_cardLocation[pos];
    
}