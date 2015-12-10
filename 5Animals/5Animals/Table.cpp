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
    
	tableArray[52][52] = stack;
    occupied[52][52] = 1;
    
    //index for selecting secret animals
    secretCardIndex = new int[numPlayers];
	for(int i = 0; i<numPlayers; ++i)
	{ 
		secretCardIndex[i] = i+1;
	}
	random_shuffle(&secretCardIndex[0], &secretCardIndex[numPlayers-1]); //shuffle index
    
    //set limits of table to display
    //will display all cards in table + one empty row and col
    upperLeftRow = 51;
    upperLeftCol = 51;
    lowerRightRow = 53;
    lowerRightCol = 53;

}

int Table::addAt(std::shared_ptr<AnimalCard> newCard, int row, int col){
    
    //check if position on table is empty
	if(occupied[row][col] != 0)
	{
		cout<<"Error: this index is already occupied"<<endl;
		return 0;
	}
    
    //check if atleast one neighbour matches
    int numMatches = checkNeighbours(newCard, row, col);
    if (numMatches == 0){
        cout<<"Error: cannot place card here, no matching neighbours"<<endl;
        return 0;

    }

    //add card to table
	tableArray[row][col] = newCard;
    occupied[row][col] = 1;
    
    //update animal count
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
    
}

int Table::checkNeighbours(shared_ptr<AnimalCard> card, int row, int col){
    
    int matches = 0;
    
    if( (row > 0) && (occupied[row-1][col] != 0) ) {
        if((card->getAnimal(0, 0) == tableArray[row-1][col]->getAnimal(1, 0)) || (tableArray[row-1][col]->getAnimal(1, 0) == 'j' ) || (tableArray[row-1][col]->getAnimal(0, 0) == 'c' ) ){
            //check top left
            matches++;
        } else if( (card->getAnimal(0, 1) == tableArray[row-1][col]->getAnimal(1, 1) ) || (tableArray[row-1][col]->getAnimal(1, 1) == 'j' ) || (tableArray[row-1][col]->getAnimal(0, 0) == 'c' )){
            //check top right
            matches++;
        }
    }
    
    if( (row < 103) && (occupied[row+1][col] != 0)) {
        if( (card->getAnimal(1, 0) == tableArray[row+1][col]->getAnimal(0, 0)) || (tableArray[row+1][col]->getAnimal(0, 0) == 'j' ) || (tableArray[row+1][col]->getAnimal(0, 0) == 'c' )){
            //check bottom left
            matches++;
        } else if( (card->getAnimal(1, 1) == tableArray[row+1][col]->getAnimal(0, 1)) || (tableArray[row+1][col]->getAnimal(0, 1) == 'j' ) || (tableArray[row+1][col]->getAnimal(0, 0) == 'c' )){
            //check bottom right
            matches++;
        }
    }
    
    if( (col > 0) && (occupied[row][col-1] != 0)) {
        if( (card->getAnimal(0, 0) == tableArray[row][col-1]->getAnimal(0, 1)) || (tableArray[row][col-1]->getAnimal(0, 1) == 'j' ) || (tableArray[row][col-1]->getAnimal(0, 0) == 'c' )){
            //check top left
            matches++;
        } else if( (card->getAnimal(1, 0) == tableArray[row][col-1]->getAnimal(1, 1)) || (tableArray[row][col-1]->getAnimal(1, 1) == 'j' ) || (tableArray[row][col-1]->getAnimal(0, 0) == 'c' )){
            //check bottom left
            matches++;
        }
    }
    
    if((col<103) && (occupied[row][col+1] != 0)) {
        if( (card->getAnimal(0, 1) == tableArray[row][col+1]->getAnimal(0, 0)) || (tableArray[row][col+1]->getAnimal(0, 0) == 'j' ) || (tableArray[row][col+1]->getAnimal(0, 0) == 'c' )){
            //check top right
            matches++;
    
        } else if( (card->getAnimal(1, 1) == tableArray[row][col+1]->getAnimal(1, 0)) || (tableArray[row][col+1]->getAnimal(1, 0) == 'j' ) | (tableArray[row][col+1]->getAnimal(0, 0) == 'c' )){
            //check bottom right
            matches++;
        }
    }
    
       return matches;
    
}

std::shared_ptr<AnimalCard> Table::pickAt(int row, int col){
    
	std::shared_ptr<AnimalCard> pickedCard = 0;
    
	//remove card from the table
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
	} catch(exception& e){
		cout << "Illegal Pick";
	}
    
    if(pickedCard != 0){
        //update animal count
        removeFromAnimalCount(pickedCard);
    }
    
	return pickedCard;
    
}

