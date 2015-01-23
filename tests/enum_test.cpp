//Defining your own types
#include <iostream>

using namespace std;

//Conventional to name enumerations in all caps
//An enumeration defines a type and the possibilities
enum Suit { HEARTS, SPADES, CLUBS, DIAMONDS };

string suit_names[] = {"Hearts", "Spades", "Clubs", "Diamonds"};

enum Rank
{   
	TWO, THREE, FOUR, FIVE, SIT, SEVEN, EIGHT, NINE, TEN,
	JACK, QUEEN, KING, ACE
};

string rank_names[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
		       "Jack", "Queen", "King", "Ace"};

typedef struct
{
	Rank rank;
	Suit suit;
} Card;

void printCard (Card card)
{
	cout << rank_names[card.rank] << " of " << suit_names[card.suit] << endl;
}



int main()
{
	Card card;

	card.suit = SPADES;
	card.rank = QUEEN;

	printCard(card);

	return 0;
}
