//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include "DeerAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

DeerAction::DeerAction(): type(6){
    
    cardMatrix[0][0] = 'D';
    cardMatrix[0][1] = 'D';
    cardMatrix[1][0] = 'D';
    cardMatrix[1][1] = 'D';
    
}

char DeerAction::getAnimal(){
    
    return 'd';
    
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

    cout<<" The Deer Action allows a player to select another player to trade goals with " << endl;

    cout<< "Choose a player to switch goals with:"<<endl;;
    std::string userIn;
    cin>>userIn;

    QueryResult qr = QueryResult(userIn, 0);
    return qr;
    
}

void DeerAction::perform(Table & table, Player* player, QueryResult qr){
	
    //get secret animals of both players
    string animal1 = table.getPlayer( qr.getPlayerName() )->getSecretAnimal();
    string animal2 = player->getSecretAnimal();

    //swap secret animals
    player->swapSecretAnimal(animal1);
    table.getPlayer(qr.getPlayerName())->swapSecretAnimal(animal2);
    
    //print result
    cout<<"Your new secret animal is "<<player->getSecretAnimal()<<endl;
    cout<<endl;
    cout<<qr.getPlayerName()<<"'s new secret animal is "<<animal2<<endl;
    cout<<endl;
    
}