void Table::addToAnimalCount(std::shared_ptr<AnimalCard> card){
        
    //get all unique animals from card
    vector<char> unique;
    
    //if animal does not yet exist in vector, add to vector
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
    
    //for all elements in vector, increment animal count
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
    
    //if animal does not yet exist in vector, add to vector
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
    
    //for all elements in vector, decrement animal count
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
    
    //check is any animal count has reached 12
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
    
    //assign each player a secret animal according to the shuffled index
	switch(secretCardIndex[currentNumPlayers])
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
    
    //print column index:
    cout<<"   ";
    for( int i = upperLeftCol; i<lowerRightCol+1; i++){
        cout<<i<<"  ";
    }
    cout<<endl;
    cout<<endl;
    
    
    for (int i=upperLeftRow; i<lowerRightRow+1; i++){
        
        //print row index
        cout<<i<<" ";
        
        //print first row of card
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
        //prints second row of card
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

Table& Table::operator+=(std::shared_ptr<ActionCard> newCard){
    
    //add card to startstack (bottom of startstack, animal count does not change)
    *stack+=newCard;
    return *this;
    
}

Table& Table::operator-=(std::shared_ptr<ActionCard> newCard){
    
    //add card to top of startstack
    
    //remove animal count of the current card on top of startstack
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
    //add animal count of new card added to top of startstack
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
    
    //add card to top of startstack
    *stack-=newCard;
    
    return *this;
    
}


ostream & operator <<(ostream& out , const Table& table){
    
    //write table to file
    
    out << table.bearCount;
    out << table.deerCount;
    out << table.hareCount;
    out << table.mooseCount;
    out << table.wolfCount;
    
    //save player info to file
    out << table.d_maxNumPlayers;
    out << table.currentNumPlayers;
    for (int x = 0; x < table.d_maxNumPlayers; x++){
        out << table.players[x];
    }

    out << table.stack;
    
    //save current cards on gameboard
    for(int i = 0; i < 103; i++){
        for(int j = 0; j < 103; j++){
            if(table.occupied[i][j] == 0){
                out<< 0;
            } else {
                out << 1;
                //type used to record what type of card was saved
                //used when retrieving info from file
                out<< table.tableArray[i][j]->type;
                out<< table.tableArray[i][j];
            }
        }
    }
    
    return out;
    
}

istream & operator >>(istream& in, Table& table){

    //retrieve previous game info from file
    
    in >> table.bearCount;
    in >> table.deerCount;
    in >> table.hareCount;
    in >> table.mooseCount;
    in >> table.wolfCount;
    in >> table.d_maxNumPlayers;
    in >> table.currentNumPlayers;
    
    //get player info and recreate players
    for (int i = 0; i<table.d_maxNumPlayers; i++){
        Player temp("","",i);
        in >> temp;
        table.players.push_back(temp);
    }
    
    in >> table.stack;
    
    //recreate board
    int x;
    for(int i = 0; i < 103; i++){
        for(int j = 0; j < 103; j++){
            cin>>x;
            table.occupied[i][j] = x;
            if(x == 1){
                
                //typeOfCard used to determine what type of card was saved
                int typeOfCard;
                in >> typeOfCard;
                std::shared_ptr<AnimalCard> card;
                
                if(typeOfCard == 0){
                   Joker *c = new Joker();
                    card.reset(c);
                } else if (typeOfCard == 1){
                    NoSplit *c = new NoSplit('b', Orientation::UP, EvenOdd::EVEN);
                    card.reset(c);
                } else if (typeOfCard == 2){
                    char tws1[2][2] = { {'b','b'},{'d','d'} };
                    TwoSplit *c = new TwoSplit(tws1, Orientation::UP, EvenOdd::EVEN);
                    card.reset(c);
                } else if (typeOfCard == 3){
                    char ths1[2][2] = { {'b','b'},{'d','h'} };
                    ThreeSplit *c = new ThreeSplit(ths1, Orientation::UP, EvenOdd::EVEN);
                    card.reset(c);
                } else {
                    char fs1[2][2] = { {'b','d'},{'h','m'} };
                    FourSplit *c = new FourSplit(fs1, Orientation::UP, EvenOdd::EVEN);
                    card.reset(c);
                }
                in >> *card ;
                table.tableArray[i][j] = card;
            }
        }
    }
    
    return in;
    
}