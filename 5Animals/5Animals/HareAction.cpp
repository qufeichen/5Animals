//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "ActionCard.h"
#include "HareAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include "AnimalCard.h"
#include <iostream>
#include <string>

using namespace std;

HareAction::HareAction(){
    
    cardMatrix[0][0] = 'h';
    cardMatrix[0][1] = 'h';
    cardMatrix[1][0] = 'h';
    cardMatrix[1][1] = 'h';
    
}

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