#include <iostream>			//cout
#include "GameManager.h"	//hand evaluation functions 
#include <thread>			//std::thread


using namespace std;

void runPoker(int i);
GameManager gameInstance;
const int NUMTHREADS = 4;

int main() {

	//creating 4 worker threads
	std::thread* _threads;
	_threads = new std::thread[NUMTHREADS];

	for (int i = 0; i < 1000; i++)
	{
		gameInstance.shuffleDeck();
	}

	cout << "Player hands sorted by suit: \n\n" << endl;

	gameInstance.deal();

	gameInstance.showHands();

	//allocating each thread a specific player to evaluate
	for (int i = 0; i < NUMTHREADS; i++)
	{
		_threads[i] = std::thread(runPoker, i);
		std::this_thread::sleep_for(1ms);
	}

	//once finished deallocate threads and make them join
	for (int i = 0; i < NUMTHREADS; i++)
	{
		_threads[i].join();
	}

	gameInstance.winner();

	return 0;
}

void runPoker(int i)
{
	gameInstance.evaluateSingleHand(i);
}
