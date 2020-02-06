// Header file, creates a solitaire object
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include "Card.hpp"

class Solitaire {
protected:
	// Columns
	std::vector<Card> col1;
	std::vector<Card> col2;
	std::vector<Card> col3;
	std::vector<Card> col4;
	std::vector<Card> col5;
	std::vector<Card> col6;
	std::vector<Card> col7;
	// foundations
	std::vector<Card> found_spades;
	std::vector<Card> found_hearts;
	std::vector<Card> found_clubs;
	std::vector<Card> found_diamonds;
	// pile
	std::vector<Card> pile;
	// Full deck
	std::vector<Card> deck;
	// pile counter
	int pile_c = 0;
	// conter variable to print specific number of cards - p1 = print1 = last element in container
	int p1 = 0, p2 = 1, p3 = 2, p4 = 3, p5 = 4, p6 = 5, p7 = 6;
public:
	Solitaire() {
		fill_deck();
		shuffle();
		fill_columns();
	}
	//get deck
	std::vector<Card> get_deck() { return deck; }

	// get pile
	int get_pile_count() { return pile_c; }
	// set pile
	void inc_pile_count(int i) { pile_c += i; }
	// reset pile
	void reset_pile_count() { pile_c = 0; }
	// decrement pile to a specific number
	void dec_pile_count(int i) { pile_c -= i; }

	// fills deck
	void fill_deck() {
		for (int i = 1; i <= 13; ++i) {
			// Spades
			deck.push_back(Card(i, SPADES));
			// Hearts
			deck.push_back(Card(i, HEARTS));
			// Clubs
			deck.push_back(Card(i, CLUBS));
			// Diamonds
			deck.push_back(Card(i, DIAMONDS));
		}
	}

	// shuffle
	void shuffle() {
		unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
		//unsigned seed = 1;
		std::shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
	}

	// fill columns with cards
	void fill_columns() {
		// Loop through decksize
		for (int i = 0; i < 8; i++)
		{
			// gradually loops more depending on the col num
			// col1
			if (i < 1)
			{
				// Gets last card of the deck pushes it to the column and deletes it
				Card c = deck[deck.size() - 1];
				col1.push_back(c);
				deck.pop_back();
			}
			// col2
			if (i < 2)
			{
				Card c = deck[deck.size() - 1];
				col2.push_back(c);
				deck.pop_back();
			}
			// col3
			if (i < 3)
			{
				Card c = deck[deck.size() - 1];
				col3.push_back(c);
				deck.pop_back();
			}
			// col 4
			if (i < 4)
			{
				Card c = deck[deck.size() - 1];
				col4.push_back(c);
				deck.pop_back();
			}
			// col 5
			if (i < 5)
			{
				Card c = deck[deck.size() - 1];
				col5.push_back(c);
				deck.pop_back();
			}
			// col 6 
			if (i < 6)
			{
				Card c = deck[deck.size() - 1];
				col6.push_back(c);
				deck.pop_back();
			}
			// col 7 
			if (i < 7)
			{
				Card c = deck[deck.size() - 1];
				col7.push_back(c);
				deck.pop_back();
			}
		}

		while (deck.size() != 0)
		{
			Card c = deck[deck.size() - 1];
			pile.push_back(c);
			deck.pop_back();
		}
	}

	// print columns
	void print_cols() {
		std::cout << std::endl;
		// col1
		print_individual_column(1, p1, col1);
		// col2
		print_individual_column(2, p2, col2);
		// col3
		print_individual_column(3, p3, col3);
		// col4
		print_individual_column(4, p4, col4);
		// col5
		print_individual_column(5, p5, col5);
		// col6
		print_individual_column(6, p6, col6);
		// col7
		print_individual_column(7, p7, col7);
	}

	// Prints an individual column
	void print_individual_column(int colNum, int pointer, std::vector<Card> col)
	{
		std::cout << std::endl << "COLUMN [" << colNum << "]:" << std::endl;
		// If size is 0 print 'add a king here to start pile
		if (col.size() == 0)
			std::cout << "Add a King here to start this pile" << std::endl;
		else
			for (int i = 0; i < col.size(); ++i)
			{
				if (i < pointer)
					std::cout << (i + 1) << ") - Hidden Card" << std::endl;
				else
				{
					std::cout << (i + 1) << ") - ";
					col[i].print_card();
				}
			}
	}

