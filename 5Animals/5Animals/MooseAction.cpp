//
// Created by Qufei Chen on 2015-11-16.
//

#include "ActionCard.h"
#include "MooseAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

QueryResult MooseAction::query(){
	//will display the action on the console and query the player for input if needed. Returns a QueryResult object storing the result

	//print action
	cout << " The Moose action triggers a rotation of secret animals from player 1 to player 2, from 2 to 3, etc." << endl;

	//no input from user needed
	string userIn = "";

	//create and return new Query Result
	QueryResult qr = QueryResult(userIn);
	return qr;
}



void MooseAction::perform(Table &, Player* , QueryResult){

}