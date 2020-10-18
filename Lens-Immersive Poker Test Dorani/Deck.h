#pragma once
#include <iostream>		//cout
#include "Card.h"		//deck of cards
#include <vector>		//vector of cards
#include <algorithm>	//needed for random_shuffle	
#include <random>		//random generator
#include <chrono>		//std::chrono::system_clock


using namespace std;

class Deck
{
public:
	//the number of cards in the deck
	int numCards = 52;

	//Array of possible suits 
	string suits[4]{ "Spades", "Hearts", "Clubs", "Diamonds" };
	//string suits[4]{ "Spades", "Spades", "Spades", "Hearts" };

	//Array of possible values
	string values[13]{ "Ace", "Two", "Three", "Four", "Five", "Six", "Seven",
		"Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	//string values[13]{ "Ace", "Ace", "Ace", "Ace", "Queen", "Queen", "Queen", "Queen", "Queen",
	//	"Ten", "Ten", "Ten", "Ten" };

	//constructor initializes deck with 52 unique cards
	Deck();
	~Deck();

	//prints the deck of cards
	void printDeck();

	//shuffles deck
	void shuffleDeck();
	
protected:
	//vector structure of cards known as the deck
	std::vector<Card> deck;
};

