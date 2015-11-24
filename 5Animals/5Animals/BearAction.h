//
//  BearAction.h
//  5Animals
//
//  Created by Qufei Chen on 2015-11-12.
//  Copyright © 2015 Qufei Chen. All rights reserved.
//

#ifndef BearAction_h
#define BearAction_h
#include "ActionCard.h"
#include <string>
#include <iostream>

using namespace std;

class BearAction : public ActionCard {
public:
    QueryResult query();
    void perform(Table &, Player* , QueryResult);

};
#endif /* BearAction_h */dsflkdsf
