#include <iostream>
#include "Table.h"
#include "Player.h"
#include "stdafx.h"

Table::Table(int numPlayers) : d_numPlayers(numPlayers){
	//add pointer to the center
	//only contains start card
	currentNumPlayers = 0;
	tableArray[52][52] = stack;
	//player array
	players = new Player[numPlayers];
	//index for selecting secret cards
	secretCardIndex = new int[numPlayers];
	for(int i = 0; i<numPlayers; ++i){
		secretCardIndex[i] = i+1;
	}
	//shuffle index
	random_shuffle(&secretCardIndex[0], &secretCardIndex[numPlayers-1]);

}

int Table::addAt(std::shared_ptr<AnimalCard> newCard, int row, int col){
	int value = 0;
	//check if able to put in card
	//if(){}


	tableArray[row][col] = newCard; 
	//check neighbours

	return value;
}

Table& Table::operator+=(std::shared_ptr<ActionCard> newCard){
	*stack+=newCard;

	return *this;
}

Table& Table::operator-=(std::shared_ptr<ActionCard> newCard){
	*stack-=newCard;

	return *this;
}

std::shared_ptr<AnimalCard>Table::pickAt(int row, int col){
	std::shared_ptr<AnimalCard> pickedCard;
	//remove fthe table
	try{
		if(row == 52 && col == 52)
		{
			throw std::exception("Illegal Pick");
		}else{
			pickedCard = tableArray[row][col];

			//delete element in table
			tableArray[row][col] = NULL;
		}
	}
	catch(exception& e){
		cout << "Illegal Pick";
	}
	return pickedCard;
}

bool Table::win(std::string& animal){
	bool win = true;

	//check of animal in string has won
	//wins as soon as there are 7 matching cards
	//Need logic


	return win;
}

ostream & operator <<(ostream& out , const Table& table){

	//Print whole table
	for(int i = 0 ; i < 103; i++){
		for(int j = 0; j < 103; j++){
			cout << table.tableArray[i][j];
		}
		cout <<"\n";
	}
return out;
}


Player Table::getPlayer(string playerName){
	for(int i = 0; i<d_numPlayers;i++){
		if(players[i].getName() == playerName){
			return players[i];
		}
	}
}
	
string Table::createPlayer(string name){
	if(currentNumPlayers >= d_numPlayers)
		return "max number of players already reached";

	string secretAnimal;
switch(secretCardIndex[currentNumPlayers])
   {
   case '1' :
    	secretAnimal = "Bear";
      	break;
   case '2' :
   		secretAnimal = "Wolf";
   		break;
   case '3' :
     	secretAnimal = "Hare";
     	break;
   case '4' :
      	secretAnimal = "Moose";
      	break;
   case '5' :
      	secretAnimal = "Deer";
     	 break;
   }
players[currentNumPlayers] = Player(name, secretAnimal);
++currentNumPlayers;
	return "player created successfully";
}
