//
//  WolfAction.h
//  5Animals
//
//  Created by Qufei Chen on 2015-11-12.
//  Copyright © 2015 Qufei Chen. All rights reserved.
//
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
