
#include <iostream>
#include <string>

#include "NoSplit.h"
#include "TwoSplit.h"
#include "FourSplit.h"
#include "ThreeSplit.h"
#include "BearAction.h"
#include "DeerAction.h"
#include "MooseAction.h"
#include "Joker.h"
#include "Deck.h"
#include "Game.h"

using namespace std;


int main()
{
    
    cout<<"Welcome to 5Animals!"<<endl;
    
    //IF NEW GAME:
    //enter number of players
    cout<<"Please enter the number of players:"<<endl;
    int numPlayers;
    cin>> numPlayers;
    
    //check that number of players is valid (between 1 and 5 inclusive)
    while( ! ((1<numPlayers) && (numPlayers<6)) )
    {   cout<<"Invalid input! Please enter a number between 2 and 5 (inclusive):"<<endl;
        cin>> numPlayers;
    }
    
    //create game
    Game game(numPlayers);
    
    //create players
    string name;
    for(int i=0;i<numPlayers;i++){
        cout<<"Please enter player 1's name"<<endl;
        cin>>name;
        game.table->createPlayer(name);
    }
    
    //OR
    //LOAD FROM FILE
    //TODO: implement load from file
    
    //initialize deck
    //draw three cards for hand of each player
    
    
    
    //create cards here?
    NoSplit no('c');
    EvenOdd even = EVEN;
    no.printRow(cout, even);
    TwoSplit two(2);
    ThreeSplit three(25);
    FourSplit four(51);
    BearAction bear;
    DeerAction deer;
    MooseAction moose;
    Joker joker;
    Deck<MooseAction> deck;
    StartCard start;
    
    
    
    
    
	std::cin.get();
	return 0;
    
    
}