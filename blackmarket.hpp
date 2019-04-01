/******************************************************************************
**  Title:			Blackmarket Class Interface
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the interface file for the BlackMarket
**                  class which is derived from the Space class 
**					and represents a black market.
*******************************************************************************/

#ifndef BLACKMARKET_HPP
#define BLACKMARKET_HPP

#include "space.hpp"

class BlackMarket : public Space
{
	public:
		BlackMarket();
		~BlackMarket();
		virtual void randomEvent(int&, int&) override;
		virtual void action(int&, int&, std::vector<std::string>&) override;
};
#endif