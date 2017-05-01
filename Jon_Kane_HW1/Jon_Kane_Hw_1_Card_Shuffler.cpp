// Jon Kane
// Homework 1
// ME 493
// Card Shuffler

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <random>
#include <time.h>

class Card { // Creates a class called card to occupy 
public:
	int Suit;
	int Value;
	void init();
};

void Card::init() { // Initializes the values needed for the cards of a suit and number value to be zero
	
	Suit = 0;
	Value = 0;
}

int main() {
	srand(time(NULL));
	int NumberofDecks;
	int num;
	// cout << "Please enter an integer value for the number of decks: ";
	// cin >> num;
	// cout << "The number of decks is " << num;
	NumberofDecks = num;

	vector<int> v;
	vector<Card> AllDecks;

	for (int i = 0; i<NumberofDecks * 52; i++) { // This creates a 52 card vector of the overall deck that will be in order before shuffling
		Card c;
		c.init();
		c.Suit = 1 + i % 4; // number of suits is 4, for diamond, club, spade and heart
		c.Value = 1 + i % 13; //numbers 1 through 13 represent the card calue including the ace, jack, queen and king
		AllDecks.push_back(c);
	}

	for (int i = 0; i<10000 * NumberofDecks; i++) {
		int Swap;
		int NumberedDeck;
		int Swapcard;
		int SuitTemp;
		int ValueTemp;
		int DeckTemp;

		Swap = rand() % AllDecks.size();
		Swapcard = rand() % AllDecks.size();
		SuitTemp = AllDecks[Swapcard].Suit;
		ValueTemp = AllDecks[Swapcard].Value;

		AllDecks[Swapcard].Suit = AllDecks[Swap].Suit;
		AllDecks[Swapcard].Value = AllDecks[Swap].Value;

		AllDecks[Swap].Suit = SuitTemp;
		AllDecks[Swap].Value = ValueTemp;
	}

	// Test A: Check the cards and make sure there are no duplicate cards
	for (int i = 0; i<52; i++) {
		for (int j = 0; j<52; j++) {

			if (i != j && NumberofDecks == 1) {
				assert(AllDecks[i].Suit != AllDecks[j].Suit || AllDecks[i].Value != AllDecks[j].Value); // Checks if the combination of suit and value have been used
			}
		}
	}

	// Test B: When working with multiple decks, checks if there are multiple cards that share the same value from different decks
	int MatchesFound;
	MatchesFound = 0;
	for (int i = 0; i<AllDecks.size(); i++) {

		if (AllDecks[i].Suit == AllDecks[0].Suit && AllDecks[i].Value == AllDecks[0].Value) {
			MatchesFound++;
		}
	}
	assert(MatchesFound == NumberofDecks);
}
