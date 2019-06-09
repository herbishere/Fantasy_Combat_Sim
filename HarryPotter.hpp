/**************************************************************************************************
** Program name:Project 3 - FANTASY COMBAT GAME
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/09/2019
** Description: THIS IS THE HEADER FILE OF THE CHARACTER CLASS
**		This program simulates combat between 2 characters. Characters include vampires,
**		barbarians, blue men, medusas, and harry potters. Combat consists of the sequence
**		of one character attacking another character who is defending, then the second
**		character attacking while the first character defends. The loser is determined
**		by the character who reaches 0 strength points first. This program utilizes a menu
**		to determine the fighters.
**		ABSTRACTION OF:	A HarryPotter Warrior
**		PURPOSE:	Hold all function specific for a HarryPotter Warrior
**		HOW TO USE:	Create a Barbrian object using the constructor and apply applicable
**				functions from the Character base class, or functions for the
**				harrypotter.
**		SUMMARY:	Harry Potter has Two Functions:
**				The attack function takes the attack roll as an argument and
**				returns the total damage done.
**				The defense function takes the total attack damage and the defense
**				roll to determine the actual damage done. This damage done is
**				applied to the defender and returned. The defense function has a 
**				special ability called HOGWARTS where Harry Potter can revive if
**				the character dies and hasn't revived already.
**************************************************************************************************/
// HarryPotter.hpp

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

// Global constants
const int HARRYPOTTER_ATT_SIDES = 6;
const int HARRYPOTTER_ATT_NUM = 2;
const int HARRYPOTTER_DEF_SIDES = 6;
const int HARRYPOTTER_DEF_NUM = 2;
const int HARRYPOTTER_ARMOR = 0;
const int HARRYPOTTER_STR = 10;
const int HARRYPOTTER_REVIVE = 20;

#include "Character.hpp"

class HarryPotter : public Character
{
	private:
		bool canRevive;			// determines whether harrypotter can revive
	public:
		HarryPotter();			// default constructor
		virtual int attack(int);
		virtual int defense(int,int);
};
#endif
