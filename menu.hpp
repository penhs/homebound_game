/******************************************************************************
**  Title:			Menu Class Interface
**	Author:         Samnang Penh
**  Date:           10/07/2018
**  Description:    This is the interface file for the Menu class, 
**					which uses a string vector to store menu choices and  
**					can print a greeting for the user, add menu choices,
**					remove menu choices, print menu, request a choice
**					from user, or return an int representing user choice. 
*******************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>

class Menu
{
    private:
        std::string greeting;
        std::vector <std::string> menu;
        
    public:
        Menu();
        void setGreeting(std::string);
        void addMenuItem(std::string);
        void removeMenuItem(int);
        void printGreeting();
		void printMenu();
        int getUserChoice();      
};
#endif