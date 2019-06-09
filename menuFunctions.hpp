/**************************************************************************************************
** Program name:Program 03 - Fantasy Combat Game
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	02/10/2018
** Description:	THIS IS THE HEADER FILE OF THE MENU FUNCTIONS
**		This program simulates combat between 2 characters. Characters include vampires,
**		barbarians, blue men, medusas, and harry potters. Combat consists of the sequence
**		of one character attacking another character who is defending, then the second
**		character attacking while the first character defends. The loser is determined
**		by the character who reaches 0 strength points first. This program utilizes a menu
**		to determine the fighters.
**		These menu functions include character selection displays, replay displays, and
**		getting, validating, and returning the user's input for their choices.
**************************************************************************************************/
// menuFunctions.hpp

#ifndef MENUFUNCTIONS_HPP
#define MENUFUNCTIONS_HPP

#include <iostream>

using std::cout;
using std::cin;

// Global Constants
const int MIN_MENU 	= 1;
const int MAX_MENU 	= 5;
const int MAX_REPLAY	= 2;
const int IGNORE_NUMF 	= 10000;

// Helper Functions
void cleanInput();
void printBorder();

// Display Functions/Queries

void dispTitle();		// Shows the Program Title
void dispSelection(int);	// Shows the Main Menu
void dispReplay();		// Queries the user if they want to replay the game

// Get Functions/Input Validation Functions

int validateSelection();
int validateReplay();

#endif
