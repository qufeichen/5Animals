//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include "ActionCard.h"
#include "Table.h"
#include "Player.h"
#include "QueryResult.h"
#include <string>
#include <iostream>

#ifndef DeerAction_h
#define DeerAction_h

using namespace std;


class DeerAction : public ActionCard {
    
private:
    char cardMatrix[2][2];
    
public:
    int type;
    DeerAction();
    QueryResult query();
    void perform(Table &, Player* , QueryResult);
    void printRow(EvenOdd);
    char getAnimal();
    
};

#endif