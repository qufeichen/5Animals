//
// Created by Qufei Chen on 2015-11-16.
//

#include "ActionCard.h"
#include "HareAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include "AnimalCard.h"
#include <iostream>
#include <string>

using namespace std;

QueryResult HareAction::query(){
    
    cout<<" The Hare action allows you to move an animal card on the table including the joker to a different location on the table where the card is valid" << endl;

	int aRow;
	int aCol;
	int bRow;
	int bCol;
    cout<< "Choose a card to move"<<endl;
    cout<< "Enter the row index of the card you want to move"<<endl;
    cin>>aRow;
    cout<< "Enter the column index of the card you want to move"<<endl;
    cin>>aCol;
    cout<< "Enter the row index of position you want to move the card to"<<endl;
    cin>>bRow;
    cout<< "Enter the column index of position you want to move the card to"<<endl;
    cin>>bCol;

    QueryResult qr = QueryResult("", 4);

    qr.addToArray(aRow);
    qr.addToArray(aCol);
    qr.addToArray(bRow);
    qr.addToArray(bCol);

    return qr;
}


void HareAction::perform(Table & table, Player* player , QueryResult qr){

	shared_ptr<AnimalCard> card = table.pickAt(qr.getPosition(0),qr.getPosition(1));
	table.addAt(card, qr.getPosition(2), qr.getPosition(3) );
    
}