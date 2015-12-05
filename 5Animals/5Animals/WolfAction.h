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

#ifndef WolfAction_h
#define WolfAction_h

using namespace std;

class WolfAction : public ActionCard {
    
public:
    QueryResult query();
    void perform(Table &, Player* , QueryResult);
    
};

#endif /* WolfAction_h */
