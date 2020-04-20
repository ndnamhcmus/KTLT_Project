#include "19127048.h"
#include "19127493.h"

void main()
{
	int deck[SUITS][RANKS] = { 0 };
	const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* ranks[RANKS] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	shuffleCards(deck);
	//printMatrix(deck);
	

	//printCardsShuffling(deck, suits, ranks);


	//int** hand;
	//cout << "Player 1" << endl;
	//hand = dealingForHand(deck);
	//printHand(hand, suits, ranks);


	int array[5];
	int** test = createHandTest(array);
	cout << isFourOfAKind(test);

	system("pause");
}
