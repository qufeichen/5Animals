//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

#include "ActionCard.h"
#include "Table.h"
#include "Player.h"
#include <string>
#include <iostream>

#ifndef BearAction_h
#define BearAction_h

using namespace std;


class BearAction : public ActionCard {

private:
    char cardMatrix[2][2];
    
public:
    BearAction();
    QueryResult query();
    void perform(Table &, Player* , QueryResult);
    string action;
    void printRow(EvenOdd);
    char getAnimal();

};

#endif