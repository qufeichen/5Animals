//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "ActionCard.h"
#include "DeerAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

DeerAction::DeerAction(){
    
    cardMatrix[0][0] = 'D';
    cardMatrix[0][1] = 'D';
    cardMatrix[1][0] = 'A';
    cardMatrix[1][1] = 'A';
    
}

void DeerAction::printRow(EvenOdd e){
    
    if(e == EVEN){
        cout << cardMatrix[0][0];
        cout << cardMatrix[0][1];
    }
    else if(e == ODD){
        cout << cardMatrix[1][0];
        cout << cardMatrix[1][1];
    }
    
}

QueryResult DeerAction::query(){

    cout<<" The Deer Action allows a player to select another player to trade goals with" << endl;

    cout<< "Choose a player to switch goals with";
    std::string userIn;
    cin>>userIn;

    QueryResult qr = QueryResult(userIn, 0);
    return qr;
}

void DeerAction::perform(Table & table, Player* player, QueryResult qr){
	
    string animal1 = table.getPlayer( qr.getPlayerName() )->getSecretAnimal();
    string animal2 = player->getSecretAnimal();

    player->swapSecretAnimal(animal1);
    table.getPlayer(qr.getPlayerName())->swapSecretAnimal(animal2);
    //TODO: swap methods return old method. should we print this?
    
}