#pragma once
#include <iostream>		//cout
#include "Card.h"		//cards needed for hand
#include <vector>		//std::vector
#include <algorithm>	//sort

using namespace std;

class Player
{
public:
	int playerNumber;


	//player constructor sets the player number default is 1
	Player(int num = 1);
	~Player();

	//set the player number
	void setPlayerNumber( int num);

	//function returns the players hand in the form of a vector
	std::vector<Card> getPlayerHand();
	//insert a card into the players hand
	void givePlayerCard(Card card);
	//print all cards in player's hand
	void printHand();

	/// <summary>
	///	sorts the players hand based on suit 
	/// using bubble sort
	/// </summary>
	void sortHandSuit();

	/// <summary>
	/// sorts the players hand based on value
	/// using bubble sort
	/// </summary>
	void sortHandValue();

	/// <summary>
	/// add points to the players score
	/// </summary>
	/// <param name="points"></param>
	void addPoints(int points);


	/// <summary>
	/// displays the players score
	/// </summary>
	void displayPlayerScore();

	int getPlayerScore();

	//Card card1 = Card("Spades", "Nine");
	//Card card2 = Card("Spades", "Eight");
	//Card card3 = Card("Spades", "Seven");
	//Card card4 = Card("Spades", "Six");
	//Card card5 = Card("Spades", "Four");

private:
	int playerScore = 0;
	//the player's hand
	std::vector<Card> hand;
};

