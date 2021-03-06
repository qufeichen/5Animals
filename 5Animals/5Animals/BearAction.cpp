//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include "BearAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include "Hand.h" 
#include <iostream>
#include <string>

using namespace std;

BearAction::BearAction():type(5){
    
    cardMatrix[0][0] = 'B';
    cardMatrix[0][1] = 'B';
    cardMatrix[1][0] = 'B';
    cardMatrix[1][1] = 'B';
    
}

char BearAction::getAnimal(){
    
    return 'b';
    
}

void BearAction::printRow(EvenOdd e){
    
    if(e == EVEN){
        cout << cardMatrix[0][0];
        cout << cardMatrix[0][1];
    }
    else if(e == ODD){
        cout << cardMatrix[1][0];
        cout << cardMatrix[1][1];
    }
    
}

QueryResult BearAction::query(){

    cout<<" The Bear Action is allows a player to select another player to switch hands" << endl;
    
    cout<< "Choose a player to switch hands with: "<<endl;
    std::string switchName;
    cin>>switchName;

    QueryResult qr = QueryResult(switchName, 0);
    return qr;
    
}

void BearAction::perform(Table &table, Player* player , QueryResult qr){
  
    //get hands of both players
    Hand *currentHand = player->getHand();
    Player *otherPlayer = table.getPlayer(qr.getPlayerName());
    Hand *otherPlayerHand = otherPlayer->getHand();
    
    //swap hands
    player->setHand(otherPlayerHand);
    otherPlayer->setHand(currentHand);
    cout<<endl;
    
    //print new hands for both players
    cout<<"Your new hand:"<<endl;
    player->getHand()->print();
    cout<<endl;
    
    cout<<qr.getPlayerName()<<"'s new hand:"<<endl;
    otherPlayer->getHand()->print();
    cout<<endl;

}
