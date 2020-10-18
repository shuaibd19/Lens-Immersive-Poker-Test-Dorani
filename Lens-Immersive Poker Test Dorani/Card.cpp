#include "Card.h"

Card::Card(string suit, string value)
{
    cardSuit = suit;
    cardValue = value;
    _cValue = checkValueOfCard();
    _cSuit = checkSuitOfCard();
}

Card::Card()
{
    _cValue = checkValueOfCard();
    _cSuit = checkSuitOfCard();
}


Card::~Card()
{
}

string Card::getCard()
{
    //cout << getSuitValue() << " " << getNumericValue() << endl;
    return cardSuit + " - " + cardValue;
}


void Card::setCard(string suit, string value)
{
    cardSuit = suit;
    cardValue = value;
}

int Card::getNumericValue()
{
    return _cValue;
}

char Card::getSuitValue()
{
    return _cSuit;
}

int Card::checkValueOfCard()
{
    if (cardValue.compare("Ace") == 0)
    {
        return 14;
    }

    if (cardValue.compare("Two") == 0)
    {
        return 2;
    }
    
    if (cardValue.compare("Three") == 0)
    {
        return 3;
    }
    
    if (cardValue.compare("Four") == 0)
    {
        return 4;
    }
    
    if (cardValue.compare("Five") == 0)
    {
        return 5;
    }
    
    if (cardValue.compare("Six") == 0)
    {
        return 6;
    }
    
    if (cardValue.compare("Seven") == 0)
    {
        return 7;
    }
    
    if (cardValue.compare("Eight") == 0)
    {
        return 8;
    }
    
    if (cardValue.compare("Nine") == 0)
    {
        return 9;
    }
    
    if (cardValue.compare("Ten") == 0)
    {
        return 10;
    }

    if (cardValue.compare("Jack") == 0)
    {
        return 11;
    }

    if (cardValue.compare("Queen") == 0)
    {
        return 12;
    }

    if (cardValue.compare("King") == 0)
    {
        return 13;
    }

    else return 0;
}

char Card::checkSuitOfCard()
{
    if (cardSuit.compare("Spades") == 0)
    {
        return 'S';
    }

    if (cardSuit.compare("Hearts") == 0)
    {
        return 'H';
    }

    if (cardSuit.compare("Clubs") == 0)
    {
        return 'C';
    }

    if (cardSuit.compare("Diamonds") == 0)
    {
        return 'D';
    }

    else return '/';
}


