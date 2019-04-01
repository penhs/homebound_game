/******************************************************************************
**  Title:			SpaceDock Class Interface
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the interface file for the SpaceDock
**                  class which is derived from the Space class 
**					and represents a space dock.
*******************************************************************************/

#ifndef SPACEDOCK_HPP
#define SPACEDOCK_HPP

#include "space.hpp"

class SpaceDock : public Space
{
	public:
		SpaceDock();
		~SpaceDock();
		virtual void randomEvent(int&, int&) override;
		virtual void action(int&, int&, std::vector<std::string>&) override;
};
#endif