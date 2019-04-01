/******************************************************************************
**  Title:			Menu Class Implementation
**	Author:         Samnang Penh
**  Date:           10/07/2018
**  Description:    This is the implementation file for the Menu class, 
**					which uses a string vector to store menu choices and  
**					can print a greeting for the user, add menu choices,
**					remove menu choices, print menu, request a choice
**					from user, or return an int representing user choice. 
*******************************************************************************/

#include "menu.hpp"
#include "validation.hpp"
#include <iostream>
#include <string>
#include <vector>

/******************************************************************************
** Menu::Menu() 
**      This is the default constructor which initializes member 
**		variable greeting.              
*******************************************************************************/

Menu::Menu()
{
	greeting = "";
}

/******************************************************************************
** Menu::setGreeting() 
**      This function takes a string argument and sets the value of 
**		member variable greeting to it.             
*******************************************************************************/

void Menu::setGreeting(std::string strIn)
{
    greeting = strIn;    
}

/******************************************************************************
** Menu::addMenuItem() 
**      This function takes a string argument and appends it to the
**		member variable vector menu.   
*******************************************************************************/

void Menu::addMenuItem(std::string itemIn)
{
    menu.push_back(itemIn);
}

/******************************************************************************
** Menu::removeMenuItem() 
**      This function takes an int argument and uses it to erase the nth 
**		element from member variable vector menu.
*******************************************************************************/

void Menu::removeMenuItem(int nth)
{
	// Erases the nth element of the vector
	menu.erase( menu.begin() + nth );
}

/******************************************************************************
** Menu::printGreeting() 
**      This function prints the member variable greeting.           
*******************************************************************************/

void Menu::printGreeting()
{
    std::cout << greeting << std::endl;
}

/******************************************************************************
** Menu::printMenu() 
**      This function prints all elements from member variable vector menu.
*******************************************************************************/

void Menu::printMenu()
{
    for (int i = 0, j = menu.size(); i < j; i++)
    {
        std::cout << menu[i] << std::endl;
    }
    
    std::cout << std::endl;
}

/******************************************************************************
** Menu::getUserChoice() 
**      This function calls the printGreeting and printMenu functions to
**		display a greeting and the menu choices for the user, requests
**		the user to enter an integer, calls the validateInt() function
**		to check if user input is an integer, checks if the user input
**		is a valid menu choice, and then returns true if user input is
**		a valid integer, or false if input is invalid.
*******************************************************************************/

int Menu::getUserChoice()
{
    // Initialize local variables to track user input
	std::string userInput = "";
    int userChoice = 0;
    bool isValid = false;
    
	// Loop until user inputs valid entry
    do
    {
		// Display greeting and menu for user
		printGreeting();
        printMenu();

		// Get user input
		std::cout << "Selection: ";
		getline(std::cin, userInput);
    
		// Validate user input if integer or not
        isValid =  validateInt(userInput);
        
        // Convert user input from string to integer if true
        if (isValid == true)
        {
            // Pass the size of the menu to an int variable
			int menuSize = menu.size();

			userChoice = std::stoi(userInput);
            
            // Check if user input is within bounds
            if ( (userChoice < 1) || (userChoice > menuSize) )
            {
                isValid = false;
                std::cout << "** Invalid entry! **" << std::endl << std::endl;
            }
        }
        
        else
        {
            std::cout << "** Invalid entry! **" << std::endl << std::endl;
        }

    } while (isValid == false);

    return userChoice;    
}