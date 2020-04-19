#include "19127048.h"
#include "19127493.h"
// test
void main()
{
	int deck[SUITS][RANKS] = { 0 };
	const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* ranks[RANKS] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };


	shuffleCards(deck);
	//printMatrix(deck);


	printCardsShuffling(deck, suits, ranks);
	system("pause");
}