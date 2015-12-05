
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
#include "AnimalCardFactory.h"

using namespace std;

int main( int narg, char *args[] ) {
  
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
    
    //create deck
     Deck<std::shared_ptr<AnimalCard> > deck;
    
    //create players
    string name;
    for(int i=0;i<numPlayers;i++){
        cout<<"Please enter player 1's name"<<endl;
        cin>>name;
        //game.table->createPlayer(name);
    }

	//testing animal card factory
	AnimalCardFactory factory;
	factory.getFactory();

    //OR
    //LOAD FROM FILE
    //TODO: implement load from file
    
    //initialize deck
    //draw three cards for hand of each player

    
    
    // TODO: create cards here?
    //    NoSplit no('c');
    //    EvenOdd even = EVEN;
    //    no.printRow(cout, even);
    //    TwoSplit two(2);
    //    ThreeSplit three(25);
    //    FourSplit four(51);
    //    BearAction bear;
    //    DeerAction deer;
    //    MooseAction moose;
    //    Joker joker;
    //    Deck<MooseAction> deck;
    //    StartCard start;
    
    
    
    /*
     TODO: FIX THIS:
     Full of errors
     will not build/compile
    
     
  if (narg > 1) {
    // open file and check for errors
    ifstream ifs; // associated with file 
    ifs >> deck;
    ifs >> tab;
    ifs >> noPlayers;
    players = new Player*[noPlayers];
    for ( int pl=0; pl<noPlayers; ++pl ) {
      players[pl] = new Player();
      ifs >> players[pl]; // will load hand of player
    }
  } else {
    AnimalCardFactory* factory = AnimalCardFactory::get();
    deck = factory->getDeck();
    cout << "Number of Players?" << endl;
    cin >> noPlayers;
    players = new Player*[noPlayers];
    Hand  = deck.getHand();
    for ( int pl=0; pl<noPlayers; ++pl ) {
      cout << "Name of player " << pl << "?" << endl;
      std::string name; 
      cin >> name;
      players[pl] = new Player(name); 
      for (int i=0; i<3; ++i ) {
	players[pl].hd += deck.draw(); 
      }
    }
  }

  bool won{false};
  
  while (!won) {
    for ( int pl=0; pl<noPlayers; ++pl ) {
      cout << tab;
      players[pl] += deck.draw(); 
      cout << players[pl];
      bool next = true;
      do {
	int cardNo;
	cout << "Which card to play? (0 to " 
	     << players[pl].hd.noCards() << ")? "; 
	cin >> cardNo;
	std::shared_ptr<AnimalCard> ac = players[pl].hd[cardNo];
	players[pl].hd -= ac;
	// try downcasting to action card
	std::shared_ptr<ActionCard> action = 
	  dynamic_pointer_cast<ActionCard>(ac);
	if ( action != nullptr ) {
	  // on success
	  cout << "Top (1) or bottom (0) of start stack? " << endl;
	  int tmp;
	  cin >> tmp;
	  if (tmp>0)
	    tab += action;
	  else {
	    tab -= action;
	    // Perform action
	    QueryResult q = action.query(); 
	    action.perfom( tab, players, q ); 
	  }
	} else {
	  int row, col;
	  cout << "Where should the card go? (row column)" << endl;
	  cin >> row >> col;
	  int extraCard = tab.addAt( ac, row, col );
	  if ( extraCard == 0 ) {
	    // illegal card
	    next = false;
	  } else {
	    for ( int c=1;c<extraCard;++c ) {
	      players[pl] += deck.draw(); 
	    }
	  }
	}
	if ( next ) {
	  for ( int pl=0; pl<noPlayers; ++pl ) {
	    tab.win( players[pl].getSecretAnimal() );
	  }
	}
      }
    }

  }
     
     
     */

}
