/******************************************************************************
**  Title:			Game Class Implementation
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the implementation file for the Game class,
**                  which is a class that represents the Homebound
**					Game and initializes all pertaining objects.
*******************************************************************************/
#include "game.hpp"
#include "blackmarket.hpp"
#include "casino.hpp"
#include "government.hpp"
#include "junkyard.hpp"
#include "motel.hpp"
#include "spacedock.hpp"

#include <iostream>


/******************************************************************************
** Game::Game() 
**      This is the default constructor which initializes all member 
**		variables to the default game values, builds the main menu,
**		initializes the space objects, and links the space objects      
**
**		Map:
**			[Black Market]  [Casino]  [Government]
**			[Junkyard]      [Motel]   [Space Dock]   
**
*******************************************************************************/
Game::Game()
{	
	// Set health and money to starting values
	health = 100;
	money = 1000;
	
	// Build player's main options menu
	options.setGreeting("\nSelect an option below:");
	options.addMenuItem("  (1) Enter building");
	options.addMenuItem("  (2) Walk north");
	options.addMenuItem("  (3) Walk east");
	options.addMenuItem("  (4) Walk west");
	options.addMenuItem("  (5) Walk south");
	options.addMenuItem("  (6) View backpack");
	options.addMenuItem("  (7) View map");
	options.addMenuItem("  (8) Quit game");

	// Initialize spaces
	blackmarket = new BlackMarket();
	casino = new Casino();
	government = new Government();
	junkyard = new Junkyard();
	motel = new Motel();
	spacedock = new SpaceDock();

	// Set black market space pointers
	blackmarket->setTop(nullptr);
	blackmarket->setRight(casino);
	blackmarket->setLeft(nullptr);
	blackmarket->setBottom(junkyard);

	// Set casino space pointers
	casino->setTop(nullptr);
	casino->setRight(government);
	casino->setLeft(blackmarket);
	casino->setBottom(motel);

	// Set government building space pointers
	government->setTop(nullptr);
	government->setRight(nullptr);
	government->setLeft(casino);
	government->setBottom(spacedock);

	// Set junkyard space pointers
	junkyard->setTop(blackmarket);
	junkyard->setRight(motel);
	junkyard->setLeft(nullptr);
	junkyard->setBottom(nullptr);

	// Set motel space pointers
	motel->setTop(casino);
	motel->setRight(spacedock);
	motel->setLeft(junkyard);
	motel->setBottom(nullptr);

	// Set space dock space pointers
	spacedock->setTop(government);
	spacedock->setRight(nullptr);
	spacedock->setLeft(motel);
	spacedock->setBottom(nullptr);
}

/******************************************************************************
** Game::~Game() 
**      This is the destructor which deletes the spaces.        
*******************************************************************************/
Game::~Game()
{
	delete blackmarket;
	blackmarket = nullptr;

	delete casino;
	casino = nullptr;

	delete government;
	government = nullptr;

	delete junkyard;
	junkyard = nullptr;

	delete motel;
	motel = nullptr;

	delete spacedock;
	spacedock = nullptr;
}

