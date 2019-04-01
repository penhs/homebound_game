/******************************************************************************
**  Title:			SpaceDock Class Implementation
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the implementation file for the SpaceDock
**                  class which is derived from the Space class 
**					and represents a space dock.
*******************************************************************************/

#include "spacedock.hpp"
#include "menu.hpp"
#include "validation.hpp"
#include <iostream>
#include <cstdlib> 

/******************************************************************************
** SpaceDock::SpaceDock() 
**      This is the default constructor which initializes member 
**		variable spaceType to "Space Dock".              
*******************************************************************************/
SpaceDock::SpaceDock() : Space()
{
	setSpaceType("space dock building");
}

/******************************************************************************
** SpaceDock::SpaceDock() 
**      This is the destructor.           
*******************************************************************************/
SpaceDock::~SpaceDock()
{

}

/******************************************************************************
** SpaceDock::randomEvent(int&, int&) 
**      This function takes two int parameters by reference for the 
**		player's health and money and triggers a random event.           
*******************************************************************************/
void SpaceDock::randomEvent(int& hp, int& cash)
{
	// Roll random number between 1-10
	int playerChance = rand() % 10 + 1;	

	std::cout << "You proceeded into a teleporter which transported you to\n"
			  << "the space dock situated in low orbit around the planet.\n" 
			  << std::endl;

	// 10% chance of finding medicine to heal
	if ( playerChance == 1 )
	{
		// Recover some health
		hp += 5;

		// Set health to 100 (max) if higher than max
		if ( hp > 100 )
		{
			hp = 100;
		}
		std::cout << "You found medicine someone dropped and ingested it!\n"
				  << "You recovered some health!\n" << std::endl;
	}

	// 10% chance of finding money ($1 - $500)
	else if ( playerChance == 2 )
	{
		int cashFound = rand() % 500 + 1; 
		cash += cashFound;
		std::cout << "You found $" << cashFound << " that someone dropped!\n" 
				  << std::endl;
	}
}

/******************************************************************************
** SpaceDock::action(int&, int&, std::vector<std::string>&) 
**      This function takes two int parameters and a string vector
**		parameter by reference for the player's health, money, and
**		backpack and allows the player to initiate a game action.        
*******************************************************************************/
void SpaceDock::action(int& hp, int& cash, std::vector<std::string>& vect)
{
	bool spacedockLoop = true;		// Loop flag
	bool hasClearance = false;		// Tracks if player already has clearance
	bool hasJumpDrive = false;		// Checks if player has tractor beam

	// Initialize menu for space dock options
	Menu spacedockOptions;
	spacedockOptions.setGreeting("What would you like to do?");
	spacedockOptions.addMenuItem("  (1) Go back to the space dock" 
								 " building and leave");
	spacedockOptions.addMenuItem("  (2) Get inside your spaceship, install a"
								 " new jump drive, and go home");

	// Check if backpack contains flight clearance certificate and jump drive
	for (int i = 0, j = vect.size(); i < j; i++)
    {
        if ( vect[i] == "Flight Clearance Certificate" )
		{
			hasClearance = true;
		}

		if ( vect[i] == "Jump Drive Module" )
		{
			hasJumpDrive = true;
		}
    }

	while ( spacedockLoop == true )
	{
		switch ( spacedockOptions.getUserChoice() )
		{
			// Leave the space dock
			case 1: spacedockLoop = false;
					clearScreen();		// Clear console screen
					std::cout << "You went back to the teleporter and arrived "
							  << "back at the space dock building.\n" 
							  << std::endl;
					break;

			// If all win requirements are met, set health to 999 to win game
			case 2:	clearScreen();	// Clear console screen

					if ( (hasClearance == true) && (hasJumpDrive == true) )
					{
						spacedockLoop = false;
						hp = 999;	// Set to 999 to detect player win
						std::cout << "You installed the new jump drive in "
								  << "the spaceship...\n"
								  << std::endl;
					}

					if (hasClearance == false)
					{
						std::cout << "You still need flight clearance!\n"
								  << std::endl;
					}

					if (hasJumpDrive == false)
					{
						std::cout << "You still need a jump drive module!\n"
								  << std::endl;
					}
					break;
		}
	}

	if ( hp != 999 )
	{
		// Lose some health from exiting building
		hp -= 2;

		// Set health to 0 (min) if lower than min
		if ( hp < 0 )
		{
			hp = 0;
		}
		std::cout << "You walked out of the space dock building and " 
				<< "immediately the toxic \nair flooded your lungs and "
				<< "your health declined by 2...\n" << std::endl;
	}
}