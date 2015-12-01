//
// Created by Qufei Chen on 2015-11-24.
//

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