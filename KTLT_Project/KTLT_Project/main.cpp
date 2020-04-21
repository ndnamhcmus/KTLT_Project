#include "19127048.h"
#include "19127493.h"

int main()
{
	int deck[SUITS][RANKS] = { 0 };
	const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* ranks[RANKS] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	shuffleCards(deck);
	//printCardsShuffling(deck, suits, ranks);
	/*printMatrix(deck);
	printPointerMatrix(dealingForHand(deck), 5, 2);*/
	

	//int** hand;
	//cout << "Player 1" << endl;
	//hand = dealingForHand(deck);
	//printHand(hand, suits, ranks);


	/*int array[5];
	int** test = createHandTest(array);
	cout << "Highest Card is: " << isStraight(test) << endl;*/


	printMatrix(deck);
	int*** test = dealingForHands(deck, 3);
	DellocateTriplePointer(test, 3, 5);
	system("pause");
	return 0;
}
