#include <iostream>
#include "Table.h"
Table::Table(){
	//add pointer to the center
	//only contains start card
	tableArray[52][52] = stack;
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
			tableArray[row][col] = 0;
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