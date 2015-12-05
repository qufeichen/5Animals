//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "ActionCard.h"
#include "Table.h"
#include "Player.h"
#include "QueryResult.h"
#include <string>
#include <iostream>

#ifndef HareAction_h
#define HareAction_h

using namespace std;

class HareAction : public ActionCard {
    
public:
    QueryResult query();
    void perform(Table &, Player* , QueryResult);

};
#endif /* HareAction_h */
