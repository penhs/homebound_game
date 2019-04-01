/******************************************************************************
**  Title:			Junkyard Class Implementation
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the implementation file for the Junkyard
**                  class which is derived from the Space class 
**					and represents a junkyard.
*******************************************************************************/

#include "junkyard.hpp"
#include "menu.hpp"
#include "validation.hpp"
#include <iostream>
#include <cstdlib> 

/******************************************************************************
** Junkyard::Junkyard() 
**      This is the default constructor which initializes member 
**		variable spaceType to "Junkyard".              
*******************************************************************************/
Junkyard::Junkyard() : Space()
{
	setSpaceType("junkyard area");
}

/******************************************************************************
** Junkyard::Junkyard() 
**      This is the destructor.           
*******************************************************************************/
Junkyard::~Junkyard()
{

}

/******************************************************************************
** Junkyard::randomEvent(int&, int&) 
**      This function takes two int parameters by reference for the 
**		player's health and money and triggers a random event.           
*******************************************************************************/
void Junkyard::randomEvent(int& hp, int& cash)
{
	int playerChance = rand() % 10 + 1;	// Roll random number between 1-10

	// 10% chance of stubbing toe (cannot kill player)
	if ( (playerChance == 1) && (hp > 2) )
	{
		hp -= 2;	// Deduct health
		
		std::cout << "You accidently stubbed your toe on a piece of building"
				  << " rubble and lost 2 health!\n" << std::endl;
	}

	// 10% chance of finding money ($1 - $1000)
	else if ( playerChance == 2 )
	{
		int cashFound = rand() % 1000 + 1; 
		cash += cashFound;
		std::cout << "You found $" << cashFound << " that someone dropped!\n" 
				  << std::endl;
	}
}

/******************************************************************************
** Junkyard::action(int&, int&, std::vector<std::string>&) 
**      This function takes two int parameters and a string vector
**		parameter by reference for the player's health, money, and
**		backpack and allows the player to initiate a game action.       
*******************************************************************************/
void Junkyard::action(int& hp, int& cash, std::vector<std::string>& vect)
{
	bool hasJumpDrive = false;		// Checks if player has tractor beam
	bool junkyardLoop = true;		// Loop flag
	
	// Initialize menu for junkyard options
	Menu junkyardMenu;
	junkyardMenu.setGreeting("What would you like to do:");
	junkyardMenu.addMenuItem("  (1) Leave the junkyard");
	junkyardMenu.addMenuItem("  (2) Scavenge (requires at least 10 health)");
	
	// Check if backpack contains Jump Drive Module
	for (int i = 0, j = vect.size(); i < j; i++)
    {
        if ( vect[i] == "Jump Drive Module" )
		{
			hasJumpDrive = true;
		}
    }

	// Allow player to purchase jump drive module if player doesn't have one
	if ( hasJumpDrive == false )
	{
		junkyardMenu.addMenuItem("  (3) Buy jump drive module for $9000");
	}


	std::cout << "You spotted a small crumbling building next to the junkyard" 
			  << " and walked in.\n" << std::endl;

	std::cout << "Scavenger: Hey there! The junkyard is where the government\n"
			  << "           dumps junk they pull from orbit. You're free to\n"
			  << "           take whatever you find but I'll pay you $50 for\n"
			  << "           each piece of copper you find! Be careful in the\n" 
			  << "           junkyard, you can easily get hurt.\n" << std::endl;


	// Loop until player decides to quit
	while ( junkyardLoop == true )
	{
		std::cout << "Health: " << hp << std::endl;
		std::cout << "Money: $" << cash << "\n" << std::endl;
		
		switch ( junkyardMenu.getUserChoice() )
		{
			case 1: // Leave
					junkyardLoop = false;
					clearScreen();		// Clear console screen
					std::cout << "You decided to leave." << std::endl;
					break;

			case 2: // Scavenge junkyard
					clearScreen();		// Clear console screen
					if ( hp >= 10 )
					{
						scavenge(hp, cash);	// Initiate scavenging
					}
					else
					{
						std::cout << "Due to the dangers of scavenging, "
								  << "you need at least 10 health.\n"
								  << std::endl;
					}
					break;

			case 3: // Buy jump drive if player has enough cash
					if ( cash >= 9000 )
					{
						junkyardLoop = false;
						cash -= 9000;	// Deduct money
						vect.push_back("Jump Drive Module");  // Add to backpack
						clearScreen();	// Clear console screen
						std::cout << "You bought the jump drive for an" 
								  << " unbelievable price!\nYou quickly" 
								  << " leave in case the scavenger" 
								  << " changes his mind." << std::endl;	
					}
					else
					{
						clearScreen();	// Clear console screen
						std::cout << "You don't have enough money to buy "
								  << "the jump drive module.\n" << std::endl;
					}
					break;
		}
	}

	// Lose some health from exiting building
	hp -= 2;

	// Set health to 0 (min) if lower than min
	if ( hp < 0 )
	{
		hp = 0;
	}
	std::cout << "\nYou walked out of the building and immediately the toxic" 
			  << "\nair flooded your lungs and your health declined by 2...\n" 
			  << std::endl;
}

