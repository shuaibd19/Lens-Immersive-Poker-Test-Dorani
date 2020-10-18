#include "GameManager.h"

GameManager::GameManager()
{
    //add 4 players to the game
    for (int i = 1; i < 5; i++)
    {
        Player p = Player(i);
        players.push_back(p);
    }
}

GameManager::~GameManager()
{
}

void GameManager::deal()
{
    //iterate through all the players
    //and assign them 5 cards from the front
    //of the deck while also removing the 
    //card at the front from the deck
    for (int i = 0; i < 5; i++)
    {
        /*this loop allows for a card to be given to
        each player before each iteration ends*/
        for (int j = 0; j < 4; j++)
        {
            players[j].givePlayerCard(deck.front());
            deck.erase(deck.begin());
        }
    }
}


void GameManager::showHands()
{
    for (int i = 0; i < 4; i++)
    {
        players[i].sortHandSuit();
        cout << "Player Number: " << players[i].playerNumber << endl;
        players[i].printHand();
    }
}

//***********************************Hand Evaluation Methods*******************************//

bool GameManager::checkRoyalFlush(Player player)
{
    if (checkFlush(player))
    {
        //rearrange the players hand based on value
        player.sortHandValue();
        player.printHand();
        if (player.getPlayerHand().front().getNumericValue() == 14 
            && player.getPlayerHand().at(1).getNumericValue() == 13
            && player.getPlayerHand().at(2).getNumericValue() == 12
            && player.getPlayerHand().at(3).getNumericValue() == 11
            && player.getPlayerHand().back().getNumericValue() == 10)
        {
            return true;
        }
    }
}

bool GameManager::checkStraightFlush(Player player)
{
    if (checkFlush(player))
    {
        //rearrange the players hand based on value
        player.sortHandValue();
        //if the difference from the end and front is 4 then it's a straight flush
        if (player.getPlayerHand().front().getNumericValue() - 
            player.getPlayerHand().back().getNumericValue() == 4)
        {
            return true;
        }
    }
}

bool GameManager::checkFourKind(Player player)
{
    int* counts = counter(player);

    for (int i = 0; i < 13; i++)
    {
        if (counts[i] == 4)
        {
            return true;
        }
    }
}

bool GameManager::checkFullHouse(Player player)
{
    int* counts = counter(player);

    for (int i = 0; i < 13; i++)
    {
        if (counts[i] == 3)
        {
            for (int j = 0; j < 13; j++)
            {
                if (counts[j] == 2)
                {
                    return true;
                }
            }
        }
    }
}

bool GameManager::checkFlush(Player player)
{
    if (player.getPlayerHand().front().getSuitValue() ==
        player.getPlayerHand().back().getSuitValue())
    {
        return true;
    }
}

bool GameManager::checkStraight(Player player)
{
    //rearrange the players hand based on value
    player.sortHandValue();
    //if the difference from the end and front is 4 then it's a straight flush
    if (player.getPlayerHand().front().getNumericValue() -
        player.getPlayerHand().back().getNumericValue() == 4 &&
        player.getPlayerHand().at(1).getNumericValue() -
        player.getPlayerHand().at(3).getNumericValue() == 2 &&
        player.getPlayerHand().front().getNumericValue() -
        player.getPlayerHand().at(2).getNumericValue() == 2)
    {
        return true;
    }
}

bool GameManager::checkThreeKind(Player player)
{
    int* counts = counter(player);

    for (int i = 0; i < 13; i++)
    {
        if (counts[i] == 3)
        {
            return true;
        }
    }
}

bool GameManager::checkTwoPair(Player player)
{
    int* counts = counter(player);

    for (int i = 0; i < 7; i++)
    {
        if (counts[i] == 2 && counts[i] < 3)
        {
            for (int j = 13; j > 7; j--)
            {
                if (counts[j] == 2 && counts[j] < 3)
                {
                    return true;
                }
            }
        }

    }

    return false;
}

bool GameManager::checkPair(Player player)
{
    int* counts = counter(player);

    for (int i = 0; i < 13; i++)
    {
        if (counts[i] == 2)
        {
            return true;
        }
    }

}

void GameManager::checkHighCard(Player player)
{
    player.sortHandValue();
    cout << "Player: " << player.playerNumber << " highest value card is: " << player.getPlayerHand().front().getCard() << "\n\n\n\n" << endl;
}


