#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <string>

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
