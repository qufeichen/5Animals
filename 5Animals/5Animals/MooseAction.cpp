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
	QueryResult qr = QueryResult(userIn,0);
	return qr;
}



void MooseAction::perform(Table & table, Player* player, QueryResult qr){
	
	string tempAni = table.getPlayer(table.getNumPlayers()).getSecretAnimal();
	for(int i = table.getNumPlayers(); i>0; i--)
	{
        string b = table.getPlayer(i-1).getSecretAnimal();
        table.getPlayer(i).swapSecretAnimal(b);
    
    }
	table.getPlayer(0).swapSecretAnimal( tempAni );
}