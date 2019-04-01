/******************************************************************************
**  Title:			Casino Class Interface
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the interface file for the Casino
**                  class which is derived from the Space class 
**					and represents a casino.
*******************************************************************************/

#ifndef CASINO_HPP
#define CASINO_HPP

#include "space.hpp"

class Casino : public Space
{
	public:
		Casino();
		~Casino();
		virtual void randomEvent(int&, int&) override;
		virtual void action(int&, int&, std::vector<std::string>&) override;
		void gamble(int&, int, bool);
};
#endif