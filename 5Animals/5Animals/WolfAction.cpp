//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "ActionCard.h"
#include "WolfAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

QueryResult WolfAction::query(){
    
	cout << " The Wolf action allows you to pick up a card from a table and place it in your hand" << endl;
	cout << "Choose a the index of the card you want to pick up" << endl;
	string row;
	string col;
	cout<< "enter the row of the card you want to pick up"<<endl;
	cin>>row;
	cout<< "enter the column of the card you want to pick up"<<endl;
	cin>>col;

    QueryResult qr = QueryResult("", 2);
	return qr;
    
}

void WolfAction::perform(Table &table, Player *player , QueryResult qr){

	player->getHand()+= table.pickAt(qr.getPosition(0),qr.getPosition(1));

}