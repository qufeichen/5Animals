//
// Created by Qufei Chen on 2015-11-16.
//

#include "ActionCard.h"
#include "HareAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

QueryResult HareAction::query(){
//will display the action on the console and query the player for input if needed. Returns a QueryResult object storing the result

    //print action
    cout<<" The Hare action allows you to move an animal card on the table including the joker to a different location on the table where the card is valid" << endl;

    //if input is needed, get input
    cout<< "Choose a card to move"<<endl;
    std::string userIn;
    cin>>userIn;

    //create and return new Query Result
    QueryResult qr = QueryResult(userIn);
    return qr;
}


void HareAction::perform(Table &, Player* , QueryResult){
//The hare action card allows a player to move an animal card on the table including the joker to a different location on the table where the card is valid.
}