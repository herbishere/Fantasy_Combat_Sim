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
**		ABSTRACTION OF:	A Barbarian Warrior
**		PURPOSE:	Hold all function specific for a Barbarian Warrior
**		HOW TO USE:	Create a Barbrian object using the constructor and apply applicable
**				functions from the Character base class.
**		SUMMARY:	The barbarian has two functions:
**				The attack function takes the attack roll as an argument and
**				returns the total attack damage.
**				The defense function takes the total attack damage and the defense
**				roll to determine the actual damage done. This damage done is
**				applied to the defender and returned.
**************************************************************************************************/
// Barbarian.hpp

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

// Global constants
const int BARBARIAN_ATT_SIDES = 6;
const int BARBARIAN_ATT_NUM = 2;
const int BARBARIAN_DEF_SIDES = 6;
const int BARBARIAN_DEF_NUM = 2;
const int BARBARIAN_ARMOR = 0;
const int BARBARIAN_STR = 12;

#include "Character.hpp"

class Barbarian : public Character
{
	public:
		Barbarian();			// default constructor
		virtual int attack(int);
		virtual int defense(int, int);
};
#endif
