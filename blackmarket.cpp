/******************************************************************************
**  Title:			BlackMarket Class Implementation
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the implementation file for the BlackMarket
**                  class which is derived from the Space class 
**					and represents a Black Market.
*******************************************************************************/
#include "blackmarket.hpp"
#include "menu.hpp"
#include "validation.hpp"

#include <iostream>
#include <cstdlib> 

/******************************************************************************
** BlackMarket::BlackMarket() 
**      This is the default constructor which initializes member 
**		variable spaceType to "Black Market".              
*******************************************************************************/
BlackMarket::BlackMarket() : Space()
{
	setSpaceType("black market");
}

/******************************************************************************
** BlackMarket::BlackMarket() 
**      This is the destructor.           
*******************************************************************************/
BlackMarket::~BlackMarket()
{

}

/******************************************************************************
** BlackMarket::randomEvent(int&, int&) 
**      This function takes two int parameters by reference for the 
**		player's health and money and triggers a random event.           
*******************************************************************************/
void BlackMarket::randomEvent(int& hp, int& cash)
{
	int playerChance = rand() % 10 + 1;	// Roll random number between 1-10

	// 10% chance of finding medicine to heal
	if ( playerChance == 1 )
	{
		// Recover significant amount of health
		hp += 10;

		// Set health to 100 (max) if higher than max
		if ( hp > 100 )
		{
			hp = 100;
		}
		
		std::cout << "You found potent medicine someone dropped and ingested" 
				  << " it!\nYou recovered a significant amount of health!\n" 
				  << std::endl;
	}

	// 10% chance of finding money ($1 - $1500)
	else if ( playerChance == 2 )
	{
		int cashFound = rand() % 1500 + 1; 
		cash += cashFound;
		
		std::cout << "You found $" << cashFound << " that someone dropped!\n" 
				  << std::endl;
	}

	// 20% chance of getting pickpocketed (lose $1 - $500)
	else if ( (playerChance == 3) || (playerChance == 4) )
	{
		int lostCash = rand() % 500 + 1; 

		// If player has cash, player is pickpocketed
		if (cash > 0)
		{
			// If amount lost is equal to or exceeds player's cash, set to cash
			if ( lostCash >= cash )
			{
				lostCash = cash;
				cash = 0;
			}

			else
			{
				cash -= lostCash;
			}
			std::cout << "You were pickpocketed and lost $" << lostCash 
					  << "!\n" << std::endl;
		}
	}

	// 10% chance of stepping on dirty syringe (cannot kill player)
	else if ( (playerChance == 5) && (hp > 5) )
	{
		hp -= 5;	// Deduct health
		
		std::cout << "You stepped on a dirty syringe and lost 5 health!\n" 
				  << std::endl;
	}
}

/******************************************************************************
** BlackMarket::action(int&, int&, std::vector<std::string>&) 
**      This function takes two int parameters and a string vector
**		parameter by reference for the player's health, money, and
**		backpack and allows the player to initiate a game action.           
*******************************************************************************/
void BlackMarket::action(int& hp, int& cash, std::vector<std::string>& vect)
{
	bool hasTractorBeam = false;	// Checks if player has tractor beam
	bool smugglerLoop = true;		// Loop flag
	
	// Initialize menu for smuggler options
	Menu smuggler;
	smuggler.setGreeting("What are you looking for?");
	smuggler.addMenuItem("  (1) Walk away from the smuggler");
	smuggler.addMenuItem("  (2) Sell blood (-5 health, +$500)");

	std::cout << "A sketchy looking alien waves for you to come over.\n" 
			  << "You approached his booth.\n" << std::endl;

	std::cout << "Smuggler: Don't ask me any questions and don't tell the \n" 
			  << "          government about me but I can give you money \n"
			  << "          for your blood or sell you a mini tractor beam \n"
			  << "          to help you win at the casino...\n" << std::endl;

	// Check if backpack contains Mini Tractor Beam
	for (int i = 0, j = vect.size(); i < j; i++)
    {
        if ( vect[i] == "Mini Tractor Beam" )
		{
			hasTractorBeam = true;
		}
    }

	// Add tractor beam to smuggler options if player does not have one
	if ( hasTractorBeam == false )
	{
		smuggler.addMenuItem("  (3) Buy mini tractor beam for $5000");
	}

	while ( smugglerLoop == true )
	{
		std::cout << "Health: " << hp << std::endl;
		std::cout << "Money: $" << cash << "\n" << std::endl;

		// Get player's option from smuggler menu
		switch ( smuggler.getUserChoice() )
		{
			case 1: // Leave
					clearScreen();		// Clear console screen
					smugglerLoop = false;
					std::cout << "You decided to walk away from the smuggler." 
							  << std::endl;
					break;

			case 2: // Trade health for money
					clearScreen();		// Clear console screen
					if ( hp > 5 )
					{
						hp -= 5;		// Deduct health
						cash += 500;	// Add money
						std::cout << "You traded some blood for money.\n"
								  << "You don't feel so well...\n" 
							  	  << std::endl;
					}
					else
					{
						std::cout << "Your health is in critical condition!\n"
								  << "You decided not to trade your blood.\n" 
							  	  << std::endl;
					}
					break;

			case 3: // Buy mini tractor beam if player has enough cash
					if ( cash >= 5000 )
					{
						smugglerLoop = false;
						cash -= 5000;	// Deduct money
						vect.push_back("Mini Tractor Beam");  // Add to backpack
						clearScreen();	// Clear console screen
						std::cout << "You bought the mini tractor beam and "
								  << "quickly\nproceeded to leave so no one "
								  << "sees you..." << std::endl;	
					}
					else
					{
						clearScreen();	// Clear console screen
						std::cout << "You don't have enough money to buy "
								  << "the mini tractor beam.\n" << std::endl;
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
	std::cout << "\nYou walked out the black market and immediately the toxic" 
			  << "\nair flooded your lungs and your health declined by 2...\n" 
			  << std::endl;
}

