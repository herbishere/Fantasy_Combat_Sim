/**************************************************************************************************
** Program name:Project 3 - Fantasy Combat Game
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	02/05/2019
** Description:	THIS IS THE MAIN FUNCTION OF PROJECT 3 - FANTASY COMBAT GAME
**		This program simulates combat between 2 characters. Characters include vampires,
**		barbarians, blue men, medusas, and harry potters. Combat consists of the sequence
**		of one character attacking another character who is defending, then the second
**		character attacking while the first character defends. The loser is determined
**		by the character who reaches 0 strength points first. This program utilizes a menu
**		to determine the fighters.
**		TO RUN: In terminal run the makefile using the "make" command and run the
**		executable file "main".
**************************************************************************************************/
// main.cpp

#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "Battle.hpp"
#include "menuFunctions.hpp"

int main()
{
	// create battle object
	Battle fight;
	bool play = true;

	while (play == true)
	{
		// display title
		dispTitle();
		// display selection menu for fighter 1
		dispSelection(1);
		// get and validate selection
		int choice = validateSelection();
		// create fighter 1 based on selection
		Character* fighter1;
		if (choice == 1)
		{
			fighter1 = new Vampire;
		}
		else if (choice == 2)
		{
			fighter1 = new Barbarian;
		}
		else if (choice == 3)
		{
			fighter1 = new BlueMen;
		}
		else if (choice == 4)
		{
			fighter1 = new Medusa;
		}
		else if (choice == 5)
		{
			fighter1 = new HarryPotter;
		}

		printBorder();	// seperate menus
	
		// display selection menu for fighter 2
		dispSelection(2);
		// get and validate selection
		cleanInput();
		choice = validateSelection();
		// create fighter 2 based on selection
		Character* fighter2;
		if (choice == 1)
		{
			fighter2 = new Vampire;
		}
		else if (choice == 2)
		{
			fighter2 = new Barbarian;
		}
		else if (choice == 3)
		{
			fighter2 = new BlueMen;
		}
		else if (choice == 4)
		{
			fighter2 = new Medusa;
		}
		else if (choice == 5)
		{
			fighter2 = new HarryPotter;
		}

		printBorder();	// seperate sections

		cleanInput();

		// commence battle
		fight.commence(fighter1, fighter2);

		printBorder();	// seperate sections

		// ask if the user wants to play again
		dispReplay();
		// get and validate user's choice
		choice = validateReplay();

		if (choice == 1)
		{
			play = true;
			cleanInput();
		}
		else if (choice == 2)
		{
			play = false;
		}
		// delete Character pointers
		delete fighter1;
		delete fighter2;
	}

	return 0;
}
