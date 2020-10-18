#include "Player.h"

Player::Player(int num)
{
    //initialise player with number
    playerNumber = num;
    //hand.push_back(card3);
    //hand.push_back(card2);
    //hand.push_back(card1);
    //hand.push_back(card5);
    //hand.push_back(card4);
}

Player::~Player()
{
}

void Player::setPlayerNumber(int num)
{
    playerNumber = num;
}

std::vector<Card> Player::getPlayerHand()
{
    return hand;
}

void Player::givePlayerCard(Card card)
{
    hand.push_back(card);
}

void Player::printHand()
{ 
    for (Card c : hand)
    {
        std::cout << c.getCard() << std::endl;
    }
    std::cout << "\n" << endl;
}

void Player::sortHandSuit()
{
    Card tempCard = Card("empty", "empty");
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (this->hand[j + 1].getSuitValue() > this->hand[j].getSuitValue())
            {
                tempCard = this->hand[j];
                this->hand[j] = this->hand[j + 1];
                this->hand[j + 1] = tempCard;
            }
        }
    }
}

void Player::sortHandValue()
{
    Card tempCard = Card("empty", "empty");
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (this->hand[j + 1].getNumericValue() > this->hand[j].getNumericValue())
            {
                tempCard = this->hand[j];
                this->hand[j] = this->hand[j + 1];
                this->hand[j + 1] = tempCard;
            }
        }
    }
}

void Player::addPoints(int points)
{
    this->playerScore += points;
}

void Player::displayPlayerScore()
{
    cout << "PLayer: " << playerNumber << " has " << playerScore << " points" << endl << endl;
}

int Player::getPlayerScore()
{
    return this->playerScore;
}

