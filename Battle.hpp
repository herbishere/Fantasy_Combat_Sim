/**************************************************************************************************
** Program name:Project 3 - FANTASY COMBAT GAME
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/09/2019
** Description: THIS IS THE HEADER FILE OF THE BATTLE CLASS
**		This program simulates combat between 2 characters. Characters include vampires,
**		barbarians, blue men, medusas, and harry potters. Combat consists of the sequence
**		of one character attacking another character who is defending, then the second
**		character attacking while the first character defends. The loser is determined
**		by the character who reaches 0 strength points first. This program utilizes a menu
**		to determine the fighters.
**		ABSTRACTION OF:	The battle between two characters
**		PURPOSE:	The Battle class encapsulates all the functions and variables
**				utilized within a battle between 2 character objects.
**		HOW TO USE:	Create 2 Character objects and use the constructor to create a 
**				Battle object then commence the battle using the commence function,
**				inputting each fighter as arguments for the battle.
**		SUMMARY:	This function creates a battle between 2 Character objects and,
**				once a character's strength value, reaches 0 or below, the
**				character with remaining strength is declared the winner.
**************************************************************************************************/
// Battle.hpp

#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <iostream>
#include "Die.hpp"
#include "Character.hpp"

using std::cin;
using std::cout;

class Battle
{
	private:
		int numRounds;
		Die coin;
		void fight(Character*, Character*);
		void displayFighterTypes(Character*, Character*);
		void drawBorder();
		void dispFighterInfo(Character*);
	public:
		Battle();
		void commence(Character*, Character*);
};
#endif
