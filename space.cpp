/******************************************************************************
**  Title:			Space Class Implementation
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the implementation file for the Space class,
**                  which is an abstract class that represents a linked 
**					space that has a room type and 4 pointers for top, 
**					right, left, and bottom.
*******************************************************************************/

#include "space.hpp"
#include <iostream>

/******************************************************************************
** Space::Space() 
**      This is the default constructor which initializes all member 
**		variable to nullptr.              
*******************************************************************************/
Space::Space()
{
	setTop(nullptr);
	setRight(nullptr);
	setLeft(nullptr);
	setBottom(nullptr);
	setSpaceType("");
}

/******************************************************************************
** Space::Space() 
**      This is the destructor.           
*******************************************************************************/
Space::~Space()
{

}

/******************************************************************************
** Space::setTop() 
**      This function sets member variable top to the parameter.         
*******************************************************************************/
void Space::setTop(Space* ptrIn)
{
	this->top = ptrIn;
}

/******************************************************************************
** Space::setRight() 
**      This function sets member variable right to the parameter.         
*******************************************************************************/
void Space::setRight(Space* ptrIn)
{
	this->right = ptrIn;
}

/******************************************************************************
** Space::setLeft() 
**      This function sets member variable left to the parameter.         
*******************************************************************************/
void Space::setLeft(Space* ptrIn)
{
	this->left = ptrIn;
}

/******************************************************************************
** Space::setBottom() 
**      This function sets member variable bottom to the parameter.         
*******************************************************************************/
void Space::setBottom(Space* ptrIn)
{
	this->bottom = ptrIn;
}

/******************************************************************************
** Space::setSpaceType() 
**      This function sets member variable spaceType to the parameter.         
*******************************************************************************/
void Space::setSpaceType(std::string spaceTypeIn)
{
	this->spaceType = spaceTypeIn;
}

/******************************************************************************
** Space::getTop() 
**      This function returns member variable top.       
*******************************************************************************/
Space* Space::getTop()
{
	return this->top;
}

/******************************************************************************
** Space::getRight() 
**      This function returns member variable right.       
*******************************************************************************/
Space* Space::getRight()
{
	return this->right;
}

/******************************************************************************
** Space::getLeft() 
**      This function returns member variable left.       
*******************************************************************************/
Space* Space::getLeft()
{
	return this->left;
}

/******************************************************************************
** Space::getBottom() 
**      This function returns member variable bottom.       
*******************************************************************************/
Space* Space::getBottom()
{
	return this->bottom;
}

/******************************************************************************
** Space::getSpaceType() 
**      This function returns member variable spaceType.       
*******************************************************************************/
std::string Space::getSpaceType()
{
	return this->spaceType;
}

/******************************************************************************
** Space::clearScreen() 
**      This function clears the console screen by printing
**		100 lines.       
*******************************************************************************/
void Space::clearScreen()
{
	// Clear console screen
	for (int i = 0; i < 100; i++)
	{
		std::cout << std::endl;
	}
}