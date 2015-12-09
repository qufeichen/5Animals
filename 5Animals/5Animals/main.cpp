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
    
    cout<<"Welcome to 5Animals!"<<endl<<endl;
    cout<<"Would you like to start a new game, or load a previous game?"<< endl;
    cout<<"Enter 1 for a new game, or any other number to load a previous game."<<endl;
    
    int newOrSave;
    cin>>newOrSave;
    bool startNewGame = true;
    
    //declare variables
    bool playerHasWon = false;
    string winner;
    Hand *currentHand;
    int numPlayers;

    //load from file
    if(newOrSave != 1){
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
        AnimalCardFactory *factory = new AnimalCardFactory();
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
        
        //loop for each player
        for( int i = 0; i<numPlayers; i++) {
            
            cout<<endl<<"====================================="<<endl;
            cout<<"Player "+board.getPlayer(i)->getName()+"'s turn: "<<endl;
            cout<<endl;
            //display table
            cout<<"Game Board:"<<endl;
            cout<<endl;
            board.print();
            
            //draw card for player
            cout<<"You draw a card from the deck!"<<endl;
            currentHand = board.getPlayer(i)->getHand();
            currentHand->operator+=(deck.draw());

            //print hand
            cout<<"Here is your hand:"<<endl;
            currentHand->print();
            cout<<endl;
            
            cout<<"Please choose a card to play:"<<endl;
            int card;
            cin>>card;
            while (card<0 || card > board.getPlayer(i)->getHand()->noCards()-1){
                cout<<"Thats not a valid card! Please choose a card from you hand:"<<endl;
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
                cout<<"Thats not a valid column! Please choose a column position on the board:";
                cin>>col;
            }
            cout<<endl;
            
            //if placing an on the stack
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
                    cout<<"Are you placing the card on top of the stack?"<<endl;
                    cout<<"Press 1 for yes, and any other number for no: "<<endl;
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
                    break;
                }
            
            } else {
                //if not placing on the stack
                
                if(shared_ptr<ActionCard> cardToPlay = dynamic_pointer_cast<ActionCard>(currentHand->operator[](card))){
                    cout<<"You can only place action cards on the StartStack!"<<endl;
                    cout<<"Start your turn over again."<<endl;
                    break;
                }
                
                //get card
                shared_ptr<AnimalCard> cardToPlay = currentHand->operator[](card);
                
                //remove card from hand
                currentHand->operator-=(cardToPlay);
                
                //place card on board
                int numMatches = board.addAt(cardToPlay, row, col);
                
                if(numMatches == 0){
                    //card not placed successfully on table, error is thrown
                    //let player play turn again
                    cout<<"Restart your turn.";
                    break;
                    
                } else {
                    
                    //draw additional cards
                    cout<<"Since your card made "<<numMatches<<" match(es), you will draw "<<numMatches<<" additional cards."<<endl;
                    for(int i=0; i<numMatches; i++){
                        shared_ptr<AnimalCard> cardDrawn = deck.draw();
                        currentHand->operator+=(cardDrawn);
                        
                }
                    //print new hand
                    cout<<"Your new hand:"<<endl;
                    currentHand->print();
                    cout<<endl;
                    
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
            
            //prompt to save game
            //TODO: should we give save option every time a player starts a turn?
            cout<<"Would you like to save the game now?"<<endl;
            cout<<"Enter 1 for yes, or any other number for no: ";
            int save;
            cin>>save;
            
            if(save == 1){
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

            
        }
        
    }
    
    cout<<"Congratulations "+winner<<", you have won the game!"<<endl;
    
    return 0;
    
}
