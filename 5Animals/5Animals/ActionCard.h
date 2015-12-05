//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include "StartCard.h"
#include "Player.h"
#include "QueryResult.h"
#include <iostream>

class Table;

#ifndef ActionCard_h
#define ActionCard_h


class ActionCard:public StartCard{
    
public:
    virtual QueryResult query() = 0;
    virtual void perform( Table&, Player*, QueryResult) = 0;
    
};

#endif