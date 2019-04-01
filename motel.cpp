/******************************************************************************
**  Title:			Motel Class Implementation
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the implementation file for the Motel
**                  class which is derived from the Space class 
**					and represents a motel.
*******************************************************************************/

#include "motel.hpp"
#include "menu.hpp"
#include "validation.hpp"
#include <iostream>
#include <cstdlib> 

/******************************************************************************
** Motel::Motel() 
**      This is the default constructor which initializes member 
**		variable spaceType to "Motel".              
*******************************************************************************/
Motel::Motel() : Space()
{
	setSpaceType("motel");
}

/******************************************************************************
** Motel::Motel() 
**      This is the destructor.           
*******************************************************************************/
Motel::~Motel()
{

}

/******************************************************************************
** Motel::randomEvent(int&, int&) 
**      This function takes two int parameters by reference for the 
**		player's health and money and triggers a random event.          
*******************************************************************************/
void Motel::randomEvent(int& hp, int& cash)
{
	// Roll random number between 1-10
	int playerChance = rand() % 10 + 1;	

	// 20% chance of finding medicine to heal
	if ( (playerChance == 1) || (playerChance == 2) )
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
	else if ( playerChance == 3 )
	{
		int cashFound = rand() % 500 + 1; 
		cash += cashFound;
		std::cout << "You found $" << cashFound << " that someone dropped!\n" 
				  << std::endl;
	}
}

/******************************************************************************
** Motel::action(int&, int&, std::vector<std::string>&) 
**      This function takes two int parameters and a string vector
**		parameter by reference for the player's health, money, and
**		backpack and allows the player to initiate a game action.           
*******************************************************************************/
void Motel::action(int& hp, int& cash, std::vector<std::string>& vect)
{
	bool motel_loop = false;			// Loop flag
	int motelChance = rand() % 4 + 1;	// Random number for room availability

	// Initialize menu for motel options
	Menu motel;
	motel.setGreeting("Rest at the motel?");
	motel.addMenuItem("  (1) Yes (+15 health)");
	motel.addMenuItem("  (2) No");
	
	std::cout << "Motel Owner: Hello! Looking to rest here? Unfortunately the\n" 
			  << "             room availability is very limited and random."
			  << std::endl;

	// 25% chance of an available motel room
	if ( motelChance == 1 )
	{
		motel_loop = true;
		std::cout << "             But you're in luck, we have a room!\n" 
			  	  << "             It will cost $1500 to rest here.\n" 
				  << std::endl;
	}
	else
	{
		motel_loop = false;
		std::cout << "             We have no rooms available," 
			  	  << " check again later.\n" 
				  << std::endl;
	}


	while ( motel_loop == true )
	{
		std::cout << "Health: " << hp << std::endl;
		std::cout << "Money: $" << cash << "\n" << std::endl;
		
		switch ( motel.getUserChoice() )
		{
			case 1: // Rest at motel
					clearScreen();		// clear console screen
					motel_loop = false;
					if ( cash >= 1500 )
					{
						hp += 15;
						cash -= 1500;
						std::cout << "You rested and recovered 15 health.\n"
								  << std::endl;
					}
					else
					{
						std::cout << "You don't have enough money!\n" 
								  << std::endl;
					}

					// Set health to 100 (max) if greater than max
					if ( hp > 100 )
					{
						hp = 100;
					}
					break;

			case 2: // Decline resting at hotel
					motel_loop = false;
					clearScreen();		// clear console screen
					std::cout << "You decided not to rest.\n" << std::endl;
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
	std::cout << "You walked out of the motel and immediately the toxic" 
			  << "\nair flooded your lungs and your health declined by 2...\n" 
			  << std::endl;
}