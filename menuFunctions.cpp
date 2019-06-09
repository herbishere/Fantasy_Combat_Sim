/**************************************************************************************************
** Program name:Lab 05 - Recursive Functions
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	02/10/2018
** Description:	THIS IS THE IMPLEMENTATION FILE OF THE MENU FUNCTIONS
**		This program displays a menu for users to decide whether they want to enter a
**		string and print it backwards, enter a series of numbers and calculate the sum, or
**		calculate the trianglular number of an integer they enter. All the functions
**		utilize recursion.
**************************************************************************************************/
// menuFunctions.cpp

#include "menuFunctions.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////
///	== UTILITY FUNCTIONS == UTILITY FUNCTIONS == UTILITY FUNCTIONS == UTILITY FUNCTIONS ==	///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description:	void printBorder();					 **PUBLIC::2019.02.04::HD**
**		Prints a border for display functions			 **************************
**************************************************************************************************/
void printBorder()
{
	cout << "\n\n";
	cout << "===============================================================================";
	cout << "\n\n";
}

/**************************************************************************************************
** Description:	void cleanInput();					 **PUBLIC::2019.02.04::HD**
**		Combines the cin.ignore and cin.clear for input		 **************************
**		validation.
**************************************************************************************************/
void cleanInput()
{
	cin.clear();
	cin.ignore(IGNORE_NUMF,'\n');
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///	== DISPLAY FUNCTIONS ==	DISPLAY FUNCTIONS == DISPLAY FUNCTIONS == DISPLAY FUNCTIONS ==	///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description:	void dispTitle();					 **PUBLIC::2019.02.10::HD**
**		This function shows the title of the program.	 	 **************************
**************************************************************************************************/
void dispTitle()
{
	printBorder();
	cout << "==== CS162 ==== Program 03 - Fantasy Combat Game  ==== Herbert Diaz ====\n";
	cout << "[   This program simulates combat between two fantasy characters. To   ]\n";
	cout << "[ begin, please choose 2 characters whom you wish to see enter combat. ]\n";
	cout << "[ After combat has started, press enter to continue to the next round  ]\n";
	cout << "[                   until a winner is determined.                      ]\n";
	cout << "========================================================================\n";
}


/**************************************************************************************************
** Description:	void dispSelection(int);				 **PUBLIC::2019.02.10::HD**
**		This function takes an integer to determine which 	 **************************
**		fighter is being chosen and shows the user their options of characters
**************************************************************************************************/
void dispSelection(int playerNumber)
{
	cout << "\n";
	cout << "Please Select a Character for Fighter " << playerNumber << ":\n";
	cout << "	[1] VAMPIRE\n";
	cout << "	[2] BARBARIAN\n";
	cout << "	[3] BLUE MEN\n";
	cout << "	[4] MEDUSA\n";
	cout << "	[5] HARRY POTTER\n";
}

/**************************************************************************************************
** Description:	void dispReplay();					 **PUBLIC::2019.02.10::HD**
**		This function asks the user if they wish to play again.	 **************************
**************************************************************************************************/
void dispReplay()
{
	cout << "\n";
	cout << "Would You Like to Play Again?\n";
	cout << "	[1] YES\n";
	cout << "	[2] NO\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////
///== INPUT VALIDATION FUNCTIONS == INPUT VALIDATION FUNCTIONS == INPUT VALIDATION FUNCTIONS ==	///
///////////////////////////////////////////////////////////////////////////////////////////////////

/**************************************************************************************************
** Description:	int validateMenu();					 **PUBLIC::2019.02.10::HD**
**		This function gets and validates the input for the	 **************************
**		selection menu and returns the validated input.
**************************************************************************************************/
int validateSelection()
{
	// Get Input
	int choice;
	cin >> choice;

	// Ask Until Input Valid
	while (!cin || choice < MIN_MENU || choice > MAX_MENU)
	{
		cleanInput();
		cout << "\n<!>INPUT INVALID: PLEASE ENTER INTEGER BETWEEN " << MIN_MENU;
		cout << " and " << MAX_MENU << "<!>\n";
		cin >> choice;
	}

	return choice;
}

/**************************************************************************************************
** Description:	int validateReplay();					 **PUBLIC::2019.02.10::HD**
**		This function gets and validates the input for the	 **************************
**		replay query and returns the validated value
**************************************************************************************************/
int validateReplay()
{
	// Get Input
	int choice;
	cin >> choice;

	// Ask Until Input Valid
	while (!cin || choice < MIN_MENU || choice > MAX_REPLAY)
	{
		cleanInput();
		cout << "\n<!>INPUT INVALID: PLEASE ENTER INTEGER BETWEEN " << MIN_MENU;
		cout << " and " << MAX_REPLAY << "<!>\n";
		cin >> choice;
	}

	return choice;
}


