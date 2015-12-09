//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include <iostream>
#include "Table.h"
#include "Player.h"
#include "StartStack.h"
#include "NoSplit.h"
#include "TwoSplit.h"
#include "ThreeSplit.h"
#include "FourSplit.h"
#include "Joker.h"

Table::Table (int numPlayers) : d_maxNumPlayers(numPlayers), currentNumPlayers(0), bearCount(0), deerCount(0), hareCount(0), mooseCount(0), wolfCount(0), stack(new StartStack()), occupied(){
	
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
    //TODO: this is not shuffling :(
    
    //set limits of table to display
    upperLeftRow = 51;
    upperLeftCol = 51;
    lowerRightRow = 53;
    lowerRightCol = 53;

}

int Table::addAt(std::shared_ptr<AnimalCard> newCard, int row, int col){
    
	//check if able to put in card
    //check if position is empty
	if(occupied[row][col] != 0)
	{
		cout<<"Error: this index is already occupied"<<endl;
		return 0;
	}
    //check if atleast one neightbour matches
    int numMatches = checkNeighbours(newCard, row, col);
    if (numMatches == 0){
        cout<<"Error: cannot place card here, no matching neighbours"<<endl;
        return 0;

    }

	tableArray[row][col] = newCard;
    occupied[row][col] = 1;
    
    addToAnimalCount(newCard);
    
    //change limits of table to display
    if((upperLeftRow != 0) && (row == upperLeftRow)){
        upperLeftRow = row-1;
    } else if((lowerRightRow != 103) && (row == lowerRightRow)){
        lowerRightRow = row+1;
    }
    if((upperLeftCol != 0) && (col == upperLeftCol)){
        upperLeftCol = col-1;
    } else if((lowerRightCol != 103) && (col == lowerRightCol)){
        lowerRightCol = col+1;
    }
	
    return numMatches;
    
    //TODO: implement in main
    //if return is 0, throw error,
}

