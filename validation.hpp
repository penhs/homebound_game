/******************************************************************************
**  Title:			Input Validation Interface
**	Author:         Samnang Penh
**  Date:           10/07/2018
**  Description:    This is the interface file for user input  
**                  validation functions.
*******************************************************************************/

#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <string>

// Function to validate if a string argument is an integer
bool validateInt(std::string);

// Function to request and validate an integer from user
// The string argument are instructions to be printed for user
int requestInt(std::string);

// Function overload to request and validate an integer from user
// Can check if integer is within a range based on int arguments
int requestInt(std::string, int, int);

#endif