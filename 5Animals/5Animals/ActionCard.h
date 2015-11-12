//
//  ActionCard.h
//  5Animals
//
//  Created by Qufei Chen on 2015-11-12.
//  Copyright © 2015 Qufei Chen. All rights reserved.
//

#ifndef ActionCard_h
#define ActionCard_h
#include "StartCard.h"
#include <iostream>


class ActionCard: public StartCard {
    
public:
    virtual QueryResult query();
    virtual void perform( Table&, Player*, QueryResult);
    //ActionCard(string action, string animal);
};


#endif /* ActionCard_h */