	// print foundations
	void print_foundations() {
		// Spades
		print_individual_foundation("SPADES", 9, found_spades);
		// Hearts
		print_individual_foundation("HEARTS", 10, found_hearts);
		// Clubs
		print_individual_foundation("CLUBS", 11, found_clubs);
		// Diamonds
		print_individual_foundation("DIAMONDS", 12, found_diamonds);
	}

	// Prints an individual foundation
	void print_individual_foundation(std::string fname, int foundNum, std::vector<Card> foundation)
	{
		std::cout << fname << " FOUNDATION [" << foundNum << "]" << std::endl;
		if (foundation.size() == 0)
			std::cout << "Add an Ace of " << fname << " here to start pile" << std::endl;
		else
			for (int i = 0; i < foundation.size(); ++i)
				foundation[i].print_card();
	}

	// print pile
	void print_pile() {
		// var that keeps track of which cards to show
		int count = get_pile_count();

		// if count starts at -1, -2 or -3, cards from the pile were played
		if (count == -3)
		{
			std::cout << "PILE [8]:" << std::endl;
			std::cout << "First 3 cards were played, please selected 8, then 4 for a new set of cards" << std::endl;
		}
		else if (count == -2)
		{
			std::cout << "PILE [8]:" << std::endl;
			std::cout << "1) - ";
			pile[count + 2].print_card();
			++count;
			std::cout << "4) - New cards" << std::endl;
			count = 0;
		}
		else if (count == -1)
		{
			std::cout << "PILE [8]:" << std::endl;
			std::cout << "X  - ";
			pile[count + 1].print_card();
			++count;
			std::cout << "2) - ";
			pile[count + 1].print_card();
			std::cout << "4) - New cards" << std::endl;
			count = 0;
		}
		// if count too big reset
		else if ((pile.size() - count) == 2)
		{
			std::cout << "PILE [8]:" << std::endl;
			std::cout << "X  - ";
			pile[count].print_card();
			++count;
			std::cout << "2) - ";
			pile[count].print_card();
			std::cout << "4) - New cards" << std::endl;
			reset_pile_count();
			dec_pile_count(3);
			//count = -3; 
			// count is just a holder, changing it means nothing
		}
		else if ((pile.size() - count) == 1)
		{
			std::cout << "PILE [8]:" << std::endl;
			std::cout << "1) - ";
			pile[count].print_card();
			std::cout << "4) - New cards" << std::endl;
			reset_pile_count();
			count = 0;
		}
		else if ((pile.size() - count) == 0)
		{
			reset_pile_count();
			count = 0;
			std::cout << "PILE [8]:" << std::endl;
			std::cout << "X  - ";
			pile[count].print_card();
			++count;
			std::cout << "X  - ";
			pile[count].print_card();
			++count;
			std::cout << "3) - ";
			pile[count].print_card();
			std::cout << "4) - New cards" << std::endl;
		}
		else
		{
			std::cout << "PILE [8]:" << std::endl;
			std::cout << "X  - ";
			pile[count].print_card();
			++count;
			std::cout << "X  - ";
			pile[count].print_card();
			++count;
			std::cout << "3) - ";
			pile[count].print_card();
			std::cout << "4) - New cards" << std::endl;
		}
	}