/******************************************************************************
** Junkyard::scavenge(int&, int&) 
**      This function takes two int parameters by reference for 
**		player's health and cash then initiates a random event
**		for the player.          
*******************************************************************************/
void Junkyard::scavenge(int& playerHealth, int& playerCash)
{
	int scavengeChance = rand() % 5 + 1;	// Roll random number between 1-5;
	
	// Lose some health from exiting building
	playerHealth -= 2;

	std::cout << "You proceeded into the open-air junkyard to start scavenging" 
			  << " and immediately\nthe toxic air flooded your lungs and your" 
			  << " health declined by 2...\n" 
			  << std::endl;

	// 20% chance of finding copper (1 - 60 pieces)
	if ( scavengeChance == 1 )
	{
		int foundCopper = rand() % 60 + 1;
		int copperCash = foundCopper * 50;
		playerCash += copperCash;

		std::cout << "You found " << foundCopper << " pieces of copper!\n\n"
				  << "You became overwhelmed by the toxic air and ran back to"
				  << " the crumbling building.\n" 
				  << "You exchanged the copper with the scavenger and received" 
				  << " $" << copperCash << "!\n" << std::endl;
	}

	// 20% chance of finding money ($1 - $3000)
	else if ( scavengeChance == 2 )
	{
		int cashFound = rand() % 3000 + 1; 
		playerCash += cashFound;
		std::cout << "You found $" << cashFound << " that someone dropped!\n\n" 
				  << "You became overwhelmed by the toxic air and ran back to"
				  << " the crumbling building.\n" << std::endl;
	}

	// 20% chance of getting cut by rusty metal (cannot kill player)
	else if ( scavengeChance == 3 )
	{
		playerHealth -= 6;	// Deduct health
		
		std::cout << "You accidently cut yourself on some rusty metal and"
				  << " and lost 6 health!\n\n"
				  << "You became overwhelmed by the toxic air and ran back to"
				  << " the crumbling building.\n" << std::endl;
	}

	// 20% chance of metal particle cloud (cannot kill player)
	else if ( scavengeChance == 4 )
	{
		playerHealth -= 3;	// Deduct health
		
		std::cout << "A cloud of metal particles suddenly appeared!\n"
				  << "You accidently breathed it in and lost 3 health!\n\n"
				  << "You became overwhelmed by the toxic air and ran back to"
				  << " the crumbling building.\n" << std::endl;
	}

	// 20% chance of finding nothing
	else if ( scavengeChance == 5 )
	{		
		std::cout << "Unfortunately you didn't find anything valuable.\n\n"
				  << "You became overwhelmed by the toxic air and ran back to"
				  << " the crumbling building.\n" << std::endl;
	}
}