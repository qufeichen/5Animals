//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include "HareAction.h"
#include "QueryResult.h"
#include "Table.h"
#include "Player.h"
#include "AnimalCard.h"
#include <iostream>
#include <string>

using namespace std;

HareAction::HareAction(){
    
    cardMatrix[0][0] = 'H';
    cardMatrix[0][1] = 'H';
    cardMatrix[1][0] = 'H';
    cardMatrix[1][1] = 'H';
    
}

char HareAction::getAnimal(){
    
    return 'h';
    
}

void HareAction::printRow(EvenOdd e){
    
    if(e == EVEN){
        cout << cardMatrix[0][0];
        cout << cardMatrix[0][1];
    }
    else if(e == ODD){
        cout << cardMatrix[1][0];
        cout << cardMatrix[1][1];
    }
    
}

QueryResult HareAction::query(){
    
    cout<<" The Hare action allows you to move an animal card on the table including the joker to a different location on the table where the card is valid" << endl;

	int aRow;
	int aCol;
	int bRow;
	int bCol;
    cout<< "Choose a card to move!"<<endl;
    cout<< "Enter the row index of the card you want to move:"<<endl;
    cin>>aRow;
    cout<< "Enter the column index of the card you want to move:"<<endl;
    cin>>aCol;
    cout<< "Enter the row index of position you want to move the card to:"<<endl;
    cin>>bRow;
    cout<< "Enter the column index of position you want to move the card to:"<<endl;
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
    if(card == 0){
        cout<<"Error is picking card from table."<<endl;
        return;
    }
	table.addAt(card, qr.getPosition(2), qr.getPosition(3) );
    
    cout<<"The card has been moved successfully!"<<endl;
    cout<<"Here is the modified table: "<<endl;
    table.print();
    cout<<endl;
    
}