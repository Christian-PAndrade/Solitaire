#include "header.hpp"
#include <iostream>

using namespace std;

void print_game(Solitaire& s) {
	s.print_cols();
	cout << "==============================" << endl;
	s.print_pile();
	cout << "==============================" << endl;
	s.print_foundations();
	cout << "==============================" << endl;
}

void game_intro() {
	cout << "Welcome to Christian's Solitaire game!" << endl;
	cout << "To play:" << endl <<
		"\tEnter at the bottom the column number of the card you would like to move ('COLUMN [#]')" << endl;
	cout << "\tThen enter the card number you want to move ('#) - Card (color)')" << endl;
	cout << "\tFinally enter the number of the receiving column ('COLUMN [#]')" << endl;
	cout << "\tYou can also get more cards at the pile by hitting 8 then 4" << endl << endl;
	cout << "Hit Any Letter then enter to Start!" << endl;
	string discard;
	cin >> discard;
}

int main()
{
	try {
		Solitaire s;

		game_intro();

		print_game(s);

		// Prompt user for input
		int condition = 0;
		while (condition != 99) {
			condition = s.user_input();
			if (condition == 42)
			{
				cout << endl << "///Congratulations! You win!" << endl;
					return 1;
			}
			if (condition == 97)
				cout << endl << "///ERROR: Cannot swap stacks///" << endl << endl;
			else if (condition == 96)
				cout << endl << "///ERROR: Pile cannot receive cards///" << endl << endl;
			else if (condition == 95)
				cout << endl << "///ERROR: An empty pile can only receive a King" << endl << endl;				
			else if (condition == 88)
				cout << endl << "///ERROR: Card value was too high, check numbers on the left side to choose your card///" << endl << endl;
			else if (condition > 13 && condition != 99)
				cout << endl << "///ERROR: Column number must be between 1 and 12///" << endl << endl;
			
			if (condition != 99 && condition < 13)
				print_game(s);
			
		}
		// exit game
		if (condition == 99)
			cout << endl << "User decided to end game. Thanks for playing!" << endl;
	}
	catch (exception ex)
	{
		cout << ex.what();
	}
	
}