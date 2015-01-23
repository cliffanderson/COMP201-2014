// Defining your own types
#include <iostream>
#include <vector>

using namespace std;

// TODO: vector<Card>
// shuffling a deck of cards
// drawing cards
// drawing cards onto the screen

// This is an enumeration
// It defines a type, along with the possibilities
enum Suit { HEARTS, SPADES, CLUBS, DIAMONDS };
// Array of suit names
const string suit_names[] = {
    "Hearts", "Spades", "Clubs", "Diamonds"
};
// Each possibility must be an identifier (legit name)
enum Rank {
    TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING, ACE
};
// Array of rank names
const string rank_names[] = {
    "2", "3", "4", "5", "6", "7", "8", "9", "10",
    "Jack","Queen", "King", "Ace"
};
// Defines a type, called Card
// It consists of a suit and a rank
typedef struct {
    // type variable;
    Suit suit;
    // type variable;
    Rank rank;
} Card;

// Forward declaration
void printCard(Card card);

vector<Card> makeDeck()
{
	//create vector
	vector<Card> deck;
	
	//create cards
	for(int suit = 0; suit < 4; suit++)
	{
		for(int rank = 0; rank < 13; rank++)
		{
			Card c;
			c.suit = Suit(suit);
			c.rank = Rank(rank);
			
			deck.push_back(c);
		}
	}
	
	
	//return vector
	return deck;
	
}

// Type
// variable
// CONSTANT

int main() {
    // type variable_name; // Declare a variable
    int age;
    string name;
    

    vector<Card> deck = makeDeck();

    for(int i = 0; i < deck.size(); i++)
    {
		printCard(deck[i]);
		//cout << endl;
    }
	
    
    
    return 0;
}

// return_type identifier (ParameterType param, ...)
// How about "Ace of Spades"
void printCard(Card card) {
    cout << rank_names[card.rank] << " of "
        << suit_names[card.suit] << endl;
}
