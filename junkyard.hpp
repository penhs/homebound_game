/******************************************************************************
**  Title:			Junkyard Class Interface
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the interface file for the Junkyard
**                  class which is derived from the Space class 
**					and represents a junkyard.
*******************************************************************************/

#ifndef JUNKYARD_HPP
#define JUNKYARD_HPP

#include "space.hpp"

class Junkyard : public Space
{
	public:
		Junkyard();
		~Junkyard();
		virtual void randomEvent(int&, int&) override;
		virtual void action(int&, int&, std::vector<std::string>&) override;
		void scavenge(int&, int&);
};
#endif