/******************************************************************************
** Game::runGame() 
**      This function begins the game.      
*******************************************************************************/
void Game::runGame()
{
	bool continueGame = true;		// Loop flag for entire game

	// Initialize quit confirmation menu
	Menu quitConfirm;
	quitConfirm.setGreeting("Are you sure you want to quit this game?");
	quitConfirm.addMenuItem("  (1) Yes");
	quitConfirm.addMenuItem("  (2) No");

	// Set player's initial space
	player = spacedock;			

	// Clear console screen and print intro
	player->clearScreen();
	std::cout << "Welcome to the Homebound game!\n\n"
			  << "You are a space adventurer visiting an alien planet but "
			  << "your spaceship's jump\ndrive has malfunctioned and you are "
			  << "now stranded, surrounded by toxic air.\nTime is running out!" 
			  << " You must quickly acquire money, get a new jump drive, \n"
			  << "get flight clearance, and go home before the planet becomes "
			  << "your grave…\n" 
			  << std::endl;

	std::cout << "After exiting the spaceship, you are currently outside the"
			  << " space dock building.\n" << std::endl;

	// Loop player options until quit, game over, or win
	while (continueGame == true)
	{
		std::cout << "Health: " << health << std::endl;
		std::cout << "Money: $" << money << std::endl;
		
		switch ( options.getUserChoice() )
		{
			// Enter building
			case 1:	player->clearScreen();	// Clear console screen
					std::cout << "You went inside the " 
							  << player->getSpaceType() << "...\n" 
							  << std::endl;

					// Trigger random event inside building
					player->randomEvent(health, money);

					// Call functions for player interaction
					player->action(health, money, backpack);
					break;
			
			// Walk north
			case 2: player->clearScreen();	// Clear console screen
					walk( "north", player->getTop() );
					break;

			// Walk east
			case 3:	player->clearScreen();	// Clear console screen
					walk( "east", player->getRight() );
					break;

			// Walk west
			case 4:	player->clearScreen();	// Clear console screen
					walk( "west", player->getLeft() );
					break;

			// Walk south
			case 5: player->clearScreen();	// Clear console screen
					walk( "south", player->getBottom() );
					break;

			// View backpack contents
			case 6: player->clearScreen();	// Clear console screen
					if ( backpack.empty() )
					{
						std::cout << "\n\nYour backpack is empty.\n"
								  << std::endl;
					}
					else
					{
						std::cout << "\n\nYour backpack contains:\n";
						for (int i = 0, j = backpack.size(); i < j; i++)
    					{
        					std::cout << "  " << backpack[i] << std::endl;
    					}
						std::cout << std::endl;
					}
					break;

			// Prints map showing player's location
			case 7: player->clearScreen();	// Clear console screen
					printMap();
					break;

			// Confirm if player really wants to quit
			case 8: player->clearScreen();	// Clear console screen
					switch ( quitConfirm.getUserChoice() )
					{
						case 1:	continueGame = false;
								std::cout << "\n******************"
										  << "\n**              **"
										  << "\n**  GAME ENDED  **"
										  << "\n**              **"
										  << "\n******************"
										  << "\n\n" << std::endl;
								break;

						case 2: player->clearScreen();	// Clear console screen
								std::cout << "\n\nContinuing game...\n\n" 
										  << std::endl;
								break;
					}
					break;
		}

		// Check for player death
		if ( health <= 0 )
		{
			
			std::cout << "\nYour health dropped to 0 and you died!\n"
					  << "\n******************"
					  << "\n**              **"
					  << "\n**  GAME OVER!  **"
					  << "\n**              **"
					  << "\n******************"
					  << "\n\n" << std::endl;

			continueGame = false;
		}

		// Check if player has won
		if ( health == 999 )
		{
			std::cout << "You pinged the flight tower and received permission " 
					  << "to take-off.\n" 
					  << "You set travel coordinates for Earth, your home.\n" 
					  << "The jump drive activated and you took off.\n\n"
					  << "After all this adventuring, you're finally homebound!"
					  << std::endl;

			std::cout << "\n******************"
					  << "\n**              **"
					  << "\n**   YOU WON!   **"
					  << "\n**              **"
					  << "\n******************"
					  << "\n\n" << std::endl;

			continueGame = false;
		}		
	}
}

/******************************************************************************
** Game::walk(std::string, Space*) 
**      This function traverses the player pointer to the space
**		parameter and then calls the space's randomEvent() and
**		action() functions.   
*******************************************************************************/
void Game::walk(std::string direction, Space* nextSpace)
{
	// If player's choice is valid, move player to that space
	if ( nextSpace != nullptr )	
	{
		health -= 2;			// Decrement health for the walk
		player = nextSpace;		// Set player space to user selection

		std::cout << "You inhaled more toxic air from your walk and your" 
				  << " health declined by 2..." << std::endl;

		if ( health > 0 )
		{
			std::cout << "\nYou've arrived at the " << player->getSpaceType() 
				  	  << ".\n" << std::endl;
		}
	}
	
	// If player's choice is invalid (nullptr), don't move player
	else
	{
		std::cout << "\nThere is nothing to the " << direction
			  	  << " but a vast wasteland.\n" 
				  << "You decided not to walk there.\n" 
			  	  << std::endl;
	}
}

