//
// Created by Qufei Chen on 2015-11-16.
//

#include "ActionCard.h"
#include "WolfAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include <iostream>
#include <string>
#include "stdafx.h"

using namespace std;

QueryResult WolfAction::query(){
	//will display the action on the console and query the player for input if needed. Returns a QueryResult object storing the result

	//print action
	cout << " The Wolf action allows you to pick up a card from a table and place it in your hand" << endl;

	//if input is needed, get input
	cout << "Choose a card to pick up" << endl;
	std::string userIn;
	cin >> userIn;

	//create and return new Query Result
	QueryResult qr = QueryResult(userIn, NULL);
	return qr;
}



void WolfAction::perform(Table &, Player* , QueryResult){

}