	// user input
	int user_input() {
		int col, card, receiving;
		// Gets Column Number
		std::cout << "Enter a column number: ";
		std::cin >> col;
		// if col is 99 return
		if (col == 99 || col > 13)
			return col;

		// Gets Card number
		std::cout << "Enter a card number: ";
		std::cin >> card;
		// if pile (8), get next 3 cards
		if (col == 8 && card == 4)
		{
			inc_pile_count(3);
			int pCount = get_pile_count();
			return col;
		}

		// Get recieving column
		std::cout << "Enter the receiving column: ";
		std::cin >> receiving;
		if (receiving == 8)
			return 96;

		// column with the card being switched
		std::vector<Card>* user_col = get_col(col, true);
		// column Receiving card
		std::vector<Card>* user_recCol = get_col(receiving, false);

		// if card is equal to size, we are just moving a single card
		if (user_col->size() == card || user_col == &pile)
		{
			// if the card is going to a foundation pile
			if (col == 8 && card < 4)
				// move from pile
				switch_from_pile(user_col, card, user_recCol, col);
			else if (receiving == 9 || receiving == 10 || receiving == 11 || receiving == 12)
			{
				// move to a fundation
				switch_to_foundation(user_col, card, user_recCol, col);
			}
			else
				// copy card from column
				switch_cards(user_col, card, user_recCol, col);
		}
		// if card number is greater than count of column
		else if (user_col->size() < card)
			return 88;
		// if card is lower than the vector size, we are moving a stack
		else
		{
			// If size of receiving column is 0 user must be moving a King into empty pile
			if (user_recCol->size() == 0)
			{
				// Check last card of pile being moved... it has to be a King
				Card a = user_col->at(card - 1);
				if (a.get_num() == 13)
				{
					switch_to_empty_stack(user_col, card, user_recCol, col);
				}
				// Else return error -- must be king to go into empty col
				else
					return 95;
			}
			else
			{
				// check if it is possible to move the stack
				Card a = user_col->at(card - 1);
				Card b = user_recCol->at(user_recCol->size() - 1);
				if (switchable(a, b))
					switch_stacks(user_col, card, user_recCol, col);
				else
					return 97;
			}
		}

		// If the foundations have all 13 cards of that suit, game is over
		if (found_clubs.size() == 13 && found_diamonds.size() == 13 && found_hearts.size() == 13 && found_spades.size() == 13)
		{
			return 42;
		}

		// returns column number
		return col;
	}

	// get column from user input
	std::vector<Card>* get_col(int col, bool decrease) {
		std::vector<Card>* ptr;
		switch (col) {
			// Columns 1-7 can receive cards
		case 1:
			// decrease counter of printable cards
			if (decrease)
				--p1;
			ptr = &col1;
			return ptr;
			break;
		case 2:
			// decrease counter of printable cards
			if (decrease)
				--p2;
			ptr = &col2;
			return ptr;
			break;
		case 3:
			// decrease counter of printable cards
			if (decrease)
				--p3;
			ptr = &col3;
			return ptr;
			break;
		case 4:
			// decrease counter of printable cards
			if (decrease)
				--p4;
			ptr = &col4;
			return ptr;
			break;
		case 5:
			// decrease counter of printable cards
			if (decrease)
				--p5;
			ptr = &col5;
			return ptr;
			break;
		case 6:
			// decrease counter of printable cards
			if (decrease)
				--p6;
			ptr = &col6;
			return ptr;
			break;
		case 7:
			// decrease counter of printable cards
			if (decrease)
				--p7;
			ptr = &col7;
			return ptr;
			break;
			// The Pile where the user can get different cards
		case 8:
			ptr = &pile;
			return ptr;
			break;
			// Foundations
		case 9:
			ptr = &found_spades;
			return ptr;
			break;
		case 10:
			ptr = &found_hearts;
			return ptr;
			break;
		case 11:
			ptr = &found_clubs;
			return ptr;
			break;
		default:
			ptr = &found_diamonds;
			return ptr;
			break;
		}
	}

	// increments p because a card move did not suceed
	void increment_p(int i) {
		switch (i) {
		case 1:
			++p1;
			break;
		case 2:
			++p2;
			break;
		case 3:
			++p3;
			break;
		case 4:
			++p4;
			break;
		case 5:
			++p5;
			break;
		case 6:
			++p6;
			break;
		case 7:
			++p7;
			break;
		default:
			break;
		}
	}

