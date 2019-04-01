/******************************************************************************
**  Title:			Government Class Implementation
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the implementation file for the Government
**                  class which is derived from the Space class 
**					and represents a government building.
*******************************************************************************/

#include "government.hpp"
#include "menu.hpp"
#include "validation.hpp"
#include <iostream>
#include <cstdlib> 

/******************************************************************************
** Government::Government() 
**      This is the default constructor which initializes member 
**		variable spaceType to "Government Building".              
*******************************************************************************/
Government::Government() : Space()
{
	setSpaceType("government building");
}

/******************************************************************************
** Government::Government() 
**      This is the destructor.           
*******************************************************************************/
Government::~Government()
{

}

/******************************************************************************
** Government::randomEvent(int&, int&) 
**      This function takes two int parameters by reference for the 
**		player's health and money and triggers a random event.           
*******************************************************************************/
void Government::randomEvent(int& hp, int& cash)
{
	// Roll random number between 1-10
	int playerChance = rand() % 10 + 1;	

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
** Government::action(int&, int&, std::vector<std::string>&) 
**      This function takes two int parameters and a string vector
**		parameter by reference for the player's health, money, and
**		backpack and allows the player to initiate a game action.           
*******************************************************************************/
void Government::action(int& hp, int& cash, std::vector<std::string>& vect)
{
	bool hasClearance = false;	// Tracks if player already has clearance
	int testScore;				// Tracks score from flight clearance test
	
	// Check if backpack contains flight clearance certificate
	for (int i = 0, j = vect.size(); i < j; i++)
    {
        if ( vect[i] == "Flight Clearance Certificate" )
		{
			hasClearance = true;
		}
    }
	
	// If player already got flight clearance certificate
	if ( hasClearance == true )
	{
		std::cout << "You already have flight clearance. There's nothing left\n"
				  << "to do here so you decided to leave." << std::endl;
	}

	// If player hasn't gotten flight clearance certificate yet
	else
	{
		// Initialize menu for flight clearance test taking
		Menu takeTest;
		takeTest.setGreeting("Would you like to take the test now?");
		takeTest.addMenuItem("  (1) Take test now");
		takeTest.addMenuItem("  (2) Maybe later...");
		
		std::cout << "Secretary: You're looking for flight clearance to leave\n"
				  << "           this planet? You'll need to take a test and\n" 
				  << "           score 100% in order to obtain a flight\n" 
				  << "           clearance certificate.\n" << std::endl;

		// Get player's choice to take test or not
		switch ( takeTest.getUserChoice() )
		{
			
			case 1: // Take test
					testScore = flightClearanceTest();

					// A test score of 3 = 100%
					if (testScore == 3)
					{
						clearScreen();	// Clear console screen
						std::cout << "Congrats, you passed the test and "
								<< "received a flight clearance certificate!" 
								<< std::endl;
						
						// Add Flight Clearance Certificate to backpack
						vect.push_back("Flight Clearance Certificate");

						// Recover some health from happiness
						hp += 5;

						// Set health to 100 (max) if higher than max
						if ( hp > 100 )
						{
							hp = 100;
						}

						std::cout << "You became extremely happy and recovered" 
								  << " some health!" << std::endl;
					}
					else
					{
						clearScreen();	// Clear console screen
						std::cout << "Unfortunately you failed the test and "
								  << "will need to retake it..." << std::endl;
					}
					break;

			
			case 2: // Don't take test
					clearScreen();	// Clear console screen
					std::cout << "You declined to take the test and decided to"
							  << " leave." << std::endl;
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
	std::cout << "\nYou walked out the government building and immediately the" 
			  << "\ntoxic air flooded your lungs and your health declined by 2" 
			  << "...\n" << std::endl;
}

/******************************************************************************
** Government::flightClearanceTest() 
**      This function allows the player to take a test in order to
**		receive flight clearance (player needs to score 100%).       
*******************************************************************************/
int Government::flightClearanceTest()
{
	// Tracks how many answers were correct (3 = 100%)
	int rightAnswers = 0;
	
	// Initialize menu objects for the 3 test questions
	Menu question1;
	Menu question2;
	Menu question3;

	// Set answer choices for first question
	question1.setGreeting("What should you do before you take-off?");
	question1.addMenuItem("  (1) Nothing, just take-off");
	question1.addMenuItem("  (2) Ask flight tower for permission");
	question1.addMenuItem("  (3) Arm weapons");

	// Set answer choices for second question
	question2.setGreeting("Which spaceship has the absolute right-of-way?");
	question2.addMenuItem("  (1) Emergency medical spaceship");
	question2.addMenuItem("  (2) Research spaceship");
	question2.addMenuItem("  (3) Cargo spaceship");

	// Set answer choices for third and final question
	question3.setGreeting("What should you do if you get into an accident?");
	question3.addMenuItem("  (1) Quickly fly away from the scene");
	question3.addMenuItem("  (2) Get into your emergency pod and hide");
	question3.addMenuItem("  (3) Report the incident to authorities");

	clearScreen();	// Clear console screen
	std::cout << "Welcome to the flight clearance test!\n"
			  << "You will need to score 100% to pass it.\n\n" << std::endl;

	std::cout << "Question #1: \n" << std::endl;
	switch ( question1.getUserChoice() )
	{
			case 1: // Wrong answer
					clearScreen();	// Clear console screen
					break;

			case 2: // Correct answer
					clearScreen();	// Clear console screen
					rightAnswers++;
					break;

			case 3: // Wrong answer
					clearScreen();	// Clear console screen
					break;
	}

	std::cout << "Question #2: \n" << std::endl;
	switch ( question2.getUserChoice() )
	{
			case 1: // Correct answer
					clearScreen();	// Clear console screen
					rightAnswers++;
					break;

			case 2: // Wrong answer
					clearScreen();	// Clear console screen
					break;

			case 3: // Wrong answer
					clearScreen();	// Clear console screen
					break;
	}

	std::cout << "Question #3: \n" << std::endl;
	switch ( question3.getUserChoice() )
	{
			case 1: // Wrong answer
					clearScreen();	// Clear console screen
					break;

			case 2: // Wrong answer
					clearScreen();	// Clear console screen
					break;

			case 3: // Correct answer
					clearScreen();	// Clear console screen
					rightAnswers++;
					break;
	}
	
	clearScreen();	// Clear console screen

	return rightAnswers;
}