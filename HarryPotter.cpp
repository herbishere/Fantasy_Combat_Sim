/**************************************************************************************************
** Program name:Project 3 - FANTASY COMBAT GAME
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/06/2019
** Description: THIS IS THE IMPLEMENTATION FILE OF THE HARRYPOTTER CLASS
**		This program simulates combat between 2 characters. Characters include vampires,
**		barbarians, blue men, medusas, and harry potters. Combat consists of the sequence
**		of one character attacking another character who is defending, then the second
**		character attacking while the first character defends. The loser is determined
**		by the character who reaches 0 strength points first. This program utilizes a menu
**		to determine the fighters.
**************************************************************************************************/
// HarryPotter.cpp

#include "HarryPotter.hpp"

/**************************************************************************************************
** Description:	HarryPotter();						 **PUBLIC::2019.02.08::HD**
**		This is the default constructor for the HarryPotter	 **************************
**		class
**************************************************************************************************/
HarryPotter::HarryPotter() :
 Character (	HARRYPOTTER_ATT_NUM, HARRYPOTTER_ATT_SIDES, HARRYPOTTER_DEF_NUM,
		HARRYPOTTER_DEF_SIDES, HARRYPOTTER_ARMOR, HARRYPOTTER_STR	)
{
	setFighterType(HARRYPOTTER);
	setSpecial(false);
	canRevive = true;
}


/**************************************************************************************************
** Description:	int attack(int);					 **PUBLIC::2019.02.08::HD**
**             	This function returns the randomly generated attack	 **************************
**		damage of the Character class.
**************************************************************************************************/
int HarryPotter::attack(int attackRoll)
{
	setSpecial(false);
	return attackRoll;
}

/**************************************************************************************************
** Description:	int defense(int,int);					 **PUBLIC::2019.02.08::HD**
**             	This function calculates and returns the total damage 	 **************************
**		done to the calling character based on the damage from the argument, the
**		character's defense roll, and the character's armorVal data member. This function
**		also has a special ability called HOGWARTS which revives Harry Potter to 20 
**		strength points if he hasn't revived once before. 
**************************************************************************************************/
int HarryPotter::defense(int attDmg, int defRoll)
{
	setSpecial(false);

	// calculate total damage
	int totalDmg =  attDmg - (defRoll + getArmorVal());

	// if damage was done, apply damage and return the total damage
	if (totalDmg > 0)
	{
		// apply the damage to the character
		setStrengthVal(getStrengthVal() - totalDmg);

		// SPECIAL ABILITY: HOGWARTS
		// if the strengthVal is 0 or below, check if the target can revive
		if (getStrengthVal() < 1)
		{
			if (canRevive == true)
			{
				setSpecial(true);
				setStrengthVal(HARRYPOTTER_REVIVE);
				canRevive = false;
			}
			else
			{
				setAlive(false);
			}
		}

		// return the total damage
		return totalDmg;
	}
	// otherwise, return no damage
	else
	{
		return 0;
	}
}

