/******************************************************************************
**  Program name:   Homebound Game (Final Project)
**  Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    A text-based game where the player is stranded on a
**					toxic planet and must get money to buy a replacement 
**					jump drive, obtain flight clearance, and leave the 
**					planet to go home.              
*******************************************************************************/
#include "game.hpp"
#include "menu.hpp"
#include "validation.hpp"

#include <iostream>
#include <cstdlib> 
#include <time.h> 

int main() 
{
	// Loop flag
	bool playGame = true;
	
	// Initialize replay menu
	Menu replay;
	replay.setGreeting("Do you want to start a new game?");
	replay.addMenuItem("  (1) Yes");
	replay.addMenuItem("  (2) No");

	// Seed random seed to time
    srand( time(NULL) );

	// Loop until player quits
	while ( playGame == true )
	{
		// Build the game and start it
		Game* gameStart = new Game();
		gameStart->runGame();
		delete gameStart;
		gameStart = nullptr;

		// Ask if player wants to play again
		switch ( replay.getUserChoice() )
		{
			// Play again
			case 1: playGame = true;
					break;
			
			// Quit program
			case 2: playGame = false;
					std::cout << "\n\nThanks for playing, goodbye!\n"
							  << "\n\n** Program Ended **\n\n" << std::endl;
					break;
		}
	}

	return 0;
}