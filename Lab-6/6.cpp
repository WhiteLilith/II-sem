#include "stda.fx"
#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

enum Suit { clubs, diamonds, hearts, spades };

const int JACK = 11;
const int QUEEN = 12;
const int KING = 13;
const int ACE = 14;

class Card
{
private:
	int number;
	Suit suit;

public:
	Card()
	{
		number = 0;
		suit = clubs;
	}

	void Set(int n, Suit s)
	{
		suit = s;
		number = n;
	}

	void Display()
	{
		if (number >= 2 && number <= 10)
		{
			cout << number;
		}
		else 
		{
			switch (number)
			{
			case JACK: cout << "Jack";
				break;
			case QUEEN: cout << "Queen";
				break;
			case KING: cout << "King";
				break;
			case ACE: cout << "Ace";
				break;
			}
		}

		switch (suit)
		{
			case clubs: cout << "♠,"; 
				break;
			case diamonds: cout << "♦,"; 
				break;
			case hearts: cout << "♥,"; 
				break;
			case spades: cout << "♣,"; 
				break;
		}
	}
};


int main()
{
	Card deck[52];

	for (int i = 0; i < 52; i++)
	{
		int n = (i % 13) + 2;
		Suit s = Suit(i / 13);
		deck[i].Set(n, s);
	}

	cout << "Begin deck: " << endl;

	for (int i = 0; i < 52; i++)
	{
		deck[i].Display();
		cout << " ";
		if (!((i + 1) % 13))
		{
			cout << endl;
		}
	}

	srand(time(NULL));
	for (int i = 0; i < 52; i++)
	{
		int k = rand() % 52;
		Card temp = deck[i];
		deck[i] = deck[k];
		deck[k] = temp;
	}

	cout << "Mixed deck: " << endl;
	for (int i = 0; i < 52; i++)
	{
		deck[i].Display();
		cout << " ";
		if (!((i + 1) % 13))
		{
			cout << endl;
		}
	}

	return 0;
}
