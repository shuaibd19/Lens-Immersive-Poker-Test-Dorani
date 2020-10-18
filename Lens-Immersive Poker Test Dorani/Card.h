#pragma once
#include <iostream>		//cout
#include <string>		//compare

using namespace std;

class Card
{
public:
	Card(string suit, string value);
	Card();
	~Card();
	//return the card
	string getCard();
	//set the value of the card
	void setCard(string suit, string value);

	/// <summary>
	/// returns value of card
	/// </summary>
	/// <returns>int</returns>
	int getNumericValue();

	/// <summary>
	/// returns suit of card
	/// </summary>
	/// <returns></returns>
	char getSuitValue();
private:
	//The card should have a value and type
	string cardSuit;
	string cardValue;

	//numeric value
	int _cValue;
	//char suit
	char _cSuit;

	/// <summary>
	/// checks value of card
	/// </summary>
	/// <returns>int</returns>
	int checkValueOfCard();

	/// <summary>
	/// checks suit of the card
	/// </summary>
	/// <returns>char</returns>
	char checkSuitOfCard();
};

