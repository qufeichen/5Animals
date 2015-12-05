//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "ActionCard.h"
#include "BearAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include "Hand.h" 
#include <iostream>
#include <string>


using namespace std;

QueryResult BearAction::query(){

    cout<<" The Bear Action is allows a player to select another player to switch hands" << endl;
    
    cout<< "Choose a player to switch hands with";
    std::string switchName;
    cin>>switchName;

    QueryResult qr = QueryResult(switchName, 0);
    return qr;
    
}

void BearAction::perform(Table &table, Player* player , QueryResult qr){

    Hand h = player->getHand();
    player->setHand(table.getPlayer(qr.getPlayerName())->getHand());
    table.getPlayer(qr.getPlayerName())->setHand(h);

}