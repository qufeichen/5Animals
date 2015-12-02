//

// Created by Qufei Chen on 2015-11-24.
//
#include <string>
#include <iostream>

#ifndef INC_5ANIMALS_QUERYRESULT_H
#define INC_5ANIMALS_QUERYRESULT_H

using namespace std;

class QueryResult{

private:
    //variable:
    string d_playerName;
	int *d_cardLocation;
	int d_arrayLength;
	int index;

public:
    //constructor
    QueryResult(string, int);
	void addToArray(int);
	string getPlayerName();
	int getPosition(int);
};

#endif //INC_5ANIMALS_QUERYRESULT_H