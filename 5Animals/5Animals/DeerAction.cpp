//
// Created by Qufei Chen on 2015-11-16.
//

#include "ActionCard.h"
#include "DeerAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

QueryResult DeerAction::query(){
//will display the action on the console and query the player for input if needed. Returns a QueryResult object storing the result

    //print action
    cout<<" The Deer Action allows a player to select another player to trade goals with" << endl;

    //if input is needed, get input
    cout<< "Choose a player to switch goals with";
    std::string userIn;
    cin>>userIn;

    //create and return new Query Result
    QueryResult qr = QueryResult(userIn, NULL);
    return qr;
}


void DeerAction::perform(Table &, Player* , QueryResult){
//The deer action card allows a player to select another player to trade goals with
}