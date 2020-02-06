#pragma once
#include <iostream>

// Enum for the suits
enum Suit { SPADES, HEARTS, CLUBS, DIAMONDS };

// Class Card
class Card {
	int number;
	Suit suit;
public:
	Card() = default;
	Card(int i, Suit s) {
		number = i;
		suit = s;
	}

	// getters
	int get_num() { return number; }
	Suit get_suit() {
		if (suit == 0)
			return SPADES;
		else if (suit == 1)
			return HEARTS;
		else if (suit == 2)
			return CLUBS;
		else
			return DIAMONDS;
	}
	// setters
	void set_num(int i) { number = i; }
	void set_suit(Suit s) { suit = s; }

	// print card
	void print_card() {
		if (number == 1)
		{
			if (suit == 0)
				std::cout << "Ace of SPADES (Black)" << std::endl;
			else if (suit == 1)
				std::cout << "Ace of HEARTS (Red)" << std::endl;
			else if (suit == 2)
				std::cout << "Ace of CLUBS (Black)" << std::endl;
			else
				std::cout << "Ace of DIAMONDS (Red)" << std::endl;
		}
		else if (number == 11)
		{
			if (suit == 0)
				std::cout << "Jack of SPADES (Black)" << std::endl;
			else if (suit == 1)
				std::cout << "Jack of HEARTS (Red)" << std::endl;
			else if (suit == 2)
				std::cout << "Jack of CLUBS (Black)" << std::endl;
			else
				std::cout << "Jack of DIAMONDS (Red)" << std::endl;
		}
		else if (number == 12)
		{
			if (suit == 0)
				std::cout << "Queen of SPADES (Black)" << std::endl;
			else if (suit == 1)
				std::cout << "Queen of HEARTS (Red)" << std::endl;
			else if (suit == 2)
				std::cout << "Queen of CLUBS (Black)" << std::endl;
			else
				std::cout << "Queen of DIAMONDS (Red)" << std::endl;
		}
		else if (number == 13)
		{
			if (suit == 0)
				std::cout << "King of SPADES (Black)" << std::endl;
			else if (suit == 1)
				std::cout << "King of HEARTS (Red)" << std::endl;
			else if (suit == 2)
				std::cout << "King of CLUBS (Black)" << std::endl;
			else
				std::cout << "King of DIAMONDS (Red)" << std::endl;
		}
		else
		{
			if (suit == 0)
				std::cout << get_num() << " of SPADES (Black)" << std::endl;
			else if (suit == 1)
				std::cout << get_num() << " of HEARTS (Red)" << std::endl;
			else if (suit == 2)
				std::cout << get_num() << " of CLUBS (Black)" << std::endl;
			else
				std::cout << get_num() << " of DIAMONDS (Red)" << std::endl;
		}

	}
};