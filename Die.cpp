/**************************************************************************************************
** Program name:Lab 03 - War Game with Dice
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	1/27/2018
** Description:	THIS IS THE IMPLEMENTATION FILE FOR THE DIE CLASS
**		This program is a game where two players roll a dice and whoever rolls the higher
**		number earns a point. The player with the higher score after a user-defined number
**		of rounds wins.
**************************************************************************************************/
// Die.cpp
#include "Die.hpp"


/**************************************************************************************************
** Description: Die();							 **PUBLIC::2019.02.08::HD**
**		This is the default constructor for the Die class that	 **************************
**		seeds the random function
**************************************************************************************************/
Die::Die()
{
	// Seed random generator
	static bool seed = false;
	if (seed == false)
	{
		srand(time(0));
		seed = true;
	}
}


/**************************************************************************************************
** Description: Die(int);						 **PUBLIC::2019.01.23::HD**
**		This is a constructor for the Die class that sets the	 **************************
**		number of sides of the die. 
**		Takes an integer as arguments to be stored in the N data member. 
**************************************************************************************************/
Die::Die(int sideIn)
{
	this->N = sideIn;

	// Seed random generator
	static bool seed = false;
	if (seed == false)
	{
		srand(time(0));
		seed = true;
	}
}

/**************************************************************************************************
** Description: roll();							 **PUBLIC::2019.01.23::HD**
**              Returns a random integer between 1 and N.		 **************************
**************************************************************************************************/
int Die::roll()
{
	return rand() % N + 1;
}

/**************************************************************************************************
** Description:	getN();							 **PUBLIC::2019.01.24::HD**
**		Returns the N data member.				 **************************
**************************************************************************************************/

int Die::getN()
{
	return N;
}


/**************************************************************************************************
** Description:	setN();							 **PUBLIC::2019.01.24::HD**
**		sets the number of sides of the die via the N		 **************************
**************************************************************************************************/

void Die::setN(int N)
{
	this->N = N;
}
