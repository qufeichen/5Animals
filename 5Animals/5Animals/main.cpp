//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Robert Luo -
//Due Date: December 9th, 2015

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "AnimalCard.h"
#include "ActionCard.h"
#include "StartCard.h"
#include "StartStack.h"
#include "Deck.h"
#include "Table.h"
#include "Hand.h"
#include "AnimalCardFactory.h"

using namespace std;

int main( int argc, char *args[] ) {
    
    cout<<"Welcome to 5Animals!"<<endl<<endl<<"Would you like to start a new game, or load a previous game?"<< endl <<"Enter 0 for a new game, and any other number to load a previous game."<<endl;
    int newOrSave;
    cin>>newOrSave;
    bool startNewGame = true;
    
    //declare variables
    bool playerHasWon = false;
    string winner;
    Hand *currentHand;
    int numPlayers;
    AnimalCardFactory *factory = new AnimalCardFactory();

    //load from file
    if(newOrSave != 0){
        startNewGame = false;
        
        ifstream infile;
        infile.open(".../5Animals.txt");
        
        //check for error
        if(infile.fail()){
            cerr << "There was an error reading from file. You do not have a game saved!"<<endl;
            //no file found, start new game
            startNewGame = true;
            
        } else {
        
            infile >> numPlayers;
//        
//        if(isAction == true)
//        infile >> ActionCard c;
//        else
//        infile >> AnimalCard c;
        
        //table
        Table board = Table(numPlayers);
        
        //implement this in table
        //infile >> board;
        
        infile.close();
        /* variables to save
         int numPlayers;
         Hand currentHand;
         
         Table tableArray (cards that have been played and position)
         
         AnimalCardFactory (deck with cards left)
         Player vector
         Player (name, secret animal, hand, cards in hand)
         Startstack( cards in startstack)
         
         */
        }
        

    }

        //start a new game
    
    //if(startNewGame){
        //enter number of players
        cout<<"You are starting a new game!"<<endl;
        cout<<"Please enter the number of players:"<<endl;
        cin>> numPlayers;
        
        //check that number of players is valid (between 1 and 5 inclusive)
        while( ! ((1<numPlayers) && (numPlayers<6)) )
        {   cout<<"Invalid input! Please enter a number between 2 and 5 (inclusive):"<<endl;
            cin>> numPlayers;
        }
        
        //create game
        Table board = Table(numPlayers);
        
        //create deck
        //Deck::template deck<AnimalCard> = factory->getDeck();
        Deck<AnimalCard> deck = factory->getDeck();
    
        //create players
        string name;
        for(int i=0;i<numPlayers;i++){
            cout<<"Please enter player "<<(i+1)<<"'s name:"<<endl;
            cin>>name;
            board.createPlayer(name);
            cout<<"Your secret animal is "+board.getPlayer(i)->getSecretAnimal()<<endl;
            cout<<endl;
        }
    
        //draw three cards per player
        Hand *tempHand;
        for(int i = 0; i<numPlayers; i++){
            tempHand = board.getPlayer(i)->getHand();
            tempHand->operator+=(deck.draw());
            tempHand->operator+=(deck.draw());
            tempHand->operator+=(deck.draw());

        }
  //  }
  
    while(!playerHasWon){
        
        //prompt to save game
        //TODO: should we give save option every time a player starts a turn?
        cout<<"Would you like to save the game now? Enter 0 for yes, and any other number for no: ";
        int save;
        cin>>save;
        
        if(save == 0){
            //TODO: save to file
            
            ofstream outfile;
            outfile.open(".../5Animals.txt");
            
            outfile << numPlayers << endl;
            
            //save players
            for(int i = 0; i<numPlayers; i++){
                outfile << board.getPlayer(i);
                }
            
            //table
            outfile<< board;
            
            //TODO: deck
            
            
            outfile.close();
            //end program
            exit(1);
        }
        
        
        //loop for each player
        for( int i = 0; i<numPlayers; i++) {
            
            cout<<endl<<"====================================="<<endl;
            cout<<"Player "+board.getPlayer(i)->getName()+"'s turn: "<<endl;
            cout<<endl;
            //display table
            cout<<"Game Board:"<<endl;
            board.print();
            
            //draw card for player
            currentHand = board.getPlayer(i)->getHand();
            currentHand->operator+=(deck.draw());

            //print hand
            cout<<"Here is your hand:"<<endl;
            currentHand->print();
            
            cout<<"Please choose a card to play:?"<<endl;
            int card;
            cin>>card;
            while (card<0 || card > board.getPlayer(i)->getHand()->noCards()-1){
                cout<<"Thats not a valid card! Please choose a card from you hand:"<<endl;
                //TEST
                cout<<"numCards in hand: "<<board.getPlayer(i)->getHand()->noCards()<<endl;
                cin>>card;
            }
            
            cout<<"Please choose a position on the board to play the card:"<<endl;
            int row;
            int col;
            cout<<"Enter a row: ";
            cin>>row;
            while (row<0 || row > 102){
                cout<<"Thats not a valid row! Please choose a row position on the board:";
                cin>>row;
            }
            cout<<endl;
            
            cout<<"Enter a column: ";
            cin>>col;
            while (col<0 || col > 102){
                cout<<"Thats not a valid row! Please choose a column position on the board:";
                cin>>col;
            }
            cout<<endl;
            
            //if placing an action card
            if( row == 52 && col == 52){
                
                //Should use exceptions to check for null pointer?
//                try{
//                    shared_ptr<ActionCard> cardToPlay =  dynamic_pointer_cast<ActionCard>(currentHand[card]);
//                    if( cardToPlay == nullptr ){
//                        throw "exception";
//                    }
//                } catch (exception e){
//                    cout<<"You cannot place a non-action card on the startstack. Please start your turn again.";
//                    i--;
//                }
                
                //dynamic cast - will return null pointer if casting fails
               
                shared_ptr<ActionCard> cardToPlay =  dynamic_pointer_cast<ActionCard>(currentHand->operator[](card));
                if( cardToPlay != nullptr){
                    
                    //get card
                    //shared_ptr<ActionCard> cardToPlay =  dynamic_pointer_cast<ActionCard>(currentHand[card]);
                    //remove card from hand
                    currentHand->operator-=(currentHand->operator[](card));
                    
                    int top;
                    cout<<"Are you placing the card on top of the stack? Press 1 for yes, and any other key for no"<<endl;
                    cin>>top;
                    
                    if(top == 1){
                
                        board += cardToPlay;
                    } else {
                        //perform action
                        board -= cardToPlay;
                        QueryResult qr = cardToPlay->query();
                        cardToPlay->perform(board, board.getPlayer(i), qr);
                    }

                }
                
                //if not an action card
                else {
                    
                    //You cannot place a non-action card on the stack
                    cout<<"You cannot place a non-action card on the stack"<<endl;
                    //TODO:
                    //return to start of loop so player can enter another location to place card?
                    cout<<"Please start your turn again."<<endl;
                    i--;
                    //should an exception be called here?
                }
            
            } else {
                //if not an action card
                
                //get card
                shared_ptr<AnimalCard> cardToPlay = currentHand->operator[](card);
                
                //remove card from hand
                currentHand->operator-=(currentHand->operator[](card));
                
                //place card on board
                int numMatches = board.addAt(cardToPlay, row, col);
                
                if(numMatches == 0){
                    //card not placed successfully on table, error is thrown
                    //let player play turn again
                    cout<<"Restart your turn.";
                    i--;
                    
                } else {
                    
                    //draw additional cards
                    cout<<"Since your card made "<<numMatches<<" matches, you will draw "<<numMatches<<" additional cards.";
                    for(int i=0; i<numMatches; i++){
                        shared_ptr<AnimalCard> cardDrawn = deck.draw();
                        currentHand->operator+=(cardDrawn);
                        
                    }
                    //print new hand
                    cout<<"Your new hand:"<<endl;
                    currentHand->print();
                    
                }
                
            }
            
            //check if player has won (check ALL PLAYERS)
            string secretAni;
            for(int x = 0; x<numPlayers; x++){
                secretAni = board.getPlayer(x)->getSecretAnimal();
                playerHasWon = board.win(secretAni);
                //get name of winner
                if(playerHasWon){
                    winner = board.getPlayer(x)->getName();
                }
            }
            
        }
        
    }
    
    cout<<"Congratulations "+winner<<", you have won the game!"<<endl;
    
    //Algorithm from project
    //
    //    While no Player has won
    //    if pause save game to file and exit
    //      For each Player
    //        Display Table
    //        Player draws top card from Deck Display Player
    //        do
    //            Ask Player input to choose card Play a card
    //            Place card in Table
    //            while card is not placed legally
    //                if ActionCard was played and added on the bottom, perform the action for all players
    //                    check if the player has won
    //                        // Note player may win even at another player's turn end
    //
    
    
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
    return 0;
    
}