int Table::checkNeighbours(shared_ptr<AnimalCard> card, int row, int col){
    
    int matches = 0;
    
    if( (row > 0) && (occupied[row-1][col] != 0) ) {
        if((card->getAnimal(0, 0) == tableArray[row-1][col]->getAnimal(1, 0)) || (tableArray[row-1][col]->getAnimal(1, 0) == 'j' ) || (tableArray[row-1][col]->getAnimal(1, 0) == 'c' ) ){
            //check top left
            matches++;
        } else if( (card->getAnimal(0, 1) == tableArray[row-1][col]->getAnimal(1, 1) ) || (tableArray[row-1][col]->getAnimal(1, 1) == 'j' ) || (tableArray[row-1][col]->getAnimal(1, 1) == 'c' )){
            //check top right
            matches++;
        }
    }
    
    if( (row < 103) && (occupied[row+1][col] != 0)) {
        if( (card->getAnimal(1, 0) == tableArray[row+1][col]->getAnimal(0, 0)) || (tableArray[row+1][col]->getAnimal(0, 0) == 'j' ) || (tableArray[row+1][col]->getAnimal(0, 0) == 'c' )){
            //check bottom left
            matches++;
        } else if( (card->getAnimal(1, 1) == tableArray[row+1][col]->getAnimal(0, 1)) || (tableArray[row+1][col]->getAnimal(0, 1) == 'j' ) || (tableArray[row+1][col]->getAnimal(0, 1) == 'c' )){
            //check bottom right
            matches++;
        }
    }
    
    if( (col > 0) && (occupied[row][col-1] != 0)) {
        if( (card->getAnimal(0, 0) == tableArray[row][col-1]->getAnimal(0, 1)) || (tableArray[row][col-1]->getAnimal(0, 1) == 'j' ) || (tableArray[row][col-1]->getAnimal(0, 1) == 'c' )){
            //check top left
            matches++;
        } else if( (card->getAnimal(1, 0) == tableArray[row][col-1]->getAnimal(1, 1)) || (tableArray[row][col-1]->getAnimal(1, 1) == 'j' ) || (tableArray[row][col-1]->getAnimal(1, 1) == 'c' )){
            //check bottom left
            matches++;
        }
    }
    
    if((col<103) && (occupied[row][col+1] != 0)) {
        if( (card->getAnimal(0, 1) == tableArray[row][col+1]->getAnimal(0, 0)) || (tableArray[row][col+1]->getAnimal(0, 0) == 'j' ) || (tableArray[row][col+1]->getAnimal(0, 0) == 'c' )){
            //check top right
            matches++;
    
        } else if( (card->getAnimal(1, 1) == tableArray[row][col+1]->getAnimal(1, 0)) || (tableArray[row][col+1]->getAnimal(1, 0) == 'j' ) | (tableArray[row][col+1]->getAnimal(1, 0) == 'c' )){
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
        
		if((row == 52 && col == 52) || (occupied[row][col] == 0))
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
    
    //add to top of stack
    
    //change animal count
    char remove = stack->getTopAnimal();
    switch (remove) {
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
    char newcardAnimal = newCard->getAnimal();
    switch (newcardAnimal) {
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
    
    
    
    *stack-=newCard;
    return *this;
    
}

void Table::addToAnimalCount(std::shared_ptr<AnimalCard> card){
        
    //get all unique animals from card
    vector<char> unique;
    
    if( find(unique.begin(), unique.end(), card->getAnimal(0, 0)) == unique.end() ){
        unique.push_back(card->getAnimal(0, 0));
    }
    if( find(unique.begin(), unique.end(), card->getAnimal(0, 1)) == unique.end() ){
        unique.push_back(card->getAnimal(0, 1));
    }
    if( find(unique.begin(), unique.end(), card->getAnimal(1, 0)) == unique.end() ){
        unique.push_back(card->getAnimal(1, 0));
    }
    if( find(unique.begin(), unique.end(), card->getAnimal(1, 1)) == unique.end() ){
        unique.push_back(card->getAnimal(1, 1));
    }
        
    for(size_t l = 0; l<unique.size(); l++){
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
    vector<char> unique;
    
    if( find(unique.begin(), unique.end(), card->getAnimal(0, 0)) == unique.end() ){
        unique.push_back(card->getAnimal(0, 0));
    }
    if( find(unique.begin(), unique.end(), card->getAnimal(0, 1)) == unique.end() ){
        unique.push_back(card->getAnimal(0, 1));
    }
    if( find(unique.begin(), unique.end(), card->getAnimal(1, 0)) == unique.end() ){
        unique.push_back(card->getAnimal(1, 0));
    }
    if( find(unique.begin(), unique.end(), card->getAnimal(1, 1)) == unique.end() ){
        unique.push_back(card->getAnimal(1, 1));
    }
    
    for(size_t l = 0; l<unique.size(); l++){
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
    
	bool win = false;
    
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
	players.push_back( Player(name, secretAnimal, currentNumPlayers) );
	++currentNumPlayers;
	return "player created successfully";
    
}

void Table::print(){
    
    //print index:
    cout<<"   ";
    for( int i = upperLeftCol; i<lowerRightCol+1; i++){
        cout<<i<<"  ";
    }
    cout<<endl;
    cout<<endl;
    
    
    for (int i=upperLeftRow; i<lowerRightRow+1; i++){
        cout<<i<<" ";
        
        for (int j=upperLeftCol; j<lowerRightCol; j++){
            if(occupied[i][j] == 1){
                tableArray[i][j]->printRow(EvenOdd::EVEN);
                cout<<"  ";
            } else {
                cout<<"  ";
                cout<<"  ";
            }
        }
        cout<<endl;
        cout<<"   ";
        for (int k=upperLeftCol; k<lowerRightCol; k++){
            if(occupied[i][k] == 1){
                tableArray[i][k]->printRow(EvenOdd::ODD);
                cout<<"  ";
            } else {
                cout<<"  ";
                cout<<"  ";
            }
        }
        cout<<endl;
        
    }
    
}

ostream & operator <<(ostream& out , const Table& table){
    
    out << table.bearCount;
    out << table.deerCount;
    out << table.hareCount;
    out << table.mooseCount;
    out << table.wolfCount;
    
    out << table.d_maxNumPlayers;
    out << table.currentNumPlayers;
    for (int x = 0; x < table.d_maxNumPlayers; x++){
        out << table.players[x];
    }

    out << table.stack;
    
    for(int i = 0; i < 103; i++){
        for(int j = 0; j < 103; j++){
            if(table.occupied[i][j] == 0){
                out<< 0;
            } else {
                out << 1;
                out<< table.tableArray[i][j]->type;
                out<< table.tableArray[i][j];
            }
        }
    }
    
    
    return out;
    
}

istream & operator >>(istream& in, Table& table){

    in >> table.bearCount;
    in >> table.deerCount;
    in >> table.hareCount;
    in >> table.mooseCount;
    in >> table.wolfCount;
    in >> table.d_maxNumPlayers;
    in >> table.currentNumPlayers;
    
    for (int i = 0; i<table.d_maxNumPlayers; i++){
        Player temp("","",i);
        in >> temp;
        table.players.push_back(temp);
    }
    
    in >> table.stack;
    
    
    int x;
    for(int i = 0; i < 103; i++){
        for(int j = 0; j < 103; j++){
            cin>>x;
            table.occupied[i][j] = x;
            if(x == 1){
                int typeOfCard;
                in >> typeOfCard;
                std::shared_ptr<AnimalCard> card;
                
                if(typeOfCard == 0){
                    std::shared_ptr<AnimalCard> card(new Joker());
                } else if (typeOfCard == 1){
                    std::shared_ptr<AnimalCard> card( new NoSplit('b', Orientation::UP, EvenOdd::EVEN) );
                } else if (typeOfCard == 2){
                    char tws1[2][2] = { {'b','b'},{'d','d'} };
                    std::shared_ptr<AnimalCard> card( new TwoSplit(tws1, Orientation::UP, EvenOdd::EVEN) );
                } else if (typeOfCard == 3){
                    char ths1[2][2] = { {'b','b'},{'d','h'} };
                    std::shared_ptr<AnimalCard> card( new ThreeSplit(ths1, Orientation::UP, EvenOdd::EVEN) );
                } else {
                    char fs1[2][2] = { {'b','d'},{'h','m'} };
                    std::shared_ptr<AnimalCard> card( new FourSplit(fs1, Orientation::UP, EvenOdd::EVEN) );
                }
                
                in >> card ;
                table.tableArray[i][j] = card;
            }
        }
    }
    
    return in;
}