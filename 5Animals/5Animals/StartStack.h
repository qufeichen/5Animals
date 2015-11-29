//
// 
//

#include <string>
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
#include "ActionCard.h"
#ifndef STARTSTACK_H
#define STARTSTACK_H
class StartStack:AnimalCard{
public:

private:
	StartStack();
	StartStack& operator+=(std::shared_ptr<ActionCard>);
	StartStack& operator-=(std::shared_ptr<ActionCard>);
	std::shared_ptr<ActionCard> getStartCard();
};

#endif