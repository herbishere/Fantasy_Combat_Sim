/**************************************************************************************************
** Program name:Project 3 - FANTASY COMBAT GAME
** Author:	Herbert Diaz <diazh@oregonstate.edu>
** Date:	2/09/2019
** Description: THIS IS THE IMPLEMENTATION FILE OF THE BATTLE CLASS
**		This program simulates combat between 2 characters. Characters include vampires,
**		barbarians, blue men, medusas, and harry potters. Combat consists of the sequence
**		of one character attacking another character who is defending, then the second
**		character attacking while the first character defends. The loser is determined
**		by the character who reaches 0 strength points first. This program utilizes a menu
**		to determine the fighters.
**************************************************************************************************/
// Character.cpp

#include "Battle.hpp"

/**************************************************************************************************
** Description: Battle(Character*, Character*);				 **PUBLIC::2019.02.09::HD**
**		This is the default constructor for the battle class	 **************************
**************************************************************************************************/
Battle::Battle()
{
	numRounds=0;
	coin.setN(2);	// 2 sides to a coin
}


/**************************************************************************************************
** Description: void commence(Character*, Character*);		 	 **PUBLIC::2019.02.09::HD**
**		This function commences a match of fighting between	 **************************
**		2 character objects. The fight continues until one character is defeated
**************************************************************************************************/
void Battle::commence(Character* fighter1, Character* fighter2)
{
	int firstHit;

	while (fighter1->isAlive() == true && fighter2->isAlive() == true)
	{
		// display round information
		numRounds++;
		drawBorder();
		cout << "\nRound " << numRounds << "\n";

		//flip a coin, 1 for fighter1, 2 for fighter2
		firstHit = coin.roll();

		// fighter 1 attacks first
		if (firstHit == 1)
		{
			cout << "\n========== Fighter 1 Strikes First! ==========\n";
			fight(fighter1,fighter2);
			// if fighter 2 is alive, continue counterattack
			if (fighter2->isAlive() == true)
			{
				cout << "\n========= Fighter 2 Counter Attacks! =========\n";
				fight(fighter2,fighter1);
			}
		}
		// fighter 2 attacks first
		else if (firstHit == 2)
		{
			cout << "\n========== Fighter 2 Strikes First! ==========\n";
			fight(fighter2,fighter1);
			// if fighter 1 is alive, continue counterattack
			if (fighter1->isAlive() == true)
			{
				cout << "\n========== Fighter 1 Counter Attacks! ==========\n";
				fight(fighter1,fighter2);
			}
		}

		cout << "\n\nPress ENTER to Continue...\n\n";
		cin.ignore(256,'\n');
		cout << "\n";
	}

	// Declare the winner
	if (fighter1->isAlive() == false)
	{
		cout << "===FIGHTER 2 HAS WON!!!===\n";
		cout << "FIGHTER 2\n";
		dispFighterInfo(fighter2);
		cout << "\n	HAS DEFEATED:\n\n";
		cout << "FIGHTER 1\n";
		dispFighterInfo(fighter1);
		
	}
	else if (fighter2->isAlive() == false)
	{
		cout << "===FIGHTER 1 HAS WON!!!===\n";
		cout << "FIGHTER 1\n";
		dispFighterInfo(fighter1);
		cout << "\n	HAS DEFEATED:\n\n";
		cout << "FIGHTER 2\n";
		dispFighterInfo(fighter2);
		
	}
	
	//reset number of rounds
	numRounds = 0;
}

/**************************************************************************************************
** Description: void fight(Character*, Character*);	 		 **PUBLIC::2019.02.09::HD**
**		This function commences a fight between an attacker and	 **************************
**		a defender
**************************************************************************************************/
void Battle::fight(Character* attacker, Character* defender)
{
	// display character info at start of fight
	displayFighterTypes(attacker, defender);

	// get the attacker's attack roll
	int attackRoll = attacker->rollAttack();

	// display attacker's roll
	drawBorder();
	cout << "[=Attacker=]\n";
	cout << "|	Rolls [" << attacker->getNumAtt() << "] Attack Dice and Rolls [";
	cout << attackRoll << "]!";

	// get the defender's defense roll
	int defenseRoll = defender->rollDefense();

	// display defender's roll
	drawBorder();
	cout << "[=Defender=]\n";
	cout << "|	Rolls [" << defender->getNumDef() << "] Defense Dice and Rolls [";
	cout << defenseRoll << "]!\n";

	// get the attacker's total attack damage
	int attackDmg = attacker->attack(attackRoll);
	if (attacker->getSpecial() == true)
	{
		cout << "\n		<!> ATTACKER'S SPECIAL IS IN EFFECT <!>";
	}

	// display damage formula
	cout << "\n\n	";
	cout << "[Damage] = [Attacker Damage] - [Defender Roll] - [Defender Armor]\n";

	// get and apply the actual damage
	int actualDmg = defender->defense(attackDmg, defenseRoll);

	// check if special move was done
	if (defender->getSpecial() == true)
	{
		cout << "\n		<!> DEFENDER'S SPECIAL IS IN EFFECT <!>\n";
	}

	// show damage calcluation
	cout << "			";
	cout << "[" << actualDmg << "] = [" << attackDmg << "] - [" << defenseRoll;
	cout << "] - [" << defender->getArmorVal() << "]\n";

	// show defender info at end of fight
	drawBorder();
	cout << "[=Defender=]\n";
	cout << "|	Damage:		" << actualDmg << "\n";
	cout << "|	Strength:	" << defender->getStrengthVal() << "\n";
}

