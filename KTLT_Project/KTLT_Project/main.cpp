#include "19127048.h"
#include "19127493.h"

void main()
{
	int deck[SUITS][RANKS] = { 0 };
	const char* suits[SUITS] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* ranks[RANKS] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	shuffleCards(deck);
	//printCardsShuffling(deck, suits, ranks);


	//int** hand;
	//cout << "Player 1" << endl;
	//hand = dealingForHand(deck);
	//printHand(hand, suits, ranks);


	int array[5];
	int** test = createHandTest(array);
<<<<<<< HEAD
	//cout << isFourOfAKind(test) << endl;
	//cout << isStraightFlush(test) << endl;
	//cout << isTwoPairs(test) << endl;
	//cout << isPair(test) << endl;
=======
	

>>>>>>> 371fbba53f78e3b06cf9ef0d10a886c8db62a585
	system("pause");
}
