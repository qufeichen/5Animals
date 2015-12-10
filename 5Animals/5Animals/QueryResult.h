//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include <string>
#include <iostream>

#ifndef INC_5ANIMALS_QUERYRESULT_H
#define INC_5ANIMALS_QUERYRESULT_H

using namespace std;


class QueryResult{

private:
    string d_playerName;
	int *d_cardLocation;
	int d_arrayLength;
	int index;

public:
    QueryResult(string, int);
	void addToArray(int);
	string getPlayerName();
	int getPosition(int);
    
};

#endif