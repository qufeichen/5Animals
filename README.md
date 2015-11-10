# 5Animals
Animal version of 7Dragons
Created for CSI2372 final project
------------------------------------------------------------------------------------------------------
GAME REQUIREMENTS

-2 to 5 players
-5 secret animal cards
-50 animal cards (10 each)
    matched with horizontal or vertical neighbour
    if 2 to 4 matches exist, player draws 1 to 3 extra cards
-joker: any card
-startCard: matches any card if not covered, first card placed on table at start of game
-Action cards: 15
(bottom of stack performed next)
    wolf: pick up card from table, put into deck
    bear: switch hands with another player
    moose: rotate secret animals (1 to 2, 2 to 3)
    hare: move card to another location on table (where valid)
    deer: select a player to switch goals with

EveryTurn:
-player draws card from deck of animal cards
-player places a card on the table (animal card must be connected to others, action card on top/bottom of stack)

------------------------------------------------------------------------------------------------------
DESIGN

Classes: 

Table
-wrapper around a four-connected graph implemented with a fixed size array of pointers
Deck
-extend std::vector
Hand
-std::hand 
StartStack 
-aggregate std::deque

AnimalCard (abstract)
subclasses:
-NoSplit
-SplitTwo
-SplitThree
-SplitFour

Joker
StartCard

ActionCard (abstract)
subclasses:
-BearAction
-DeerAction
-HareAction
-MooseAction
-WolfAction
(work with pointers) std::shared

Template for Deck (parametric in the type of card)
-use with class AnimalCard

Randomize deck:
standard arlgorithm std::shuffle

Pause functionality:
-game needs to be saved and reloaded from file
-stream insertion and extraction operator


Exceptions with downcasts: distinguish between actionCard and other AnimalCard
-IllegalPlacement if player attempts to place clard illegally

Print cards and deck:
-traverse table row by row
-each two print first row of each card



