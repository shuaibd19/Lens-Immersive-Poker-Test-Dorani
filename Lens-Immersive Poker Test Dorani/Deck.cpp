#include "Deck.h"

Deck::Deck()
{
	//iterate through the 4 suits and 13 variations of cards
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			//assign the card with the values and push to the end of the deck
			Card card = Card(suits[i], values[j]);
			deck.push_back(card);
		}
	}
}

Deck::~Deck()
{
}

void Deck::printDeck()
{
	for (Card c : deck)
	{
		cout << c.getCard() << endl;
	}

	cout << endl;
}

void Deck::shuffleDeck()
{
	//generate a time based seed
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(deck.begin(), deck.end(), std::default_random_engine(seed));
}

