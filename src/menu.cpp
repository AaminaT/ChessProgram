#include "menu.hpp"

void Menu::display()
{
	cout << "CHESS" << endl;
	cout << "------------------------" << endl;
	cout << "1. Play New Game\n2. Load Game\n3. Quit" << endl;
	cout << "Enter a number (1 - 3) to select option: ";

	int choice = 0;
	cin >> choice;

	while(!(choice <= 3 && choice > 0)){
		cout << "Invalid input, please try again: ";
		cin >> choice;
	}

	switch(choice){
		case 1:
			// g.beginNewGame()
			break;
		case 2:
			// s.loadPreviousGame()
			break;
		default:
			cout << "Quitting Chess" << endl;
			break;
	}
}
