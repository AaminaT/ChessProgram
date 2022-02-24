#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <string>
#include <iostream>

class Menu
{
public:
	Menu() {} 
	void display();
	~Menu() {}
private:
	Game* g;
	SQL* s;
	std::string menuText;
};
#endif
