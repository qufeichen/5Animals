//5Animals
//CSI2372 Final Project
//Professor Jochen Lang
//Qufei Chen - 6771326
//Haoyuan Luo - 6838050
//Due Date: December 9th, 2015

====================================
Deviation in design of project :

-Players created inside class Table instead of main

Reasoning:

-We decided to place the creation of players in class Table so that the perform method of action cards would have access to the player list. Two of the action cards require information from another player, and we had two choices:

1. ask the player to input their player number
2. pass in the variable through one of the input parameters

The problem with method 1 is that there is no control over the player's input. There is no way to make sure that the player was inputing their own player number. We decided to place the player array inside table so that we could directly acess the player array (since a reference to table is passed into the perform method) without asking the player for input, which keeps the performed action of the action card true to our intent. 