/******************************************************************************
** Game::printMap() 
**		This function prints the map to show the player's current
**		location.
*******************************************************************************/
void Game::printMap()
{
	// Print location at black market
	if ( player->getSpaceType() == "black market" )
	{
		std::cout << " --------------------------------------------------  \n"
				  << "|  Black Market  |     Casino     |   Government   | \n"
				  << "|       **       |                |                | \n"
				  << "| (You Are Here) |                |                | \n"
				  << "|--------------------------------------------------| \n"
				  << "|    Junkyard    |     Motel      |   Space Dock   | \n"
				  << "|                |                |                | \n"
				  << "|                |                |                | \n"
				  << " --------------------------------------------------  \n"
				  << std::endl;
	}	

	// Print location at casino
	else if ( player->getSpaceType() == "casino" )
	{
		std::cout << " --------------------------------------------------  \n"
				  << "|  Black Market  |     Casino     |   Government   | \n"
				  << "|                |       **       |                | \n"
				  << "|                | (You Are Here) |                | \n"
				  << "|--------------------------------------------------| \n"
				  << "|    Junkyard    |     Motel      |   Space Dock   | \n"
				  << "|                |                |                | \n"
				  << "|                |                |                | \n"
				  << " --------------------------------------------------  \n"
				  << std::endl;
	}

	// Print location at government building
	else if ( player->getSpaceType() == "government building" )
	{
		std::cout << " --------------------------------------------------  \n"
				  << "|  Black Market  |     Casino     |   Government   | \n"
				  << "|                |                |       **       | \n"
				  << "|                |                | (You Are Here) | \n"
				  << "|--------------------------------------------------| \n"
				  << "|    Junkyard    |     Motel      |   Space Dock   | \n"
				  << "|                |                |                | \n"
				  << "|                |                |                | \n"
				  << " --------------------------------------------------  \n"
				  << std::endl;
	}

	// Print location at junkyard area
	else if ( player->getSpaceType() == "junkyard area" )
	{
		std::cout << " --------------------------------------------------  \n"
				  << "|  Black Market  |     Casino     |   Government   | \n"
				  << "|                |                |                | \n"
				  << "|                |                |                | \n"
				  << "|--------------------------------------------------| \n"
				  << "|    Junkyard    |     Motel      |   Space Dock   | \n"
				  << "|       **       |                |                | \n"
				  << "| (You Are Here) |                |                | \n"
				  << " --------------------------------------------------  \n"
				  << std::endl;
	}

	// Print location at motel
	else if ( player->getSpaceType() == "motel" )
	{
		std::cout << " --------------------------------------------------  \n"
				  << "|  Black Market  |     Casino     |   Government   | \n"
				  << "|                |                |                | \n"
				  << "|                |                |                | \n"
				  << "|--------------------------------------------------| \n"
				  << "|    Junkyard    |     Motel      |   Space Dock   | \n"
				  << "|                |       **       |                | \n"
				  << "|                | (You Are Here) |                | \n"
				  << " --------------------------------------------------  \n"
				  << std::endl;
	}

	// Print location at space dock
	else if ( player->getSpaceType() == "space dock building" )
	{
		std::cout << " --------------------------------------------------  \n"
				  << "|  Black Market  |     Casino     |   Government   | \n"
				  << "|                |                |                | \n"
				  << "|                |                |                | \n"
				  << "|--------------------------------------------------| \n"
				  << "|    Junkyard    |     Motel      |   Space Dock   | \n"
				  << "|                |                |       **       | \n"
				  << "|                |                | (You Are Here) | \n"
				  << " --------------------------------------------------  \n"
				  << std::endl;
	}
}