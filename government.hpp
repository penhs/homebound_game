/******************************************************************************
**  Title:			Government Class Interface
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the interface file for the Government
**                  class which is derived from the Space class 
**					and represents a government building.
*******************************************************************************/

#ifndef GOVERNMENT_HPP
#define GOVERNMENT_HPP

#include "space.hpp"

class Government : public Space
{
	public:
		Government();
		~Government();
		virtual void randomEvent(int&, int&) override;
		virtual void action(int&, int&, std::vector<std::string>&) override;
		int flightClearanceTest();
};
#endif