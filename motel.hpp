/******************************************************************************
**  Title:			Motel Class Interface
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the interface file for the Motel
**                  class which is derived from the Space class 
**					and represents a motel.
*******************************************************************************/

#ifndef MOTEL_HPP
#define MOTEL_HPP

#include "space.hpp"

class Motel : public Space
{
	public:
		Motel();
		~Motel();
		virtual void randomEvent(int&, int&) override;
		virtual void action(int&, int&, std::vector<std::string>&) override;
};
#endif