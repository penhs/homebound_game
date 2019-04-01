/******************************************************************************
**  Title:			Game Class Interface
**	Author:         Samnang Penh
**  Date:           12/04/2018
**  Description:    This is the interface file for the Game class,
**                  which is a class that represents the Homebound
**					Game and initializes all pertaining objects.
*******************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "space.hpp"
#include "menu.hpp"
#include "validation.hpp"
#include <vector>
#include <string>

class Game
{
	private:
		int health;
		int money;
		Space* player;
		Space* blackmarket;
		Space* casino;
		Space* government;
		Space* junkyard;
		Space* motel;
		Space* spacedock;
		Menu options;
		std::vector <std::string> backpack;

	public:
		Game();
		~Game();
		void runGame();
		void walk(std::string, Space*);
		void printMap();
};
#endif