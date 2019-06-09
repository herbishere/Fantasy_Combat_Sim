/**************************************************************************************************
** Program name:Project 3 - FANTASY COMBAT GAME
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/06/2019
** Description: THIS IS THE IMPLEMENTATION FILE OF THE BLUEMEN CLASS
**		This program simulates combat between 2 characters. Characters include vampires,
**		barbarians, blue men, medusas, and harry potters. Combat consists of the sequence
**		of one character attacking another character who is defending, then the second
**		character attacking while the first character defends. The loser is determined
**		by the character who reaches 0 strength points first. This program utilizes a menu
**		to determine the fighters.
**************************************************************************************************/
// BlueMen.cpp

#include "BlueMen.hpp"

/**************************************************************************************************
** Description:	BlueMen();						 **PUBLIC::2019.02.08::HD**
**		This is the default constructor for the BlueMen class	 **************************
**************************************************************************************************/
BlueMen::BlueMen() : Character (	BLUEMEN_ATT_NUM, BLUEMEN_ATT_SIDES, BLUEMEN_DEF_NUM,
					BLUEMEN_DEF_SIDES, BLUEMEN_ARMOR, BLUEMEN_STR	)
{
	setFighterType(BLUEMEN);
	setSpecial(false);
}

/**************************************************************************************************
** Description:	int attack(int);					 **PUBLIC::2019.02.08::HD**
**             	This function returns the randomly generated attack	 **************************
**		damage of the BlueMen class.
**************************************************************************************************/
int BlueMen::attack(int attackRoll)
{
	setSpecial(false);
	return attackRoll;
}

/**************************************************************************************************
** Description:	int defense(int,int);					 **PUBLIC::2019.02.08::HD**
**             	This function calculates and returns the total damage 	 **************************
**		done to the calling character based on the damage from the argument, the
**		character's defense roll, and the character's armorVal data member. This function
**		includes the special move, MOB, where the number of defense die of the Blue Men are
**		reduced for every 4 strengthVal lost.
**************************************************************************************************/
int BlueMen::defense(int attDmg, int defRoll)
{
	setSpecial(false);

	// calculate total damage
	int totalDmg =  attDmg - (defRoll + getArmorVal());

	// if damage was done, apply damage and return the total damage
	if (totalDmg > 0)
	{
		// apply the damage to the character
		setStrengthVal(getStrengthVal() - totalDmg);

		// apply the special effect: MOB
		// calculate lost health
		int lostStrength = BLUEMEN_STR - getStrengthVal();
		// hold the total dice when at max health
		int totalDice = BLUEMEN_DEF_NUM;
		// subtract 1 from the total dice for every BLUEMAN_STR strength lost
		while (lostStrength > 3)
		{
			lostStrength -= BLUEMAN_STR;
			totalDice--;
			setSpecial(true);
		}
		// set number of defense die to the amount according to strengthVal
		setNumDef(totalDice);

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

