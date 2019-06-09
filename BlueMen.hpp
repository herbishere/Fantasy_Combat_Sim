/**************************************************************************************************
** Program name:Project 3 - FANTASY COMBAT GAME
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/05/2019
** Description: THIS IS THE HEADER FILE OF THE CHARACTER CLASS
**		ABSTRACTION OF:	A BlueMen Warrior
**		This program simulates combat between 2 characters. Characters include vampires,
**		barbarians, blue men, medusas, and harry potters. Combat consists of the sequence
**		of one character attacking another character who is defending, then the second
**		character attacking while the first character defends. The loser is determined
**		by the character who reaches 0 strength points first. This program utilizes a menu
**		to determine the fighters.
**		PURPOSE:	Hold all function specific for a Blue Men Warrior
**		HOW TO USE:	Create a BlueMen object using the constructor and apply applicable
**				functions from the Character base class, or functions for the
**				blue men.
**		SUMMARY:	The Blue Men has two Functions:
**				The attack function takes the attack roll as an argument and
**				returns the total attack damage.
**				The defense() includes the Blue Men's special move MOB with its 
**				additional functionality of reducing the number of defense die 
**				every 4 strengthVal lost.
**************************************************************************************************/
// BlueMen.hpp

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

// Global constants
const int BLUEMEN_ATT_SIDES = 10;
const int BLUEMEN_ATT_NUM = 2;
const int BLUEMEN_DEF_SIDES = 6;
const int BLUEMEN_DEF_NUM = 3;
const int BLUEMEN_ARMOR = 3;
const int BLUEMEN_STR = 12;
const int BLUEMAN_STR = 4;

#include "Character.hpp"

class BlueMen : public Character
{
	public:
		BlueMen();			// default constructor
		virtual int attack(int);
		virtual int defense(int,int);
};
#endif