	// switch cards from piles
	void switch_cards(std::vector<Card>* user_col, int card, std::vector<Card>* user_recCol, int col) {
		// Get last card from vector
		Card being_moved = user_col->at(card - 1);
		// Get last card from receiving vector
		Card receiver;
		// User wants to move a King to an empty pile
		if (user_recCol->empty())
		{
			// If it actually is a king, do it
			if (being_moved.get_num() == 13)
			{
				user_col->pop_back();
				user_recCol->push_back(being_moved);
			}
			else
				std::cout << std::endl << "///ERROR: First Card must be a King///" << std::endl << std::endl;

		}
		// Moving any other card to a pile
		else {
			Card receiver = user_recCol->at(user_recCol->size() - 1);
			// make sure the switch is possible
			// first check "color availability"
			int color_moving = find_color(being_moved);
			int color_receiving = find_color(receiver);

			// if colors are the same, throw error
			if (color_moving == color_receiving)
			{
				std::cout << std::endl << "///ERROR: Cards selected have the same color///" << std::endl << std::endl;
				increment_p(col);
			}
			// If different colors
			else
			{
				// check numbers then swith
				if (switchable(being_moved, receiver))
				{
					user_col->pop_back();
					user_recCol->push_back(being_moved);
				}
				else
				{
					std::cout << std::endl << "///ERROR: Cards selected must have adjacent numbers///" << std::endl << std::endl;
					increment_p(col);
				}

			}
		}

	}

	// sends a card to the foundation
	void switch_to_foundation(std::vector<Card>* user_col, int card, std::vector<Card>* user_recCol, int col) {
		// Get last card from vector
		Card being_moved = user_col->at(card - 1);
		// ensure pile is not empty
		Card receiver;

		// suit of card
		Suit s_moved = being_moved.get_suit();

		// Scenario 1 - foundation is empty
		if (user_recCol->empty())
		{
			// Card must be an ace
			if (being_moved.get_num() == 1)
			{
				// Removes from original column
				user_col->pop_back();

				// Card must match suit
				if (s_moved == SPADES)
					found_spades.push_back(being_moved);
				else if (s_moved == HEARTS)
					found_hearts.push_back(being_moved);
				else if (s_moved == CLUBS)
					found_clubs.push_back(being_moved);
				else
					found_diamonds.push_back(being_moved);
			}
			else
				std::cout << std::endl << "///ERROR: Foundation Piles must start with an ACE card///" << std::endl << std::endl;
		}
		// scenario 2 -- foundation is not empty
		else
		{
			receiver = user_recCol->at(user_recCol->size() - 1);

			// If adjacent numbers do the switch
			if (r_switchable(being_moved, receiver))
			{
				// removes card from original column
				user_col->pop_back();
				// Card must match suit
				if (s_moved == SPADES)
					found_spades.push_back(being_moved);
				else if (s_moved == HEARTS)
					found_hearts.push_back(being_moved);
				else if (s_moved == CLUBS)
					found_clubs.push_back(being_moved);
				else
					found_diamonds.push_back(being_moved);
			}
			else
				std::cout << std::endl << "///ERROR: Card being switched was not 1 less than card at foundation" << std::endl << std::endl;
		}
	}

