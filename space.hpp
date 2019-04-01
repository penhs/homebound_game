/******************************************************************************
**  Title:			Space Class Interface
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the interface file for the Space class,
**                  which is an abstract class that represents a linked 
**					space that has a room type and 4 pointers for top, 
**					right, left, and bottom.
*******************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <vector>
#include <string>

class Space
{
	protected:
		Space* top;
		Space* right;
		Space* left;
		Space* bottom;
		std::string spaceType;

	public:
		Space();
		virtual ~Space();

		// Setter functions
		void setTop(Space*);
		void setRight(Space*);
		void setLeft(Space*);
		void setBottom(Space*);
		void setSpaceType(std::string);

		// Getter functions
		Space* getTop();
		Space* getRight();
		Space* getLeft();
		Space* getBottom();
		std::string getSpaceType();
		
		// Pure virtual functions
		virtual void randomEvent(int&, int&) = 0;
		virtual void action(int&, int&, std::vector<std::string>&) = 0;

		// Inherited function
		void clearScreen();
};
#endif