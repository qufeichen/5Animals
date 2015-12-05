//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include <iostream>
#include "Table.h"
#include "Player.h"

Table::Table (int numPlayers) : d_numPlayers(numPlayers),  bearCount(0), deerCount(0), hareCount(0), mooseCount(0), wolfCount(0){
	
    //only contains start card
	currentNumPlayers = 0;
	tableArray[52][52] = stack;

    //index for selecting secret cards
    secretCardIndex = new int[numPlayers];
	for(int i = 0; i<numPlayers; ++i)
	{ 
		secretCardIndex[i] = i+1;
	}
	random_shuffle(&secretCardIndex[0], &secretCardIndex[numPlayers-1]); //shuffle index

}

int Table::addAt(std::shared_ptr<AnimalCard> newCard, int row, int col){
	int value = 0;
	//check if able to put in card
	if(tableArray[row][col] != 0)
	{
		cout<<"error: this index is already occupied"<<endl;
		return 1; 
	}

	tableArray[row][col] = newCard;
	
    return value;
}

Table& Table::operator+=(std::shared_ptr<ActionCard> newCard){
	*stack+=newCard;

	//get type for newCard see what kind of animal it is

	return *this;
}

Table& Table::operator-=(std::shared_ptr<ActionCard> newCard){
	*stack-=newCard;

	return *this;
}

std::shared_ptr<AnimalCard>Table::pickAt(int row, int col){
	std::shared_ptr<AnimalCard> pickedCard;
	//remove from the table
	try{
		if(row == 52 && col == 52)
		{
			throw runtime_error("Illegal Pick");
		}
		else
		{
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

void Table::animalCount(std::shared_ptr<AnimalCard> card){
	// check what type it is
	std::string animalType =typeid(card).name();
	//check no split, two split etc

	//need to test
	//if(animalType == "NoSplit"){
	//	//print each row to check

	//}else if(animalType == "TwoSplit"){
	//	//print each row to check
	//}else if(animalType == "ThreeSplit"){
	//	//print each row to check
	//}else if(animalType == "FoursSplit"){
	//	//print each row to check
	//}


}

bool Table::win(std::string& animal){
	bool win = true;

	//Need logic
	//Project simplification. 
	//To ease checking if a player has won, you now only have to count the number of cards on the table with the player's secret animal. 
	//The animals do not have to be connected in order to be included in the count. Because the counts will go up, a player will now need 12 cards. 
	//The rules for placing cards (or anything else) are not affected by this change.

	//-> do we want to keep 5 variables, that each counts the number of occurance of each animal? 
	// if any of them = 7, they win


	return win;
}

ostream & operator <<(ostream& out , const Table& table){

	//Print whole table
	for(int i = 0 ; i < 103; i++)
	{
		for(int j = 0; j < 103; j++)
		{
			cout << table.tableArray[i][j];
		}
		cout <<"\n";
	}
	return out;
}

int Table::getNumPlayers(){
	return d_numPlayers;
}

Player* Table::getPlayer(string playerName) {
    
    Player* player = 0;
        for(int i = 0; i<d_numPlayers;i++)
            {
                if(players[i].getName() == playerName){
                    player = getPlayer(i);
                }
            }
    
    return player;

}

Player* Table::getPlayer(int i){
    
    Player* player = 0;
	player = &players[i];
    return player;
}


string Table::createPlayer(string name){
	if(currentNumPlayers >= d_numPlayers)
		return "max number of players already reached";


	string secretAnimal;
	switch(secretCardIndex[currentNumPlayers]) //assign secret animal
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

