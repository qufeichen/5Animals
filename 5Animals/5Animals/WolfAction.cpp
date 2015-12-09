//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include "ActionCard.h"
#include "WolfAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

WolfAction::WolfAction(): type(9){
    
    cardMatrix[0][0] = 'W';
    cardMatrix[0][1] = 'W';
    cardMatrix[1][0] = 'W';
    cardMatrix[1][1] = 'W';
    
}

char WolfAction::getAnimal(){
    
    return 'w';
    
}

void WolfAction::printRow(EvenOdd e){
    
    if(e == EVEN){
        cout << cardMatrix[0][0];
        cout << cardMatrix[0][1];
    }
    else if(e == ODD){
        cout << cardMatrix[1][0];
        cout << cardMatrix[1][1];
    }
    
}

QueryResult WolfAction::query(){
    
	cout << " The Wolf action allows you to pick up a card from a table and place it in your hand." << endl;
	cout << "Choose a the index of the card you want to pick up!" << endl;
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

    Hand *currentHand = player->getHand();
    currentHand->operator+=(table.pickAt(qr.getPosition(0),qr.getPosition(1)));
    
    cout<<"Here is your new hand: "<<endl;
    player->getHand()->print();
    cout<<endl;
    
}