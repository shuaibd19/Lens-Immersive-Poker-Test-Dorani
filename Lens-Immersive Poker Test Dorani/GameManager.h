#pragma once
#include <iostream>
#include "Card.h"			//cards needed for hand
#include "Deck.h"			//deck of cards
#include "Player.h"			//players
#include <vector>			//std::vector
#include <algorithm>		//sort
using namespace std;


class GameManager:public Deck, public Player
{
public:

	static const int NUM_THREADS = 4;

	GameManager();
	~GameManager();

	/// <summary>
	/// deals 5 cards to 4 patrons
	/// </summary>
	void deal();

	/// <summary>
	/// first sort hands by suit then
	/// show all the hands from the players
	/// </summary>
	void showHands();

	/// <summary>
	/// checks for a royal flush by first checking for flush 
	/// then checking numerical value of first and last cards
	/// </summary>
	/// <param name="player"></param>
	/// <returns>true or false</returns>
	bool checkRoyalFlush(Player player);

	/// <summary>
	/// checks for straight flush
	/// </summary>
	/// <param name="player"></param>
	/// <returns>true or false</returns>
	bool checkStraightFlush(Player player);
	
	/// <summary>
	/// checks for 4 of a kind combinations
	/// </summary>
	/// <param name="player"></param>
	/// <returns>true or false</returns>
	bool checkFourKind(Player player);

	/// <summary>
	/// checks for a full house
	/// </summary>
	/// <param name="player"></param>
	/// <returns>true or false</returns>
	bool checkFullHouse(Player player);

	/// <summary>
	/// checks for a flush by comparing first and last card suit
	/// </summary>
	/// <param name="player"></param>
	/// <returns>true or false</returns>
	bool checkFlush(Player player);

	/// <summary>
	/// checks for a straight hand
	/// </summary>
	/// <param name="player"></param>
	/// <returns>true or false</returns>
	bool checkStraight(Player player);

	/// <summary>
	/// checks for a full house
	/// </summary>
	/// <param name="player"></param>
	/// <returns>true or false</returns>
	bool checkThreeKind(Player player);

	/// <summary>
	/// checks for 2 pairs in the players hand
	/// </summary>
	/// <param name="player"></param>
	/// <returns>true or false</returns>
	bool checkTwoPair(Player player);

	/// <summary>
	/// checks for a single pair in the players hand
	/// </summary>
	/// <param name="player"></param>
	/// <returns>true or false</returns>
	bool checkPair(Player player);

	/// <summary>
	/// checks for the highest card in the hand
	/// </summary>
	/// <param name="player"></param>
	void checkHighCard(Player player);

	/// <summary>
	/// this is the main method that evaluates the players hand
	/// using the build logic
	/// </summary>
	void evaluateHands();

	/// <summary>
	/// this method only evaluates a single player's hand
	/// this will be useful when allocating threads specific taska
	/// </summary>
	/// <param name="int"></param>
	void evaluateSingleHand(int i);

	/// <summary>
	/// basic counter function used to find instances of
	/// cards in the hand
	/// </summary>
	/// <param name="player"></param>
	/// <returns>array of int's</returns>
	int* counter(Player player);

	void winner();

private:
	/// <summary>
	/// vector structure of all players
	/// </summary>
	std::vector<Player> players;
};

