#include "menu.hpp"

void Menu::display()
{
	std::cout << "CHESS" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "1. Play New Game\n2. Load Game\n3. Quit" << std::endl;
	std::cout << "Enter a number (1 - 3) to select option: ";

	int choice = 0;
	std::cin >> choice;

	while(!(choice <= 3 && choice > 0)){
		std::cout << "Invalid input, please try again: ";
		std::cin >> choice;
	}

	switch(choice){
		case 1:
			// g.beginNewGame()
			break;
		case 2:
			// s.loadPreviousGame()
			break;
		default:
			std::cout << "Quitting Chess" << std::endl;
			break;
	}
}
