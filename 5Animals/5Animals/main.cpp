//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
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
    
    //variables used to check for winner
    bool playerHasWon = false;
    string winner;
    
    //game variables
    Hand *currentHand;
    int numPlayers = 0;
    Table *board = 0;
    Deck<AnimalCard> deck;


    //load game

    //player chooses to load a game from file
    if(newOrSave != 1){
        
        startNewGame = false;
        
        //read files in start game
        ifstream infile;
        infile.open(".../5Animals.txt");
        
        //check if a saved game exists
        if(infile.fail()){
            
            cerr << "There was an error reading from file. You do not have a game saved!"<<endl;
            //no saved game found, start new game
            startNewGame = true;
            infile.close();
            
        } else {
            
            //save number of players
            infile >> numPlayers;
            
            //create gameboard, and retrieve information from saved game
            board = new Table(numPlayers);
            infile >> *board;
            
            //retrieve deck
            int decksize = 0;
            infile >> decksize;
            for(int i = 0; i<decksize; i++){
                shared_ptr<AnimalCard> card;
                infile >> card;
                deck.push_back(card);
            }
        
        infile.close();
            
        }
        
    }

    
    //new game
    
    //if player choses to start a new game, or if player does not have a game saved
    if(startNewGame){
    
        //enter number of players
        cout<<"You are starting a new game!"<<endl;
        cout<<"Please enter the number of players:"<<endl;
        cin>> numPlayers;
        
        //check that number of players is valid (between 1 and 5 inclusive)
        while( ! ((1<numPlayers) && (numPlayers<6)) )
        {
            cout<<"Invalid input! Please enter a number between 2 and 5 (inclusive):"<<endl;
            cin>> numPlayers;
            
        }
        
        //create gameboard
        board = new Table(numPlayers);
        
        //create deck
        AnimalCardFactory *factory = new AnimalCardFactory();
        deck = factory->getDeck();
    
        //create players
        string name;
        for(int i=0;i<numPlayers;i++){
            
            cout<<"Please enter player "<<(i+1)<<"'s name:"<<endl;
            cin>>name;
            board->createPlayer(name);
            cout<<"Your secret animal is "+board->getPlayer(i)->getSecretAnimal()<<endl;
            cout<<endl;
            
        }
    
        //draw three cards per player
        Hand *tempHand;
        for(int i = 0; i<numPlayers; i++){
            
            tempHand = board->getPlayer(i)->getHand();
            tempHand->operator+=(deck.draw());
            tempHand->operator+=(deck.draw());
            tempHand->operator+=(deck.draw());

        }
    }
  
    
    
    //play the game
    
    while(!playerHasWon){
        
        //loop for each player
        for( int i = 0; i<numPlayers; i++) {
            
            cout<<endl<<"====================================="<<endl;
            cout<<"Player "+board->getPlayer(i)->getName()+"'s turn: "<<endl;
            cout<<endl;
            
            //display gameboard
            cout<<"Game Board:"<<endl;
            cout<<endl;
            board->print();
            
            //draw a card for player
            cout<<"You draw a card from the deck!"<<endl;
            currentHand = board->getPlayer(i)->getHand();
            currentHand->operator+=(deck.draw());

            //print hand
            cout<<"Here is your hand:"<<endl;
            currentHand->print();
            cout<<endl;
            
            //player chooses a card
            cout<<"Please choose a card to play:"<<endl;
            int card;
            cin>>card;
            //ensure that a valid card is chosen from hand
            while (card<0 || card > board->getPlayer(i)->getHand()->noCards()-1){
                cout<<"Thats not a valid card! Please choose a card from you hand:"<<endl;
                cin>>card;
            }
            
            //player choses position to play card
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
            
            //if placing card on the stack
            if( row == 52 && col == 52){
               
                //check if card is an action card
                shared_ptr<ActionCard> cardToPlay =  dynamic_pointer_cast<ActionCard>(currentHand->operator[](card));
                
                if( cardToPlay != nullptr){
                    
                    currentHand->operator-=(currentHand->operator[](card));
                    
                    int top;
                    cout<<"Are you placing the card on top of the stack?"<<endl;
                    cout<<"Press 1 for yes, and any other number for no: "<<endl;
                    cin>>top;
                    
                    if(top == 1){
                
                        board->operator+=(cardToPlay);
                        
                    } else {
                        
                        //perform action
                        board->operator-=(cardToPlay);
                        QueryResult qr = cardToPlay->query();
                        cardToPlay->perform(*board, board->getPlayer(i), qr);
                        
                    }

                }
                
                //if card is not an action card
                else {
                    
                    cout<<"You cannot place a non-action card on the stack"<<endl;
                    cout<<"Please start your turn again."<<endl;
                    break;
                    
                }
            
                
            //if not placing on the stack
            } else {
                
                //check that card is not an action card
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
                //returns 0 if there are no matches, and card cannot be placed at this spot
                int numMatches = board->addAt(cardToPlay, row, col);
                
                if(numMatches == 0){

                    cout<<"Restart your turn.";
                    break;
                    
                } else {
                    
                    //draw additional cards
                    cout<<"Since your card made "<<numMatches<<" match(es), you will draw "<<numMatches<<" additional cards."<<endl;
                    for(int i=0; i<numMatches; i++){
                        
                        shared_ptr<AnimalCard> cardDrawn = deck.draw();
                        currentHand->operator+=(cardDrawn);
                        
                    }
                    
                    //print new hand after additional cards are drawn
                    cout<<"Your new hand:"<<endl;
                    currentHand->print();
                    cout<<endl;
                    
                }
                
            }
            
            // end of player turn
            
            
            //check if a player has won (checks ALL PLAYERS)
            string secretAni;
            
            for(int x = 0; x<numPlayers; x++){
                
                secretAni = board->getPlayer(x)->getSecretAnimal();
                playerHasWon = board->win(secretAni);
                
                if(playerHasWon){
                    
                    //get name of winner
                    winner = board->getPlayer(x)->getName();
                    
                }
                
            }
            
            //check if there are still cards remaining in deck
            if(deck.size() ==0){
                
                cout<<"There are no more cards in the deck!"<<endl;
                cout<<"Since no player has achieved 12 matches on the table, this game end on a tie."<<endl;
                cout<<"Thank you for playing! Goodbye!"<<endl;
                exit(1);
                
            }
            
            //prompt to save game
            cout<<"Would you like to save and exit the game now?"<<endl;
            cout<<"Enter 1 for yes, or any other number for no: ";
            int save;
            cin>>save;
            
            if(save == 1){
                
                ofstream outfile;
                outfile.open(".../5Animals.txt");
                
                //save number of players
                outfile << numPlayers << endl;
                
                //save table
                outfile<< board;
                
                //save deck
                outfile << deck.size();
                for(int i = 0; i<deck.size(); i++){
                    outfile << deck.draw();
                }
                
                outfile.close();
                
                //end program after save
                cout<<"Thank you for playing!"<<endl;
                cout<<"Goodbye!"<<endl;
                
                exit(1);
            }
            
        }
        
        //if no player has won:
        //player number is incremented, and the next the next player goes
        
    }
    
    
    // player wins, breaks out of game loop
    
    cout<<"Congratulations "+winner<<", you have won the game!"<<endl;
    cout<<"Thank you for playing! Goodbye!"<<endl;
    
    return 0;
    
}
