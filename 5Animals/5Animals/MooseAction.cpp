//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "MooseAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

MooseAction::MooseAction(){
    
    cardMatrix[0][0] = 'M';
    cardMatrix[0][1] = 'M';
    cardMatrix[1][0] = 'A';
    cardMatrix[1][1] = 'A';
}

void MooseAction::printRow(EvenOdd e){
    
    if(e == EVEN){
        cout << cardMatrix[0][0];
        cout << cardMatrix[0][1];
    }
    else if(e == ODD){
        cout << cardMatrix[1][0];
        cout << cardMatrix[1][1];
    }
    
}

QueryResult MooseAction::query(){
    
	cout << " The Moose action triggers a rotation of secret animals from player 1 to player 2, from 2 to 3, etc." << endl;

	string userIn = "";

	QueryResult qr = QueryResult(userIn,0);
	return qr;
    
}

void MooseAction::perform(Table & table, Player* player, QueryResult qr){
	
	string tempAni = table.getPlayer(table.getNumPlayers())->getSecretAnimal();
	for(int i = table.getNumPlayers(); i>0; i--)
	{
        string b = table.getPlayer(i-1)->getSecretAnimal();
        table.getPlayer(i)->swapSecretAnimal(b);
    
    }
	table.getPlayer(0)->swapSecretAnimal( tempAni );
    
}