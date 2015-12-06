//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include <iostream>
#include "Table.h"
#include "Player.h"

Table::Table (int numPlayers) : d_maxNumPlayers(numPlayers), currentNumPlayers(0), bearCount(0), deerCount(0), hareCount(0), mooseCount(0), wolfCount(0){
	
    //only contains start card
	tableArray[52][52] = stack;
    occupied[52][52] = 1;
    
    //index for selecting secret cards
    secretCardIndex = new int[numPlayers];
	for(int i = 0; i<numPlayers; ++i)
	{ 
		secretCardIndex[i] = i+1;
	}
	random_shuffle(&secretCardIndex[0], &secretCardIndex[numPlayers-1]); //shuffle index

}

int Table::addAt(std::shared_ptr<AnimalCard> newCard, int row, int col){
    
	//check if able to put in card
	if(occupied[row][col] != 0)
	{
		cout<<"error: this index is already occupied"<<endl;
		return 1; 
	}

	tableArray[row][col] = newCard;
    occupied[row][col] = 1;
    
    addToAnimalCount(newCard);
	
    return 0;
    
}


std::shared_ptr<AnimalCard> Table::pickAt(int row, int col){
    
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
            occupied[row][col] = 0;
		}
	}
	catch(exception& e){
		cout << "Illegal Pick";
	}
    
    removeFromAnimalCount(pickedCard);
	return pickedCard;
    
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

void Table::addToAnimalCount(std::shared_ptr<AnimalCard> card){
        
    //get all unique animals from card
    char unique[4] = {};
    int index = 0;
    bool exists;
        
    for (int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            exists = false;
                
            for(int k=0; k<4; k++) {
                if(card->getAnimal(i, j) == unique[k]){
                    exists = true;
                    break;
                }
                if(exists == false){
                    unique[index] = card->getAnimal(i, j);
                    index++;
                }
            }
                
        }
    }
        
    for(int l = 0; l<index; l++){
        switch (unique[l]) {
            case 'b':
                bearCount++;
                break;
            case 'd':
                deerCount++;
                break;
            case 'h':
                hareCount++;
                break;
            case 'm':
                mooseCount++;
                break;
            case 'w':
                wolfCount++;
                break;
            default:
                break;
        }
    }
    
}

void Table::removeFromAnimalCount(std::shared_ptr<AnimalCard> card){
    
    //get all unique animals from card
    char unique[4] = {};
    int index = 0;
    bool exists;
    
    for (int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            exists = false;
            
            for(int k=0; k<4; k++) {
                if(card->getAnimal(i, j) == unique[k]){
                    exists = true;
                    break;
                }
                if(exists == false){
                    unique[index] = card->getAnimal(i, j);
                    index++;
                }
            }
            
        }
    }
    
    for(int l = 0; l<index; l++){
        switch (unique[l]) {
            case 'b':
                bearCount--;
                break;
            case 'd':
                deerCount--;
                break;
            case 'h':
                hareCount--;
                break;
            case 'm':
                mooseCount--;
                break;
            case 'w':
                wolfCount--;
                break;
            default:
                break;
        }
    }
    
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
    
	return d_maxNumPlayers;
    
}

Player* Table::getPlayer(string playerName) {
    
    Player* player = 0;
        for(int i = 0; i<d_maxNumPlayers;i++)
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
    
	if(currentNumPlayers >= d_maxNumPlayers)
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

