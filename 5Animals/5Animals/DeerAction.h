//
//  DeerAction.h
//  5Animals
//
//  Created by Qufei Chen on 2015-11-12.
//  Copyright © 2015 Qufei Chen. All rights reserved.
//

#ifndef DeerAction_h
#define DeerAction_h

#include "ActionCard.h"
#include "Table.h"
#include "Player.h"
#include "QueryResult.h"
#include <string>
#include <iostream>

using namespace std;

class DeerAction : public ActionCard {
    
public:
    QueryResult query();
    void perform(Table &, Player* , QueryResult);

};
#endif /* DeerAction_h */
