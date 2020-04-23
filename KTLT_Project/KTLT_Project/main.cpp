#include "19127048.h"
#include "19127493.h"

int main()
{
	int deck[SUITS][RANKS] = { 0 };
	const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* ranks[RANKS] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//shuffleCards(deck);
	//printCardsShuffling(deck, suits, ranks);
	/*printMatrix(deck);
	printPointerMatrix(dealingForHand(deck), 5, 2);*/
	

	/*printMatrix(deck);
	int** hand;
	cout << "Player 1" << endl;
	hand = dealingForHand(deck);
	printHand(hand, suits, ranks);*/


	/*int array[5];
	int** test = createHandTest(array);
	cout << "Highest Card is: " << isStraight(test) << endl;*/


	/*printMatrix(deck);
	int*** test = dealingForHands(deck, 5);
	rankingHands(test, 5);*/

	int *array;
	array = evaluateHands(5, 1);
	for (int i = 0; i < 5; i++)
		cout << *(array + i) << endl;

	system("pause");
	return 0;
}
