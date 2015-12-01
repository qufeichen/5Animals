//
// Created by Qufei Chen on 2015-11-16.
//

#include "ActionCard.h"
#include "BearAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

QueryResult BearAction::query(){
//will display the action on the console and query the player for input if needed. Returns a QueryResult object storing the result

    //print action
    cout<<" The Bear Action is allows a player to select another player to switch hands" << endl;
	//get input from player
    cout<< "Choose a player to switch hands with";
    std::string userIn;
    cin>>userIn;

    //create and return new Query Result
    QueryResult qr = QueryResult(userIn, NULL);
    return qr;
}


void BearAction::perform(Table &, Player* , QueryResult){
    //perform the action with the user input stored in QueryResult
    //The bear action card allows a player to select another player to switch hands.



}