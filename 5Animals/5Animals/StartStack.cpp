#include <string>
#include <string>
#include <cstdlib>
#include <iostream>
#include <memory>
#include "StartStack.h"
#include <deque>

StartStack::StartStack(){
	stack.push_back(start);
}

//StartStack& StartStack::operator+=(std::shared_ptr<ActionCard> card){
//	//top is back
//	stack.push_back(card);
//	//change animal behaviour
//
//}
//StartStack& StartStack::operator-=(std::shared_ptr<ActionCard> card){
//	//bottom is front
//	stack.push_front(card);
//	//change animal behaviours
//}
//std::shared_ptr<ActionCard> getStartCard(){
//	//which is start card
//}