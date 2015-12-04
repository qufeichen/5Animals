//
//  ActionCard.h
//  5Animals
//
//  Created by Qufei Chen on 2015-11-12.
//  Copyright © 2015 Qufei Chen. All rights reserved.
//

#include "StartCard.h"
#include "Player.h"
#include "QueryResult.h"
#include <iostream>

//NEED class Table or else there is conflict
class Table;

#ifndef ActionCard_h
#define ActionCard_h

class ActionCard:public StartCard{
    
public:
    virtual QueryResult query() = 0;
    virtual void perform( Table&, Player*, QueryResult) = 0;
    
};


#endif /* ActionCard_h */