void GameManager::evaluateHands()
{
    for (int i = 0; i < 4; i++)
    {
        if (checkRoyalFlush(players[i]))
        {
            cout << "Player: " << players[i].playerNumber << " Has a Royal Flush!\n\n" << endl;
            players[i].addPoints(1000);

        }
        else if (checkStraightFlush(players[i]))
        {
            cout << "Player: " << players[i].playerNumber << " Has a Straight Flush!\n\n" << endl;
            players[i].addPoints(500);
        }
        else if (checkFlush(players[i]))
        {
            cout << "Player: " << players[i].playerNumber << " Has a Flush!\n\n" << endl;
            players[i].addPoints(100);
        }
        else if (checkFourKind(players[i]))
        {
            cout << "Player: " << players[i].playerNumber << " Has a Four of a Kind!\n\n" << endl;
            players[i].addPoints(250);
        }
        else if (checkFullHouse(players[i]))
        {
            cout << "Player: " << players[i].playerNumber << " Has a Full House!\n\n" << endl;
            players[i].addPoints(125);
        }
        else if (checkStraight(players[i]))
        {
            cout << "Player: " << players[i].playerNumber << " Has a Straight!\n\n" << endl;
            players[i].addPoints(75);
        }
        else if (checkThreeKind(players[i]))
        {
            cout << "Player: " << players[i].playerNumber << " Has a Three of a Kind!\n\n" << endl;
            players[i].addPoints(50);
        }
        else if (checkTwoPair(players[i]))
        {
            cout << "Player: " << players[i].playerNumber << " Has Two Pairs!\n\n" << endl;
            players[i].addPoints(30);
        }
        else if (checkPair(players[i]))
        {
            cout << "Player: " << players[i].playerNumber << " Has a Pair!\n\n" << endl;
            players[i].addPoints(20);
        }
        else 
        {
            checkHighCard(players[i]);
            players[i].addPoints(players[i].getPlayerHand().front().getNumericValue());
        }
        
    }
}

void GameManager::evaluateSingleHand(int i)
{
    if (checkRoyalFlush(players[i]))
    {
        cout << "Player: " << players[i].playerNumber << " Has a Royal Flush!\n\n\n\n" << endl;
        players[i].addPoints(1000);

    }
    else if (checkStraightFlush(players[i]))
    {
        cout << "Player: " << players[i].playerNumber << " Has a Straight Flush!\n\n\n\n" << endl;
        players[i].addPoints(500);
    }
    else if (checkFlush(players[i]))
    {
        cout << "Player: " << players[i].playerNumber << " Has a Flush!\n\n\n\n" << endl;
        players[i].addPoints(100);
    }
    else if (checkFourKind(players[i]))
    {
        cout << "Player: " << players[i].playerNumber << " Has a Four of a Kind!\n\n\n\n" << endl;
        players[i].addPoints(250);
    }
    else if (checkFullHouse(players[i]))
    {
        cout << "Player: " << players[i].playerNumber << " Has a Full House!\n\n\n\n" << endl;
        players[i].addPoints(125);
    }
    else if (checkStraight(players[i]))
    {
        cout << "Player: " << players[i].playerNumber << " Has a Straight!\n\n\n\n" << endl;
        players[i].addPoints(75);
    }
    else if (checkThreeKind(players[i]))
    {
        cout << "Player: " << players[i].playerNumber << " Has a Three of a Kind\n\n\n\n" << endl;
        players[i].addPoints(50);
    }
    else if (checkTwoPair(players[i]))
    {
        cout << "Player: " << players[i].playerNumber << " Has Two Pairs!\n\n\n\n" << endl;
        players[i].addPoints(30);
    }
    else if (checkPair(players[i]))
    {
        cout << "Player: " << players[i].playerNumber << " Has a Pair!\n\n\n\n" << endl;
        players[i].addPoints(20);
    }
    else
    {
        checkHighCard(players[i]);
    }
}


int* GameManager::counter(Player player)
{
    int counts[13] = { 0 };
    for (int i = 0; i < 5; i++)
    {
        switch (player.getPlayerHand()[i].getNumericValue())
        {
        case 14:
            counts[0] += 1;
            break;
        case 2:
            counts[1] += 1;
            break;
        case 3:
            counts[2] += 1;
            break;
        case 4:
            counts[3] += 1;
            break;
        case 5:
            counts[4] += 1;
            break;
        case 6:
            counts[5] += 1;
            break;
        case 7:
            counts[6] += 1;
            break;
        case 8:
            counts[7] += 1;
            break;
        case 9:
            counts[8] += 1;
            break;
        case 10:
            counts[9] += 1;
            break;
        case 11:
            counts[10] += 1;
            break;
        case 12:
            counts[11] += 1;
            break;
        case 13:
            counts[12] += 1;
            break;
        default:
            break;
        }
    }

    return counts;
}

void GameManager::winner()
{
    Player tempPlayer;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (this->players[j + 1].getPlayerScore() > this->players[j].getPlayerScore())
            {
                tempPlayer = this->players[j];
                this->players[j] = this->players[j + 1];
                this->players[j + 1] = tempPlayer;
            }
        }
    }

    if (players.front().getPlayerScore() == players.at(1).getPlayerScore())
    {
        cout << "Round ends in a draw... " << endl << endl;
    }
    else
    {
        cout << "The winner is Player: " << players.front().playerNumber << endl << endl;
    }
}


