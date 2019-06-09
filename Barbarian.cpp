/**************************************************************************************************
** Program name:Project 3 - FANTASY COMBAT GAME
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/06/2019
** Description: THIS IS THE IMPLEMENTATION FILE OF THE BARBARIAN CLASS
**		This program simulates combat between 2 characters. Characters include vampires,
**		barbarians, blue men, medusas, and harry potters. Combat consists of the sequence
**		of one character attacking another character who is defending, then the second
**		character attacking while the first character defends. The loser is determined
**		by the character who reaches 0 strength points first. This program utilizes a menu
**		to determine the fighters.
**************************************************************************************************/
// Barbarian.cpp

#include "Barbarian.hpp"

/**************************************************************************************************
** Description:	Barbarian();						 **PUBLIC::2019.02.08::HD**
**		This is the default constructor for the Barbarian class	 **************************
**************************************************************************************************/
Barbarian::Barbarian() : Character (	BARBARIAN_ATT_NUM, BARBARIAN_ATT_SIDES, BARBARIAN_DEF_NUM,
					BARBARIAN_DEF_SIDES, BARBARIAN_ARMOR, BARBARIAN_STR	)
{
	setFighterType(BARBARIAN);
	setSpecial(false);
}

/**************************************************************************************************
** Description:	int attack(int);					 **PUBLIC::2019.02.08::HD**
**             	This function returns the randomly generated attack	 **************************
**		damage of the Barbarian class.
**************************************************************************************************/
int Barbarian::attack(int attackRoll)
{
	setSpecial(false);
	return attackRoll;
}

/**************************************************************************************************
** Description:	int defense(int,int);					 **PUBLIC::2019.02.08::HD**
**             	This function calculates and returns the total damage 	 **************************
**		done to the calling character based on the damage from the argument, the
**		character's defense roll, and the character's armorVal data member.
**************************************************************************************************/
int Barbarian::defense(int attDmg, int defRoll)
{
	setSpecial(false);

	// calculate total damage
	int totalDmg =  attDmg - (defRoll + getArmorVal());

	// if damage was done, apply damage and return the total damage
	if (totalDmg > 0)
	{
		// apply the damage to the character
		setStrengthVal(getStrengthVal() - totalDmg);

		// if the strengthVal is 0 or below, set the target as dead
		if (getStrengthVal() < 1)
		{
			setAlive(false);
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

