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
const int RESHUFFLE_BUTTON_CODE = 114;

int GetRandomNumber()
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX));
	return static_cast<int>(rand() * fraction * DECK_SIZE);
}

void ShuffleDeck(vector<size_t>& deck)
{
	for (int i = 0; i <= DECK_SIZE; i++)
	{
		swap(deck[i], deck[GetRandomNumber()]);
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
		cout << "\npress 'R' for shuffle or any for quit" << endl;
		cout << endl;

		buttonCode = _getch();
		
		if (buttonCode == RESHUFFLE_BUTTON_CODE)
		{
			ShuffleDeck(deck);
		}
		else
		{
			break;
		}
	}

	return 0;
}


