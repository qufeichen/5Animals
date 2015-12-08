//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include <iostream>
#include "Table.h"
#include "Player.h"

Table::Table (int numPlayers) : d_maxNumPlayers(numPlayers), currentNumPlayers(0), bearCount(0), deerCount(0), hareCount(0), mooseCount(0), wolfCount(0), occupied{}{
	
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
    //check if position is empty
	if(occupied[row][col] != 0)
	{
		cout<<"error: this index is already occupied"<<endl;
		return 0;
	}
    //check if atleast one neightbour matches
    int numMatches = checkNeighbours(newCard, row, col);
    if (numMatches == 0){
        cout<<"error: cannot place card here, no matching neighbours"<<endl;
        return 0;

    }

	tableArray[row][col] = newCard;
    occupied[row][col] = 1;
    
    addToAnimalCount(newCard);
	
    return numMatches;
    
    //TODO: implement in main
    //if return is 0, throw error,
}

int Table::checkNeighbours(shared_ptr<AnimalCard> card, int row, int col){
    
    int matches = 0;
    
    if( row > 0) {
        if((card->getAnimal(0, 0) == tableArray[row-1][col]->getAnimal(1, 0)) || (tableArray[row-1][col]->getAnimal(1, 0) == 'j' ) ){
            //check top left
            matches++;
        } else if( (card->getAnimal(0, 1) == tableArray[row-1][col]->getAnimal(1, 1) ) || (tableArray[row-1][col]->getAnimal(1, 1) == 'j' )){
            //check top right
            matches++;
        }
    }
    
    if( row < 103) {
        if( (card->getAnimal(1, 0) == tableArray[row+1][col]->getAnimal(0, 0)) || (tableArray[row+1][col]->getAnimal(0, 0) == 'j' ) ){
            //check bottom left
            matches++;
        } else if( (card->getAnimal(1, 1) == tableArray[row+1][col]->getAnimal(0, 1)) || (tableArray[row+1][col]->getAnimal(0, 1) == 'j' )){
            //check bottom right
            matches++;
        }
    }
    
    if( col > 0) {
        if( (card->getAnimal(0, 0) == tableArray[row][col-1]->getAnimal(0, 1)) || (tableArray[row][col-1]->getAnimal(0, 1) == 'j' )){
            //check top left
            matches++;
        } else if( (card->getAnimal(1, 0) == tableArray[row][col-1]->getAnimal(1, 1)) || (tableArray[row][col-1]->getAnimal(1, 1) == 'j' )){
            //check bottom left
            matches++;
        }
    }
    
    if(col<103) {
        if( (card->getAnimal(0, 1) == tableArray[row][col+1]->getAnimal(0, 0)) || (tableArray[row][col+1]->getAnimal(0, 0) == 'j' )){
            //check top right
            matches++;
    
        } else if( (card->getAnimal(1, 1) == tableArray[row][col+1]->getAnimal(1, 0)) || (tableArray[row][col+1]->getAnimal(1, 0) == 'j' )){
            //check bottom right
            matches++;
        }
    }
    
       return matches;
    
}
       


std::shared_ptr<AnimalCard> Table::pickAt(int row, int col){
    
	std::shared_ptr<AnimalCard> pickedCard = 0;
    //returns 0;
    
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
        //TODO: how to return nothing
	}
    
    if(pickedCard != 0){
        removeFromAnimalCount(pickedCard);
    }
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
    
    if( animal.compare("Bear")==0 ){
        if(bearCount >=12){
            win = true;
        }
    } else if(animal.compare("Dear")==0)  {
        if(deerCount >=12){
            win = true;
        }
    } else if(animal.compare("Hare")==0)  {
        if(hareCount >=12){
            win = true;
        }
    } else if(animal.compare("Moose")==0)  {
        if(mooseCount >=12){
            win = true;
        }
    } else if(animal.compare("Wolf")==0)  {
        if(wolfCount >=12){
            win = true;
        }
    }

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
	case 1 :
		secretAnimal = "Bear";
		break;
	case 2 :
		secretAnimal = "Wolf";
		break;
	case 3:
		secretAnimal = "Hare";
		break;
	case 4 :
		secretAnimal = "Moose";
		break;
	case 5 :
		secretAnimal = "Deer";
		break;
	}
	players.push_back( Player(name, secretAnimal) );
	++currentNumPlayers;
	return "player created successfully";
    
}

void Table::print(){
    
    for (int i=0; i<103; i++){
        for (int j=0; j<103; j++){
            if(occupied[i][j] == 1){
                tableArray[i][j]->printRow(EvenOdd::EVEN);
                cout<<" ";
            } else {
                cout<<"  ";
                cout<<" ";
            }
        }
        for (int k=0; k<103; k++){
            if(occupied[i][k] == 1){
                tableArray[i][k]->printRow(EvenOdd::ODD);
                cout<<" ";
            } else {
                cout<<"  ";
                cout<<" ";
            }
        }
        cout<<endl;
        
    }
    
}