/**************************************************************************************************
** Description: void displayFighterTypes(Character*, Character*)	 **PUBLIC::2019.02.09::HD**
**		This function shows types of the Attacker and Defender	 **************************
**************************************************************************************************/
void Battle::displayFighterTypes(Character* attacker, Character* defender)
{
	// draw border
	drawBorder();

	// display attacker type
	cout << "[=Attacker=]\n"; 
	cout << "|	Type: 		";
	if (attacker->getFighterType() == BARBARIAN)
	{	cout << "Barbarian";
	}
	else if (attacker->getFighterType() == VAMPIRE)
	{	cout << "Vampire";
	}
	else if (attacker->getFighterType() == BLUEMEN)
	{	cout << "Blue Men";
	}
	else if (attacker->getFighterType() == MEDUSA)
	{	cout << "Medusa";
	}
	else if (attacker->getFighterType() == HARRYPOTTER)
	{	cout << "Harry Potter";
	}

	drawBorder();
	// display defender type
	cout << "[=Defender=]\n";
	cout << "|	Type: 		";
	if (defender->getFighterType() == BARBARIAN)
	{	cout << "Barbarian\n";
	}
	else if (defender->getFighterType() == VAMPIRE)
	{	cout << "Vampire\n";
	}
	else if (defender->getFighterType() == BLUEMEN)
	{	cout << "Blue Men\n";
	}
	else if (defender->getFighterType() == MEDUSA)
	{	cout << "Medusa\n";
	}
	else if (defender->getFighterType() == HARRYPOTTER)
	{	cout << "Harry Potter\n";
	}
	// display defender armor
	cout << "|	Armor:		" << defender->getArmorVal() << "\n";
	// display defender strength points
	cout << "|	Strength:	" << defender->getStrengthVal() ;
}

/**************************************************************************************************
** Description: void dispFighterInfo(Character*)			**PRIVATE::2019.02.09::HD**
**		This function displays the Fighter's strength and type	***************************
**************************************************************************************************/
void Battle::dispFighterInfo(Character* fighter)
{
	// declare winner type
	cout << "	Fighter Type:	";
	if (fighter->getFighterType() == BARBARIAN)
	{
		cout << "Barbarian";
	}
	else if (fighter->getFighterType() == VAMPIRE)
	{
		cout << "Vampire";
	}
	else if (fighter->getFighterType() == BLUEMEN)
	{
		cout << "Blue Men";
	}
	else if (fighter->getFighterType() == MEDUSA)
	{
		cout << "Medusa";
	}
	else if (fighter->getFighterType() == HARRYPOTTER)
	{
		cout << "Harry Potter";
	}
	cout << "\n";

	// declare remaining strength
	cout << "	Strength Left:	" << fighter->getStrengthVal() << "\n";

	// declare dice info
	cout << "	Atk Die:	" << fighter->getNumAtt() << "\n";
	cout << "	Atk Die Sides:	" << fighter->getSidesAtt() << "\n";
	cout << "	Def Die:	" << fighter->getNumDef() << "\n";
	cout << "	Def Die Sides:	" << fighter->getSidesDef() << "\n";

	// declare armor value
	cout << "	Armor:		" << fighter->getArmorVal() << "\n";
}

/**************************************************************************************************
** Description: void drawBorder()					**PRIVATE::2019.02.09::HD**
**		This function draws a border to seperate areas.		***************************
**************************************************************************************************/
void Battle::drawBorder()
{
	cout << "\n";
	cout << "_______________________________________________________________________________";
	cout << "\n";
}
