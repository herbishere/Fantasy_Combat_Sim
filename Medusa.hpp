/**************************************************************************************************
** Program name:Project 3 - FANTASY COMBAT GAME
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/05/2019
** Description: THIS IS THE HEADER FILE OF THE CHARACTER CLASS
**		This program simulates combat between 2 characters. Characters include vampires,
**		barbarians, blue men, medusas, and harry potters. Combat consists of the sequence
**		of one character attacking another character who is defending, then the second
**		character attacking while the first character defends. The loser is determined
**		by the character who reaches 0 strength points first. This program utilizes a menu
**		to determine the fighters.
**		ABSTRACTION OF:	A Medusa Warrior
**		PURPOSE:	Hold all function specific for a Medusa Warrior
**		HOW TO USE:	Create a Barbrian object using the constructor and apply applicable
**				functions from the Character base class, or functions for the
**				medusa.
**		SUMMARY:	The Medusa class has two functions:
**				The attack function takes the attack roll as an argument and
**				returns the total attack damage. The attack function includes the
**				additional functionality of doing 999 dmg when the Medusa rolls a
**				12. This is Medusa's special ablilty: GLARE
**				The defense function takes the total attack damage and the defense
**				roll to determine the actual damage done. This damage done is
**				applied to the defender and returned.
**************************************************************************************************/
// Medusa.hpp

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

// Global constants
const int MEDUSA_ATT_SIDES = 6;
const int MEDUSA_ATT_NUM = 2;
const int MEDUSA_DEF_SIDES = 6;
const int MEDUSA_DEF_NUM = 1;
const int MEDUSA_ARMOR = 3;
const int MEDUSA_STR = 8;

#include "Character.hpp"

class Medusa : public Character
{
	public:
		Medusa();			// default constructor
		virtual int attack(int);
		virtual int defense(int, int);
};
#endif
