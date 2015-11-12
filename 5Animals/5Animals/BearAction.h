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
#include<iostream>


class BearAction : public ActionCard {
    
public:
    string animal = "bear";
    string action = "bear action";
    QueryResult query(){
        Quer
    }
    void perform( Table&, Player*, QyeryResult ){
        cout<<"this action is "<<action;
    }
    
};

#endif /* BearAction_h */
