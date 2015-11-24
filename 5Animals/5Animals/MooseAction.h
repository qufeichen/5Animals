//
//  MooseAction.h
//  5Animals
//
//  Created by Qufei Chen on 2015-11-12.
//  Copyright © 2015 Qufei Chen. All rights reserved.
//

#ifndef MooseAction_h
#define MooseAction_h
#include "ActionCard.h"
#include "Table.h"
#include "Player.h"
#include "QueryResult.h"
#include <string>
#include <iostream>

using namespace std;

class MooseAction : public ActionCard {
public:
    QueryResult query();
    void perform(Table &, Player* , QueryResult);

};
#endif /* MooseAction_h */
