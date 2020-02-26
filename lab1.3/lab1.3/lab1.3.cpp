#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <cstdlib> 
using namespace std;

const int DECK_SIZE = 10;

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(vector<size_t>& deck)
{
	for (int i = 0; i <= DECK_SIZE; i++)
	{
		swap(deck[i], deck[getRandomNumber(0, DECK_SIZE)]);
	}
}

int main()
{	
	vector<size_t> deck;
	for (int i = 0; i <= DECK_SIZE; i++)
	{
		deck.push_back(i);	
	}
	
	int buttonCode = 0;
	while (1)
	{

		copy(deck.begin(), deck.end() - 1, std::ostream_iterator<size_t>(cout, " "));
		cout << "\npress 'R' for shuffle" << endl;
		cout << endl;

		buttonCode = _getch();
		
		if (buttonCode == 114)
		{
			shuffleDeck(deck);
		}
		else
		{
			break;
		}
	}
	return 0;
	
}