	// Remove card from pile and add to column
	void switch_from_pile(std::vector<Card>* user_col_ptr, int card, std::vector<Card>* user_recCol_ptr, int col) {
		// get value from pile count
		int pCount = get_pile_count();
		// adjust pCount to match indexing
		if (pCount == -1 || pCount == -2)
			pCount = 0;
		// add card selector
		pCount += card;
		// decrement 1 to match indexes
		--pCount;

		// Get selected card
		Card being_moved = user_col_ptr->at(pCount);
		// remove card
		user_col_ptr->erase(user_col_ptr->begin() + pCount);

		// Create holder card
		Card receiver;
		// If the receiving column is empty
		if (user_recCol_ptr->empty())
		{
			// And the card is a king
			if (being_moved.get_num() == 13)
			{
				// pop back from original vector
				user_col_ptr->pop_back();
				// push back to receiving vector
				user_recCol_ptr->push_back(being_moved);
				// moves pile count back 3 to display new card
				move_pilec_back();
			}
			// the card is an Ace going to foundation
			else if (being_moved.get_num() == 1 && (user_recCol_ptr == &found_spades || user_recCol_ptr == &found_hearts || user_recCol_ptr == &found_clubs || user_recCol_ptr == &found_diamonds))
			{
				user_col_ptr->pop_back();
				user_recCol_ptr->push_back(being_moved);
				// moves pile count back 3 to display new card
				move_pilec_back();
			}
			else
				std::cout << std::endl << "///ERROR: First Card must be a King///" << std::endl << std::endl;

		}
		else {
			receiver = user_recCol_ptr->at(user_recCol_ptr->size() - 1);
			// make sure the switch is possible
			// first check "color availability"
			int color_moving = find_color(being_moved);
			int color_receiving = find_color(receiver);

			// if colors are the same, throw error
			if (color_moving == color_receiving)
			{
				std::cout << std::endl << "///ERROR: Cards selected have the same color///" << std::endl << std::endl;
				increment_p(col);
			}
			else
			{
				if (switchable(being_moved, receiver))
				{
					user_recCol_ptr->push_back(being_moved);
					// moves pile count back 3 to display new card
					move_pilec_back();
				}
				else
				{
					std::cout << std::endl << "///ERROR: Cards selected must have adjacent numbers///" << std::endl << std::endl;
					increment_p(col);
				}

			}
		}


	}

	// switch stack
	void switch_stacks(std::vector<Card>* user_col_ptr, int card, std::vector<Card>* user_recCol_ptr, int col) {
		// push all cards to a temp vector
		std::vector<Card> stack_move;
		int col_size = user_col_ptr->size();
		for (int i = col_size; i >= card; --i)
		{
			// make a card and push to vector
			Card c = user_col_ptr->at(user_col_ptr->size() - 1);
			stack_move.push_back(c);
			// pop card from original vector
			user_col_ptr->pop_back();
		}

		// check last card of temp vector with first card of receiving pile
		if (user_recCol_ptr->at(user_recCol_ptr->size() - 1).get_num() - stack_move[stack_move.size() - 1].get_num() == 1)
		{
			// unload cards into new vector
			while (!stack_move.empty())
			{
				user_recCol_ptr->push_back(stack_move[stack_move.size() - 1]);
				stack_move.pop_back();
			}
		}
		else {
			std::cout << std::endl << "///ERROR: First card of pile being switched and last card of pile recieving don't allow switch///" << std::endl << std::endl;
		}
	}

	// switch a stack into an empty pile
	void switch_to_empty_stack(std::vector<Card>* user_col_ptr, int card, std::vector<Card>* user_recCol_ptr, int col) {
		// push all cards to a temp vector
		std::vector<Card> stack_move;
		int col_size = user_col_ptr->size();
		for (int i = col_size; i >= card; --i)
		{
			// make a card and push to vector
			Card c = user_col_ptr->at(user_col_ptr->size() - 1);
			stack_move.push_back(c);
			// pop card from original vector
			user_col_ptr->pop_back();
		}

		// unload cards into new vector
		while (!stack_move.empty())
		{
			user_recCol_ptr->push_back(stack_move[stack_move.size() - 1]);
			stack_move.pop_back();
		}
	}

	// find out color of card
	// return = 0 -> Red Card
	// return = 1 -> Black Card
	int find_color(Card c) {
		if (c.get_suit() == SPADES || c.get_suit() == CLUBS)
			return 1;
		else
			return 0;
	}

	// Determines whether a card can be piled on top of another in a column
	bool switchable(Card lhs, Card rhs)
	{
		int lhsNumber = lhs.get_num();
		int rhsNumber = rhs.get_num();

		if (rhsNumber - lhsNumber == 1)
			return true;
		else
			return false;
	}

	// determines if a card can be pile on top of another in a foundation
	bool r_switchable(Card lhs, Card rhs)
	{
		int lhsNumber = lhs.get_num();
		int rhsNumber = rhs.get_num();

		if (lhsNumber - rhsNumber == 1)
			return true;
		else
			return false;
	}

	// move pile_c back to display new cards after a card from the pile was played
	void move_pilec_back() {
		--pile_c;
	}

};