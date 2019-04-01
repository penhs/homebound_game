/******************************************************************************
**  Title:			Casino Class Implementation
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the implementation file for the Casino
**                  class which is derived from the Space class 
**					and represents a casino.
*******************************************************************************/

#include "casino.hpp"
#include "menu.hpp"
#include "validation.hpp"
#include <iostream>
#include <cstdlib> 

/******************************************************************************
** Casino::Casino() 
**      This is the default constructor which initializes member 
**		variable spaceType to "Casino".              
*******************************************************************************/
Casino::Casino() : Space()
{
	setSpaceType("casino");
}

/******************************************************************************
** Casino::Casino() 
**      This is the destructor.           
*******************************************************************************/
Casino::~Casino()
{

}

/******************************************************************************
** Casino::randomEvent(int&, int&) 
**      This function takes two int parameters by reference for the 
**		player's health and money and triggers a random event.       
*******************************************************************************/
void Casino::randomEvent(int& hp, int& cash)
{
	int playerChance = rand() % 10 + 1;	// Roll random number between 1-10

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

	// 20% chance of finding money ($1 - $500)
	else if ( (playerChance == 2) || (playerChance == 3) )
	{
		int cashFound = rand() % 500 + 1; 
		cash += cashFound;
		std::cout << "You found $" << cashFound << " that someone dropped!\n" 
				  << std::endl;
	}
}

/******************************************************************************
** Casino::action(int&, int&, std::vector<std::string>&) 
**      This function takes two int parameters and a string vector
**		parameter by reference for the player's health, money, and
**		backpack and allows the player to initiate a game action.           
*******************************************************************************/
void Casino::action(int& hp, int& cash, std::vector<std::string>& vect)
{
	bool hasTractorBeam = false;	// Checks if player has tractor beam
	bool gambleLoop = true;			// Loop flag
	
	// Initialize menu for gambling options
	Menu gambleMenu;
	gambleMenu.setGreeting("What would you like to do:");
	gambleMenu.addMenuItem("  (1) Decline to gamble");
	gambleMenu.addMenuItem("  (2) Gamble and wager $100");
	gambleMenu.addMenuItem("  (3) Gamble and wager $250");
	gambleMenu.addMenuItem("  (4) Gamble and wager $500");
	gambleMenu.addMenuItem("  (5) Gamble and wager $1000");

	// Check if backpack contains Mini Tractor Beam
	for (int i = 0, j = vect.size(); i < j; i++)
    {
        if ( vect[i] == "Mini Tractor Beam" )
		{
			hasTractorBeam = true;
			std::cout << "You activated the mini tractor beam "
					  << "(first dice will always roll a 6)." 
					  << std::endl;
		}
    }

	std::cout << "You sat down at a dice gambling table.\n" << std::endl;

	std::cout << "Dice Dealer: The rules are simple! We will each roll two\n"
			  << "             6-sided die and you can win the amount you \n" 
			  << "             wagered if your total is higher than mine\n"
			  << "             (a tie results in the dealer winning).\n" 
			  << std::endl;

	// Loop until player decides to quit
	while ( gambleLoop == true )
	{
		std::cout << "Money: $" << cash << "\n" << std::endl;
		
		switch ( gambleMenu.getUserChoice() )
		{
			case 1: // Leave
					gambleLoop = false;
					clearScreen();		// Clear console screen
					std::cout << "You decided not to gamble and left the table." 
							  << std::endl;
					break;

			case 2: // Gamble $100
					clearScreen();		// Clear console screen
					gamble(cash, 100, hasTractorBeam);
					break;

			case 3: // Gamble $250
					clearScreen();		// Clear console screen
					gamble(cash, 250, hasTractorBeam);
					break;

			case 4: // Gamble $500
					clearScreen();		// Clear console screen
					gamble(cash, 500, hasTractorBeam);
					break;

			case 5: // Gamble $1000
					clearScreen();		// Clear console screen
					gamble(cash, 1000, hasTractorBeam);
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
	std::cout << "\nYou walked out the casino and immediately the toxic" 
			  << "\nair flooded your lungs and your health declined by 2...\n" 
			  << std::endl;
}

/******************************************************************************
** Casino::gamble(int&, int, bool) 
**      This function takes an int parameter by reference for player's
**		cash, an int parameter for the wager amount, and a bool 
**		parameter for if the player has a mini tractor beam for 
**		cheating purposes and then initiates die rolls for the player 
**		and dealer to determine a winner.           
*******************************************************************************/
void Casino::gamble(int& playerCash, int wager, bool tractorBeam)
{
	if (playerCash < wager)
	{
		std::cout << "You don't have enough money!\n" << std::endl;
	}

	else
	{
		int playerRoll_1;
		
		// If player has mini tractor beam, force first dice roll to 6
		if (tractorBeam == true)
		{
			playerRoll_1 = 6;
		}

		else
		{
			playerRoll_1 = rand() % 6 + 1;  	// Roll 1st 6-sided die
		}

		int playerRoll_2 = rand() % 6 + 1;  	// Roll 2nd 6-sided die
		int player_total = playerRoll_1 + playerRoll_2;	

		int dealerRoll_1 = rand() % 6 + 1;  	// Roll 1st 6-sided die
		int dealerRoll_2 = rand() % 6 + 1;  	// Roll 2nd 6-sided die
		int dealer_total = dealerRoll_1 + dealerRoll_2;

		std::cout << "You rolled a " << playerRoll_1 << " and " << playerRoll_2
				  << " for a total of " << player_total << ".\n" << std::endl;

		std::cout << "The dealer rolled a " << dealerRoll_1 << " and "
				<< dealerRoll_2 << " for a total of " << dealer_total << "."
				<< std::endl;

		// If player wins outright add money (tie results in dealer win)
		if ( player_total > dealer_total )
		{
			playerCash += wager;
			std::cout << "\nYou won " << wager << "!\n" << std::endl;
		}

		// If player loses subtract money
		else
		{
			playerCash -= wager;
			std::cout << "\nYou lost " << wager << "!\n" << std::endl;
		}
	}
}