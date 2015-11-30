
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
//std::shared_ptr<AnimalCard>pickAt(int row, int col){
//
//}
//bool Table::win(std::string& animal){
//
//}