/**************************************************************************************************
** Program name:Project 3 - FANTASY COMBAT GAME
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/08/2019
** Description: THIS IS THE HEADER FILE OF THE CHARACTER CLASS
**		This program simulates combat between 2 characters. Characters include vampires,
**		barbarians, blue men, medusas, and harry potters. Combat consists of the sequence
**		of one character attacking another character who is defending, then the second
**		character attacking while the first character defends. The loser is determined
**		by the character who reaches 0 strength points first. This program utilizes a menu
**		to determine the fighters.
**		ABSTRACTION OF:	The base class for all subsequent character classes
**		PURPOSE:	The Character base class holds all the member variables and
**				functions that are utilized by the Derived classes
**		HOW TO USE:	Use Character as a base class and override virutal functions to
**				create own functions.
**		SUMMARY:	The constructor takes 6 variables to set the data members.
**				The attack function rely on rolling the die, which roll the attack
**				die a number of times depending the number of attack die.
**				The defense function relies on the defense roll, which is
**				determined similarly to the attack roll, as well as the armor value
**				data member. The attack and defense functions are virtual and can
**				be overridden by derived classes.
**				Get functions return specific data members.
**				Set functions set specific data members.
**************************************************************************************************/
// Character.hpp

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Die.hpp"

enum Fighter {ERROR, VAMPIRE, BARBARIAN, BLUEMEN, MEDUSA, HARRYPOTTER};

class Character
{
	private:
		int numAtt;		// the number of attack die
		Die attackDie;
		int numDef;		// the number of defense die
		Die defenseDie;
		int armorVal;
		int strengthVal;
		bool alive;
		bool special;
		Fighter type;
	public:
		// the constructor
		Character(int, int, int, int, int, int);

		// attack functions
		virtual int attack(int) = 0;
		int rollAttack();

		// defense functions
		virtual int defense(int,int) = 0;
		int rollDefense();

		// get functions
		int getNumAtt();
		int getSidesAtt();
		int getNumDef();
		int getSidesDef();
		int getArmorVal();
		int getStrengthVal();
		bool isAlive();
		bool getSpecial();
		Fighter getFighterType();

		// set functions
		void setStrengthVal(int);
		void setAlive(bool);
		void setNumDef(int);
		void setFighterType(Fighter);
		void setSpecial(bool);
};
#endif
