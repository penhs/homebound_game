/******************************************************************************
**  Title:			Input Validation Implementation
**	Author:         Samnang Penh
**  Date:           10/07/2018
**  Description:    This is the implementation file for user input  
**                  validation functions.
*******************************************************************************/

#include <iostream>
#include <string>

/******************************************************************************
** validateInt(std::string) 
**      This function takes a string argument and checks each character and 
**      returns true if the entire string is a positive or negative integer 
**      or returns false.                  
*******************************************************************************/

bool validateInt(std::string strIn)
{
    // True if string is a positive or negative int
	bool intCheck = true;

	// Length of string
	int strLen = strIn.length();
    
    // If first char is a digit or negative sign, validate other chars
	// If first char is a negative sign, string length must be at least 2
    if ( (isdigit(strIn[0])) || ((strIn[0] == '-') && (strLen > 1)) )
    {
        for (int i = 1; (intCheck == true) && (i < strLen); i++)
        {
            // False if any char after the 1st is not a digit
			if (!isdigit(strIn[i])) 
            {
                intCheck = false;
            }
        }
    }

    else
    {
        intCheck = false;    
    }
    
    return intCheck;
}

/******************************************************************************
** requestInt(std::string) 
**      This function takes a string argument (input instructions for user), 
**      prints the string argument to ask user for an int, checks if input  	
**		is an int, and returns the user entered int.         
*******************************************************************************/

int requestInt(std::string strIn)
{
    // Tracks user string input
	std::string userInput = "";	

	// Tracks whether user string input is an int or not
    bool isValid = false;

	// Holds an int that has been converted from user string input
    int validInt = 0;
    
    while (isValid == false)
    {
        // Get user string input
		std::cout << strIn;
        getline(std::cin, userInput);
        
		// Validate whether input is an integer
        isValid =  validateInt(userInput);
    
        // Convert string to int if every char is a digit
        if (isValid == true)
        {
            validInt = std::stoi(userInput);
        }
    
        else
        {
            std::cout << "\n** Invalid entry! **\n" << std::endl;
        }
    } 
    
    return validInt;
}

/******************************************************************************
** requestInt(std::string, int, int) 
**      This function overload takes a string argument (input instructions 
**      for user) and 2 int arguments (min and max user allowed ints),  
**      prints the string argument to ask user for an int, checks if input  	
**		is an int, checks if the int is between the min and max allowed,  
**      and returns the user entered int.         
*******************************************************************************/

int requestInt(std::string strIn, int min, int max)
{
    // Tracks user string input
	std::string userInput = "";	

	// Tracks whether user string input is an int or not
    bool isValid = false;

	// Holds an int that has been converted from user string input
    int validInt = 0;
    
    while (isValid == false)
    {
        // Get user string input
		std::cout << strIn;
        getline(std::cin, userInput);
        
		// Validate whether input is an integer
        isValid = validateInt(userInput);
    
        // Convert string to int if every char is a digit
        if (isValid == true)
        {
            int converted = std::stoi(userInput);
            
            // Checks if converted int is between min and max
            if( (converted >= min) && (converted <= max) )
            {
                validInt = converted;
            }

            else
            {
                // Change to false to loop again to request valid entry
                isValid = false;
                std::cout << "\n** Invalid number! **\n" << std::endl;
            }
        }
    
        else
        {
            std::cout << "\n** Invalid entry! **\n" << std::endl;
        }
    } 
    
    return validInt;
}